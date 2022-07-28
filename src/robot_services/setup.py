from setuptools import setup
import os
from glob import glob
from setuptools import find_packages

package_name = 'robot_services'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'srv'), glob('srv/*.srv')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='legacy',
    maintainer_email='andresfelipe3@hotmail.es',
    description='List of services for the robotic arm',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'joints_service = robot_services.get_joint_states:main'
        ],
    },
)
