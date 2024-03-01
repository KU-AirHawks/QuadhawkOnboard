#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32

def publish_numbers():
    rospy.init_node('number_publisher', anonymous=True)
    pub = rospy.Publisher('number_topic', Int32, queue_size=10)
    rate = rospy.Rate(1)  # 1 Hz

    count = 1
    while not rospy.is_shutdown():
        rospy.loginfo("Publishing: %d", count)
        pub.publish(count)
        count = (count % 8) + 1  # Cycle from 1 to 8
        rate.sleep()

if __name__ == '__main__':
    try:
        publish_numbers()
    except rospy.ROSInterruptException:
        pass
