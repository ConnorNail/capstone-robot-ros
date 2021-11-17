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
        self.time = -0.001
        rospy.Subscriber("unityChatter", PoseStamped, self.callback)
        self.pub = rospy.Publisher('/servo_server/delta_twist_cmds', TwistStamped, queue_size=10)

    def callback(self, data):
        msg = TwistStamped()
        lastX = self.lastX
        lastY = self.lastY
        lastZ = self.lastZ
        lastXAngle = self.lastXAngle
        lastYAngle = self.lastYAngle
        lastZAngle = self.lastZAngle
        lastTime = self.time
        vX = 0
        vY = 0
        vZ = 0
        vXAngle = 0
        vYAngle = 0
        vZAngle = 0
        
        x = data.pose.position.x
        y = data.pose.position.y
        z = data.pose.position.z
        time = rospy.get_rostime().secs + rospy.get_rostime().nsecs*0.000000001
        print("X:", x)
        print("Y:", y)
        print("Z:", z)
        print("Time:", time)
        print("-----------------------------------------------------------")

        #Get velocities of eef
        deltaTime = time - lastTime
        if deltaTime != 0:
            vX = (x - lastX)/deltaTime
            vY = (y - lastY)/deltaTime
            vZ = (z - lastZ)/deltaTime
        print("dX:", vX)
        print("dY:", vY)
        print("dZ:", vZ)
        print("Delta Time:", deltaTime)
        print("-----------------------------------------------------------")
        
        #Get angles of eef
        q = data.pose.orientation
        angles = tf.transformations.euler_from_quaternion([q.x, q.y, q.z, q.w])
        print("X Angle:", angles[0])
        print("Y Angle:", angles[1])
        print("Z Angle:", angles[2])
        print("-----------------------------------------------------------")
        
        #Get angular velocities
        if deltaTime != 0:
            vXAngle = (angles[0] - lastXAngle)/deltaTime
            vYAngle = (angles[1] - lastYAngle)/deltaTime
            vZAngle = (angles[2] - lastZAngle)/deltaTime
        print("dX Angle:", vXAngle)
        print("dY Angle:", vYAngle)
        print("dZ Angle:", vZAngle)
        print("-----------------------------------------------------------")
        
        #Assign Twist values
        msg.header = data.header
        msg.twist.linear.x = vX
        msg.twist.linear.y = vY
        msg.twist.linear.z = vZ
        
        self.pub.publish(msg)
        
        #Save last values
        self.lastX = x
        self.lastY = y
        self.lastZ = z
        self.lastXAngle = angles[0]
        self.lastYAngle = angles[1]
        self.lastZAngle = angles[2]
        self.time = time
        

if __name__ == '__main__':
    rospy.init_node('listener', anonymous=True)
    UnityPose()
    rospy.spin()
