#!/usr/bin/env python3

import rospy
from package1.srv import magnitude, magnitudeResponse
import math

def findMagnitude(req):
    # Mengolah & mencetak data
    resp = math.sqrt(req.komponenX**2 + req.komponenY**2 + req.komponenZ**2)
    rospy.loginfo("\n[Server]\nMENCARI MAGNITUDE\nKomponen X: %lf\nKomponen Y: %lf\nKomponen Z: %lf\nMagnitude: %f" 
                  % (req.komponenX, req.komponenY, req.komponenZ, resp))
    return magnitudeResponse(resp)

def magnitude_server():
    # Inisialisasi Node
    rospy.init_node("magnitude_server")
    
    # Insialisasi Server
    service = rospy.Service('magnitude_service', magnitude, findMagnitude)
    rospy.loginfo("Siap mencari magnitude!")
    rospy.spin()

if __name__ == '__main__':
    try:
        magnitude_server()
    except rospy.ROSInterruptException:
        pass