#!/usr/bin/env python3
import rospy
from std_msgs.msg import Int16


def sender():
    pub = rospy.Publisher('servo', Int16, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        message = 4
        rospy.loginfo(f"Sending {message}")
        pub.publish(message)
        rate.sleep()

if __name__ == "__main__":
    try: 
        sender()
    except rospy.ROSInterruptException:
        print(f"Got exception")
        pass