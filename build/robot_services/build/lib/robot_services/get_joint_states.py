import sys 
import os
import rclpy
from rclpy.node import Node
from control_msgs.msg import JointTrajectoryControllerState
from ament_index_python.packages import get_package_share_directory
from big_arm_interfaces.srv import JointsNow
import pdb


class JointsService(Node):

    def __init__(self):
        super().__init__('joints_service')

        self.got_initial_poses = False

        # TODO: Get actual angles of the system here
        self.subscription = self.create_subscription(
            JointTrajectoryControllerState,
            '/joint_trajectory_controller/state',
            self.joints_callback,
            10)
        self.subscription  # prevent unused variable warning

        self.srv = self.create_service(JointsNow, 'joints_now', self.service_callback)
      

    def service_callback(self, request, response):
        #if (self.got_initial_poses == False):
        #    return -100

        response.success = True 
        response.th1 = self.th1_initial
        response.th2 = self.th2_initial
        response.th3 = self.th3_initial
        response.th4 = self.th4_initial
        response.th5 = self.th5_initial
        response.th6 = self.th6_initial
        
        self.get_logger().info(f'Incoming request from a client, responded:  {response}')

        return response
    
    def joints_callback(self, msg):
        self.th1_initial = msg.actual.positions[0]
        self.th2_initial = msg.actual.positions[1]
        self.th3_initial = msg.actual.positions[2]
        self.th4_initial = msg.actual.positions[3]
        self.th5_initial = msg.actual.positions[4]
        self.th6_initial = msg.actual.positions[4] # FIXME
        #elf.get_logger().info(f'{msg}')
        self.got_initial_poses = True


def main(args=None):
    rclpy.init(args=args)

    joints_service = JointsService()

    rclpy.spin(joints_service)

    rclpy.shutdown()


if __name__ == '__main__':
    main()