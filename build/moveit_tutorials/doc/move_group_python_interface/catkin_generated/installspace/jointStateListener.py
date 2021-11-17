#!/usr/bin/env python3
import rospy
import tf
from std_msgs.msg import String
from geometry_msgs.msg import PoseStamped, TwistStamped

class UnityPose:
    def __init__(self):
        self.lastX = 0
        self.lastY = 0
        self.lastZ = 0
        self.lastXAngle = 0
        self.lastYAngle = 0
        self.lastZAngle = 0
        rospy.Subscriber("/joint_states", TwistStamped, self.callback)

    def callback(self, data):
        x = data.position
        t = rospy.get_rostime().secs + rospy.get_rostime().nsecs*0.000000001
        print("X:", x[0])
        print("Y:", x[1])
        print("Z:", x[2])
        print("Time:", t)
        print("Frame ID:", data.header.frame_id)
        print("-----------------------------------------------------------")

        

if __name__ == '__main__':
    rospy.init_node('listener', anonymous=True)
    UnityPose()
    rospy.spin()
