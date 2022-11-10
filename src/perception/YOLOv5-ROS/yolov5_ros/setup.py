from setuptools import setup

import os
from glob import glob
from urllib.request import urlretrieve

package_name = 'yolov5_ros'

setup(
    name=package_name,
    version='0.2.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('./launch/*.launch.py')),
        (os.path.join('share', package_name, 'utils'), glob('./yolov5_ros/utils/*.py')),
        (os.path.join('share', package_name, 'models'), glob('./yolov5_ros/models/*.py')),
        (os.path.join('share', package_name, 'models'), glob('./yolov5_ros/models/*.yaml')),
        (os.path.join('share', package_name, 'config'), glob('./yolov5_ros/config/*.pt')), 
        (os.path.join('share', package_name, 'data'), glob('./yolov5_ros/data/*.yaml')),
        (os.path.join('share', package_name, 'params'), glob('./yolov5_ros/params/*.yaml')), 
        # (os.path.join('share', package_name), glob('../weights/*.pth'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    author='Ar-Ray-code',
    author_email="ray255ar@gmail.com",
    maintainer='Ar-Ray-code',
    maintainer_email="ray255ar@gmail.com",
    description='YOLOv5 + ROS2 Foxy',
    license='GNU GENERAL PUBLIC LICENSE Version 3',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'yolov5_cam1 = '+package_name+'.base_camera_yolo:ros_main',
        ],
    },
)
