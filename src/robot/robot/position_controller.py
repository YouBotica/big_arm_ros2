#! /usr/bin/env python

import os
import sys
import rclpy
import pdb

from rclpy.duration import Duration
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import QoSProfile
from control_msgs.action import FollowJointTrajectory
from trajectory_msgs.msg import JointTrajectoryPoint
from std_msgs.msg import Float64MultiArray
from ament_index_python.packages import get_package_share_directory
from control_msgs.msg import JointTrajectoryControllerState
from big_arm_interfaces.srv import JointsNow

import numpy as np


pkg_name = 'robot'
file_location = get_package_share_directory(pkg_name)

sys.path.insert(0, os.path.join(file_location, 'scripts')) # Add scripts to path since the Inverse Kinematics function is stored there.

from inverse_kinematics import compute_IK

# ros2 action list -t
# ros2 action info /joint_trajectory_controller/follow_joint_trajectory -t
# ros2 interface show control_msgs/action/FollowJointTrajectory

class ControlActionClient(Node):

    def __init__(self):
        super().__init__('control_actionclient')
        self._action_client = ActionClient(self, FollowJointTrajectory, '/joint_trajectory_controller/follow_joint_trajectory')
        self.actual_angles = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]


        self.cli = self.create_client(JointsNow, 'joints_now') # Client service to get joint states whenever we need.
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        
        self.req = JointsNow.Request()

        qos_profile = QoSProfile(depth=10)
        self.publisher_ = self.create_publisher(Float64MultiArray, 'angle_publisher', 10)
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

        self.got_initial_poses = False 

        # When GUI Node calls this action server, it is going to execute the movement with the following parameters as inputs:
        self.declare_parameter('Px', None)
        self.declare_parameter('Py', None)
        self.declare_parameter('Pz', None)
        self.declare_parameter('use_forward_kin', None)
        self.declare_parameter('desired_angles', None)

        self.Px = self.get_parameter('Px').get_parameter_value().double_value
        self.Py = self.get_parameter('Py').get_parameter_value().double_value
        self.Pz = self.get_parameter('Pz').get_parameter_value().double_value
        self.use_forward_kin = self.get_parameter('use_forward_kin').get_parameter_value().bool_value
        self.desired_angles = np.asarray(self.get_parameter('desired_angles').get_parameter_value().double_array_value)

        self.get_logger().info(f'frw: {self.use_forward_kin}')
        # --------------------------------------------------------------------------------------------------------------------



    def send_cartesian_goal(self, actual_angles: list, Px: float, Py: float, Pz: float, grip: int, desired_angles: list, use_forward_kin: bool):

        goal_msg = FollowJointTrajectory.Goal() #Type of message for the controller's goal
        # Fill in data for trajectory
              

        joint_names = ['joint_base_1', 'joint_12', 'joint_23', 'joint_34', 'joint_45', 'joint_56', 
            'joint_6_g2', 'joint_6_g4', 'joint_grip_2b', 'joint_grip_4b']

        points = []
        point1 = JointTrajectoryPoint()
        self.actual_angles = actual_angles 
        point1.positions = self.actual_angles

        point2 = JointTrajectoryPoint()
        point2.time_from_start = Duration(seconds=5, nanoseconds=0).to_msg()

        if (use_forward_kin): # Joint angle commands rather than goal x,y,z coordinates
            #self.get_logger().info(f'desired: {desired_angles}')
            th1, th2, th3, th4, th5, th6, thg1, thg2, thg3, thg4 = desired_angles # Unpack to prevent not declared variable error when calling error handling
            point2.positions = [float(th1), float(th2), float(th3), float(th4), float(th5), float(th6), 0.0, 0.0, 0.0, 0.0]

        elif (not use_forward_kin): # Goal x,y,z coordinates, use Inverse Kinematics (IK)
            desired_pos = [Px, Py, Pz] # Home: [0.3, 0.3, 0.8]
            th1, th2, th3, th4, th5 = compute_IK(Px = desired_pos[0], Py = desired_pos[1], Pz = desired_pos[2])
            point2.positions = [float(th1), float(th2), float(th3), float(th4), float(th5), 0.0, 0.0, 0.0, 0.0, 0.0]

        else:
            self.get_logger().info('ERROR: Unknown invalid configuration passed')
            rclpy.shutdown()
        
        self.error_handling(th1, th2, th3, th4, th5) # Look out for invalid joint configurations and op volume
    

        points.append(point1)
        points.append(point2)

        if (grip == 1):
            point3 = JointTrajectoryPoint()
            point3.time_from_start = Duration(seconds=8, nanoseconds=0).to_msg()
            # Basic grip: -0.56 0.56 0.73 0.73
            point3.positions = [float(th1), float(th2), float(th3), float(th4), float(th5), 0.0, -0.76, 0.76, 0.73, 0.73]
            points.append(point3)


        goal_msg.goal_time_tolerance = Duration(seconds=5, nanoseconds=0).to_msg()
        goal_msg.trajectory.joint_names = joint_names
        goal_msg.trajectory.points = points

        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)

        self._send_goal_future.add_done_callback(self.goal_response_callback)
    
    '''_____________________________________________________________________________________________________________'''


    
    def goal_response_callback(self, future):
        self.get_logger().info('Goal sent, wait!')
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    
    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Result: '+str(result))
        rclpy.shutdown()


    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.actual_angles = feedback.actual.positions


    def timer_callback(self):
        msg = Float64MultiArray()
        msg.data = self.actual_angles
        self.publisher_.publish(msg)
        #self.get_logger().info('Publishing: "%s"' % msg.data)
    
    def send_request(self, enable):
        self.req = JointsNow.Request()
        self.req.enable = enable
        self.future = self.cli.call_async(self.req)
        self.get_logger().info(f'Received: {self.future}')
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

    
    def error_handling(self, th1, th2, th3, th4, th5):

        if (th1 == -100):
            self.get_logger().info('ERROR 1: No solutions found for the desired configuration')
            rclpy.shutdown()
        
        if (th1 == -101):
            self.get_logger().info('ERROR 2: Invalid Z coordinate')
            rclpy.shutdown()
        
        if (th1 == -102):
            self.get_logger().info('ERROR 3: Invalid th2 angle. It should be between -3.14159 and 0')
            rclpy.shutdown()
        
        if (th1 == -103):
            self.get_logger().info('ERROR 4: Invalid th3 angle. It should be between -2.6 and 2.6')
            rclpy.shutdown()
        
        if (th1 == -104):
            self.get_logger().info('ERROR 5: Invalid th4 angle. It should be between -2.6 and 2.6')
            rclpy.shutdown()
        
        if (th1 == -105):
            self.get_logger().info('ERROR 6: Invalid th5 angle. It should be between -2.6 and 2.6')
            rclpy.shutdown()
        
        if (th1 == -106):
            self.get_logger().info('ERROR 7: Out of operating volume')
            rclpy.shutdown()

   

def main(args=None):
    
    rclpy.init()

    action_client = ControlActionClient()
    response = action_client.send_request(enable=bool(sys.argv[0]))

    actual_angles = [response.th1, response.th2, response.th3, response.th4, response.th5, 
        response.th6, response.g2, response.g22, response.g4, response.g44]
    

    future = action_client.send_cartesian_goal(actual_angles=actual_angles, 
        Px=action_client.Px, Py=action_client.Py, Pz=action_client.Pz, grip=1, # FIXME Change grip to input
        desired_angles=action_client.desired_angles, use_forward_kin=action_client.use_forward_kin)
        
    rclpy.spin(action_client)


if __name__ == '__main__':
    main()