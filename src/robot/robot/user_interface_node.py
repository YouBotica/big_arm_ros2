import os
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from threading import Thread 
import time

import tkinter as tk
from tkinter import filedialog, Text, Label
from tkinter import *
from PIL import ImageTk, Image

from ament_index_python.packages import get_package_share_directory

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

        self.text = "None."

        # GUI:
        root.title("Robotic Arm Control GUI")
        canvas = tk.Canvas(root, height=700, width=700, bg="#263D42")
        canvas.pack()

        frame = tk.Frame(root, bg="white")
        frame.place(relwidth=0.8, relheight=0.8, relx=0.1, rely=0.1)

        openFile = tk.Button(root, text="Launch robot", padx=10, pady=5, fg="white", bg="#263D42")
        openFile.place(x=350,y=350)

        runApps = tk.Button(root, text="Stop robot", padx=10, pady=0, fg="white", bg="#263D42")
        runApps.place(x=350, y=600)

        # create a StringVar class
        self.my_string_var = StringVar()
        self.my_string_var.set(self.text) # Sets its text (initially)

        # create a label widget
        jointInfoWidget = Label(root, textvariable = self.my_string_var)

        jointInfoWidget.place(x=350, y=500)

        # Create an object of tkinter ImageTk to display the logo
        pkg_name = 'robot'
        img_file_name = 'youbotica.png'
        img_file_location = os.path.join(get_package_share_directory(pkg_name), 'images', img_file_name)

        img = ImageTk.PhotoImage(Image.open(img_file_location))
        logoImg = Label(frame, image = img)
        logoImg.image = img # keep a reference!
        logoImg.pack()



    def joints_callback(self, msg):
        self.text = str(msg.position)
        # set the text
        self.my_string_var.set(self.text)
        #self.get_logger().info('I heard: "%s"' % msg.position)




def main(args=None):

    # Tkinter stuff:
    root = tk.Tk()

    # ROS2:
    rclpy.init(args=args)

    commands_publisher = CommandsPublisher(root)

    executor = MultiThreadedExecutor()

    executor.add_node(commands_publisher)

    # Start the ROS2 node on a separate thread
    thread = Thread(target=executor.spin)
    thread.start()
    commands_publisher.get_logger().info("Spinned ROS2 Node . . .")


    root.mainloop()

    # Destroy the node explicitly
    commands_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()