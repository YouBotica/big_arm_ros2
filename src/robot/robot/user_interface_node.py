import os
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from threading import Thread 
import time
import json

import tkinter as tk
from tkinter import filedialog, Text, Label
from tkinter import *
from PIL import ImageTk, Image

from ament_index_python.packages import get_package_share_directory
from concurrent.futures import ThreadPoolExecutor
from functools import partial

from std_msgs.msg import String
from sensor_msgs.msg import JointState

import pdb


class CommandsPublisher(Node):
    def __init__(self, root):
        super().__init__('commands_publisher')

        self.joints_subscription = self.create_subscription(
            JointState,
            '/joint_states',
            self.joints_callback,
            10)
        self.joints_subscription  # prevent unused variable warning

        self.jb1 = "WARNING: Not retrieved yet!"
        self.j12 = self.jb1
        self.j23 = self.jb1
        self.j34 = self.jb1
        self.j45 = self.jb1
        self.j56 = self.jb1

        self.threadPool = ThreadPoolExecutor(max_workers=2)
        self.joint_entries_dict = {}

        # GUI:
        self.GUI_Layout(root=root)



    def GUI_Layout(self, root):
        root.title("Robotic Arm Control GUI")
        canvas = tk.Canvas(root, height=700, width=700, bg="#7F7FFF")
        canvas.pack()

        # With the following button the robot goes to its home position:
        goHomeBtn = tk.Button(root, text="Go Home", padx=10, pady=5, fg="white", bg="#263D42", command=self.go_home)
        goHomeBtn.place(x=150,y=450)

        # With the following button the robot goes to its zero position (all joint angles = 0)
        zeroPosBtn = tk.Button(root, text="Go Origin", padx=10, pady=5, fg="white", bg="#263D42", command=self.go_zero)
        zeroPosBtn.place(x=250,y=450)

        # This button allows to send custom angles to our robot:
        setAnglesBtn = tk.Button(root, text="Set Angles", padx=10, pady=5, fg="white", bg="#263D42", command=partial(self.open_angles_cmd_window, root)) # Use of partial to pass input arguments to the command function
        setAnglesBtn.place(x=400,y=30)

        runApps = tk.Button(root, text="Stop robot", padx=10, pady=0, fg="white", bg="#263D42")
        runApps.place(x=350, y=600)

        # create a StringVar class
        self.my_string_var = StringVar()
        self.my_string_var.set(self.jb1) # Sets its text (initially)

        # create a label widget
        verticalDistance = 10
        delta_verticalDistance = 15

        jointInfoWidget = Label(root, textvariable = self.my_string_var)
        jointInfoWidget.place(x=10, y=verticalDistance)

        # Create an object of tkinter ImageTk to display the logo
        pkg_name = 'robot'
        img_file_name = 'youbotica.png'
        img_file_location = os.path.join(get_package_share_directory(pkg_name), 'images', img_file_name)

        img = ImageTk.PhotoImage(Image.open(img_file_location))
        logoImg = Label(canvas, image = img)
        logoImg.image = img # keep a reference or say good bye to your image in the HMI!
        logoImg.pack()

    
    # DIFFERENT ROUTINES THAT CAN BE CALLED BY PRESSING BUTTONS IN OUR GUI:

    def open_angles_cmd_window(self, root): # Opens a new window where the user can insert desired joint angles for the robot
        newWindow = Toplevel(root)
        newWindow.title("Angle Publisher")
        newWindow.geometry("300x400")
        Label(newWindow, text ="Set the desired angles in radians here").pack()

        self.joint_names = ['joint_base_1', 'joint_12', 'joint_23', 'joint_34', 'joint_45', 'joint_56', 
            'joint_6_g2', 'joint_6_g4', 'joint_grip_2b', 'joint_grip_4b'] # List with the exact name of the robot's joints


        it = 0
        advance = 20
        self.joint_entries_txts = []
        self.joint_entries = []
        for joint in self.joint_names: # Creates fields for user to fill
            vert_displacement = 25 + it*advance
            joint = Label(newWindow, text=joint)
            tmp = tk.Entry(newWindow)
            joint.place(x=10, y=vert_displacement)
            tmp.place(x=100, y=vert_displacement)
            self.joint_entries_dict[joint] = tmp
            it += 1

        
        # This button allows the user to tell the robot to go to the desired angles the user gave the UI:
        gotoCustomAnglesBtn = tk.Button(newWindow, text="Send Command!", padx=10, pady=5, fg="white", bg="#263D42", command=self.send_angles) # Use of partial to pass input arguments to the command function
        gotoCustomAnglesBtn.place(x=80,y=370)
        


    def send_angles(self): # Gets the angles from the user input and calls controller to move the joints to the angles
        desired_angles = []
        for key in self.joint_entries_dict:
            desired_angles.append(float(self.joint_entries_dict[key].get()))
        self.get_logger().info(f'desired: {desired_angles}')
        use_forward_kin = True
        self.threadPool.submit(self.goto_angles, use_forward_kin, desired_angles)
    
    def goto_angles(self, use_forward_kin, desired_angles):
        self.get_logger().info(f'desired: {desired_angles}')
        cmd = f'ros2 run robot position_controller --ros-args -p "desired_angles:={desired_angles}" -p use_forward_kin:={use_forward_kin}'
        os.system(cmd)
        

    def go_home(self):
        home_coords = [0.3, 0.3, 0.8]
        use_forward_kin = False
        self.threadPool.submit(self.homing, home_coords[0], home_coords[1], home_coords[-1], use_forward_kin)

    
    def homing(self, Px, Py, Pz, use_forward_kin): # We are using IK for this routine
        empty_list = [] # Not used for this routine, but still needs to be passed as arg
        cmd = f'ros2 run robot position_controller --ros-args -p Px:={Px} -p Py:={Py} -p Pz:={Pz} -p use_forward_kin:={use_forward_kin} -p "desired_angles:={empty_list}"'
        os.system(cmd)
    
    def go_zero(self):
        zero_angles = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        use_forward_kin = True
        self.threadPool.submit(self.zeroing, zero_angles, use_forward_kin)
    
    def zeroing(self, zero_angles, use_forward_kin):
        cmd = f'ros2 run robot position_controller --ros-args -p "desired_angles:={zero_angles}" -p use_forward_kin:={use_forward_kin}'
        os.system(cmd) 

        
    def joints_callback(self, msg):    
        jointDict = {}
        jointDict = {msg.name[i]: round(msg.position[i], 4) for i in range(len(msg.position))}

        self.my_string_var.set(str(jointDict).replace(',', '\n'))




def main(args=None):

    # Tkinter stuff:
    root = tk.Tk()

    # ROS2:
    rclpy.init(args=args)

    commands_publisher = CommandsPublisher(root)

    executor = MultiThreadedExecutor()

    executor.add_node(commands_publisher)

    # Start the ROS2 node on a separate thread
    threadPool = ThreadPoolExecutor(max_workers=2)
    threadPool.submit(executor.spin)
    
    #thread = Thread(target=executor.spin)
    #thread.start()
    commands_publisher.get_logger().info("Spinned ROS2 Node . . .")


    root.mainloop()

    # Destroy the node explicitly
    commands_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()