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


        self.cli = self.create_client(JointsNow, 'joints_now')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        
        self.req = JointsNow.Request()
        # If initial poses were retrieved, destroy subscription
        #self.subscription.destroy()


        qos_profile = QoSProfile(depth=10)
        self.publisher_ = self.create_publisher(Float64MultiArray, 'angle_publisher', 10)
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

        self.got_initial_poses = False 




    def send_goal(self, actual_angles: list, Px: float, Py: float, Pz: float):

        goal_msg = FollowJointTrajectory.Goal() #Type of message for the controller's goal
        # Fill in data for trajectory
        joint_names = ['joint_base_1', 'joint_12', 'joint_23', 'joint_34', 'joint_45', 'joint_56']

        points = []
        point1 = JointTrajectoryPoint()
        self.actual_angles = actual_angles #[actual_angles[0], actual_angles[1], actual_angles[2], actual_angles[3], actual_angles[4], 0.0]
        point1.positions = self.actual_angles
        #[0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

        point2 = JointTrajectoryPoint()
        point2.time_from_start = Duration(seconds=5, nanoseconds=0).to_msg()

        desired_pos = [Px, Py, Pz] # Home: [0.3, 0.3, 0.8]

        th1, th2, th3, th4, th5 = compute_IK(Px = desired_pos[0], Py = desired_pos[1], Pz = desired_pos[2])

        self.error_handling(th1, th2, th3, th4, th5)

        point2.positions = [float(th1), float(th2), float(th3), float(th4), float(th5), 0.0]

        points.append(point1)
        points.append(point2)


        goal_msg.goal_time_tolerance = Duration(seconds=5, nanoseconds=0).to_msg()
        goal_msg.trajectory.joint_names = joint_names
        goal_msg.trajectory.points = points

        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)

        self._send_goal_future.add_done_callback(self.goal_response_callback)

    
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
        self.actual_angles = [float(feedback.actual.positions[0]), 
            float(feedback.actual.positions[1]), float(feedback.actual.positions[2]), float(feedback.actual.positions[3]),
            float(feedback.actual.positions[4]), float(feedback.actual.positions[5])] 
        

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
            self.get_logger().info('ERROR 7: Out of working volume')
            rclpy.shutdown()

   

def main(args=None):
    
    rclpy.init()
    Px = float(input("Px"))
    Py = float(input("Py"))
    Pz = float(input("Pz"))

    action_client = ControlActionClient()
    response = action_client.send_request(enable=bool(sys.argv[0]))
    actual_angles = [response.th1, response.th2, response.th3, response.th4, response.th5, response.th6]
    future = action_client.send_goal(actual_angles = actual_angles, Px=Px, Py=Py, Pz=Pz)

    rclpy.spin(action_client)


if __name__ == '__main__':
    main()