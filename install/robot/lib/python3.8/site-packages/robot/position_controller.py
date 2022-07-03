#! /usr/bin/env python

import sys
import rclpy
from rclpy.duration import Duration
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import QoSProfile
from control_msgs.action import FollowJointTrajectory
from trajectory_msgs.msg import JointTrajectoryPoint
from std_msgs.msg import Float64MultiArray
# ros2 action list -t
# ros2 action info /joint_trajectory_controller/follow_joint_trajectory -t
# ros2 interface show control_msgs/action/FollowJointTrajectory

class ControlActionClient(Node):

    def __init__(self):
        super().__init__('control_actionclient')
        self._action_client = ActionClient(self, FollowJointTrajectory, '/joint_trajectory_controller/follow_joint_trajectory')
        self.actual_angles = [0.0, 0.0, 0.0]

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
        point2.time_from_start = Duration(seconds=3, nanoseconds=0).to_msg()
        point2.positions = [angle, angle, -angle, angle, angle/2, angle/2]

        points.append(point1)
        points.append(point2)

        goal_msg.goal_time_tolerance = Duration(seconds=20, nanoseconds=0).to_msg()
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

    angle = float(sys.argv[1])
    future = action_client.send_goal(angle)

    rclpy.spin(action_client)


if __name__ == '__main__':
    main()