#!/usr/bin/env python3
import rospy
from package1.msg import pesan

def showHadir():
    text = (
"""
_   _     ___     ______   _____   ______
| | | |   / _ \   |  _  \  |_   _|  | ___ \ 
| |_| |  / /_\ \  | | | |    | |    | |_/ /
|  _  |  |  _  |  | | | |    | |    |    /
| | | |  | | | |  | |/ /    _| |_   | |\ \ 
\_| |_/  \_| |_/  |___/     \___/   \_| \_|
"""
    )
    return text

def showAbsen():
    text = (
"""
  ___    ______    _____    _____    _   _
 / _ \   | ___ \  /  ___|  |  ___|  | \ | |
/ /_\ \  | |_/ /  \ `--.   | |__    |  \| |
|  _  |  | ___ \   `--. \  |  __|   | . ` |
| | | |  | |_/ /  /\__/ /  | |___   | |\  |
\_| |_/  \____/   \____/   \____/   \_| \_/
"""
    )
    return text

def callback(data):
    # Mencetak pesan yang diterima
    if data.kehadiran:
        head = showHadir()
    else:
        head = showAbsen()
    
    rospy.loginfo("\n%s\nTERDENGAR usia: %ld tinggi: %lf nama: %s kehadiran: %s" % 
                  (head, 
                   data.usia, 
                   data.tinggi, 
                   data.nama, 
                   "Hadir" if data.kehadiran else "Tidak hadir"))
    
def listener():
    # Inisialisasi Node
    rospy.init_node("kehadiran_subscriber",anonymous=True)

    # Inisialisasi Subscriber
    rospy.Subscriber("kehadiran", pesan, callback)

    rospy.spin()

if __name__ == "__main__":
    try:
        listener()
    except rospy.ROSInterruptException:
        pass