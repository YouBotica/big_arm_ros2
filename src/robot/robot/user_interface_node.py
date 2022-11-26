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

from std_msgs.msg import String
from sensor_msgs.msg import JointState





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

        # GUI:
        self.GUI_Layout(root=root)



    def GUI_Layout(self, root):
        root.title("Robotic Arm Control GUI")
        canvas = tk.Canvas(root, height=700, width=700, bg="#7F7FFF")
        canvas.pack()


        goHomeBtn = tk.Button(root, text="Go Home", padx=10, pady=5, fg="white", bg="#263D42", command=self.go_home)
        goHomeBtn.place(x=200,y=450)

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
    
    def go_home(self):
        home_coords = [0.3, 0.3, 0.8]
        self.threadPool.submit(self.homing, home_coords[0], home_coords[1], home_coords[-1])

    
    def homing(self, Px, Py, Pz):
        cmd = f'ros2 run robot position_controller --ros-args -p Px:={Px} -p Py:={Py} -p Pz:={Pz}'
        os.system(cmd)

        
    def joints_callback(self, msg):
        
        jointDict = {}
        jointDict = {msg.name[i]: round(msg.position[i], 4) for i in range(len(msg.position))}

        #self.get_logger().info('I heard: "%s"' % jointDict)
        # set the text to display it in the HMI
        self.my_string_var.set(str(jointDict).replace(',', '\n'))
        #self.get_logger().info('I heard: "%s"' % self.text)




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