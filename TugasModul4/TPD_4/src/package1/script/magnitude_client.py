#!/usr/bin/env python3

import rospy
from package1.srv import magnitude, magnitudeResponse

def magnitude_client(x, y, z):
    # Inisialisasi Node
    rospy.init_node("magnitude_client")

    rospy.wait_for_service("magnitude_service")
    rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        try:
            # Inisialisasi Client
            findMagnitude = rospy.ServiceProxy('magnitude_service', magnitude)
            response = findMagnitude(x, y, z)

            # Mencetak hasil response
            rospy.loginfo("[Client] Magnitude yang dicari: %lf" % response.magnitude)
            rate.sleep()
        except rospy.ServiceException as e:
            print("[Client] Service call failed %s", e)

if __name__ == '__main__':
    try:
        magnitude_client(12, 12, 12)
    except rospy.ROSInterruptException:
        pass