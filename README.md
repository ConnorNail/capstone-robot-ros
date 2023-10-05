# capstone-robot-ros

## How to Start the System
### ROS
`roslaunch capstone_moveit_config demo_gazebo.launch`

Once complete

`roslaunch capstone_moveit_config moveit_servo.launch`

**Reset** the arm in RViz

Set to a non-singular position with the angle sliders. This position should match the starting VR position.

Select **Plan and Execute**

`roslaunch rosbridge_server rosbridge_websocket.launch`

`rosrun moveit_tutorials servoListener.py`

```
rosservice call /controller_manager/switch_controller "start_controllers: ['joint_group_position_controller']
stop_controllers: ['arm_controller']
strictness: 0
start_asap: false
timeout: 0.0"
```
### Oculus
Start **Capstone** application on Oculus headset

`rosrun rosserial_python serial_node.py /dev/ttyACM0`
