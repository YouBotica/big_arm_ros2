# big_arm_ros2
This is a personal project I've been working on, it is a 10 DoF robotic arm.

If you want to run it, you will need ROS2 foxy. In other ROS2 distros it will probably work too.
This projects needs ROS2 control and Gazebo ROS2 Control packages installed.

To install those packages, run the following commands:
sudo apt install ros-foxy-ros2-control*
sudo apt install ros-foxy-gazebo-ros2-control*

Clone the project and run the following commands in a terminal:

source /opt/ros/foxy/setup.bash
sudo rosdep init
rosdep update
rosdep install --from-paths src -y --ignore-src
chmod +x control.sh
chmod +x gazebo.sh
chmod +x display.sh

Now, run the control.sh script to spawn the robot and activate the controllers:
./control.sh

If you get any error that prevents you from spawning the robot in gazebo, go to your gazebo models folder (generally it is located in ~/.gazebo/models) and create a new folder with the name "robot". 

Then enter this project repository, go to src/robot, copy the meshes folder, and paste it on the folder you just created (~/.gazebo/models/robot). This is a very common problem, what happens is that depending on your configuration, gazebo sometimes cannot retrieve the mesh files from the project's workspace, thus it is unable to spawn the robot. 

Once you are able to spawn the robot in gazebo, you can move the robot to different x,y,z coordinates by doing the following:
ros2 run robot_services joints_service 
Then in another terminal run:
ros2 run robot position_controller

Now, enter any coordinates that are within the working volume of the robot. The program will ask you to enter x,y,z coordinates one by one.
For example, enter Px=0.5, Py=0.5, Pz=0.8


Brief explanation:
The joints_service script is a service that will tell the system the joint states whenever it is called by the client.
The position controller is going to apply the inverse kinematics to compute the desired joint angles to reach the goal. NOTE: So far, the robot is programmed to reach its goals with both the gripper and its parent joint parallel to to the ground (this is because there are more joint states than equations, so some contraints are required to solve the non-linear system of equations). This means that the robot may not be able to reach some goals that are within the working volume. I will probably add some other configurations to improve the mobility of the robot, this project is still under development, so you can expect future commits! Cheers! 




Video showing the robot operating:
https://user-images.githubusercontent.com/108030129/182917242-15c74810-3788-4a5f-84d8-2e2314c0eeb1.mp4




