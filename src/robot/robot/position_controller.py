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

        qos_profile = QoSProfile(depth=10)
        self.publisher_ = self.create_publisher(Float64MultiArray, 'angle_publisher', 10)
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def send_goal(self, angle):
        goal_msg = FollowJointTrajectory.Goal() #Type of message for the controller's goal
        # Fill in data for trajectory
        joint_names = ['joint_base_1', 'joint_12', 'joint_23', 'joint_34', 'joint_45', 'joint_56']

        points = []
        point1 = JointTrajectoryPoint()
        point1.positions = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

        point2 = JointTrajectoryPoint()
        point2.time_from_start = Duration(seconds=5, nanoseconds=0).to_msg()

        desired_pos = [0.6, -0.5, 0.6]

        th1, th2, th3, th4, th5 = compute_IK(Px = desired_pos[0], Py = desired_pos[1], Pz = desired_pos[2])

        #point2.positions = [angle, angle, -angle, angle, angle/2, angle/2]
        #pdb.set_trace()
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
        #self.get_logger().info('Received feedback:'+str(feedback))
        self.actual_angles = [float(feedback.actual.positions[0]), 
            float(feedback.actual.positions[1]), float(feedback.actual.positions[2]), float(feedback.actual.positions[3]),
            float(feedback.actual.positions[4]), float(feedback.actual.positions[5])] 
        #self.get_logger().info('Received feedback:'+str(feedback.actual.positions[0]))

    def timer_callback(self):
        msg = Float64MultiArray()
        msg.data = self.actual_angles
        self.publisher_.publish(msg)
        #self.get_logger().info('Publishing: "%s"' % msg.data)

    

def main(args=None):
    
    rclpy.init()

    action_client = ControlActionClient()

    angle = 0.0 #float(sys.argv[1])
    future = action_client.send_goal(angle)
    #future = action_client.send_goal(-angle)

    rclpy.spin(action_client)


if __name__ == '__main__':
    main()