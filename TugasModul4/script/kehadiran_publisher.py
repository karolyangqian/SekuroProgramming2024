#!/usr/bin/env python3

import rospy
from package1.msg import pesan
import pandas as pd
import numpy as np

def inch_to_cm(inch):
    return inch*2.54

def talker():
    # Inisialisasi Publisher
    message_pub = rospy.Publisher("kehadiran", pesan, queue_size=10)

    # Inisialisasi Node
    rospy.init_node('kehadiran_publisher', anonymous=True)

    # Rate pengiriman pesan sebesar 1hz (1 pesan setiap detik)
    rate = rospy.Rate(1)

    # Membaca CSV biostats
    df = pd.read_csv('/home/karol/TPD_4/src/package1/script/biostats.csv')

    # Menyatakan kehadiran
    df_size = len(df)
    kehadiran = list(map(bool, np.random.randint(2, size=df_size)))
    df.insert(4, "Presence", kehadiran, True)

    i = 0
    size = len(df)
    # rospy.is_shutdown() sama aja seperti ros::ok()
    while not rospy.is_shutdown():

        # Variabel dengan tipe msg yang telah ditentukan
        data = pesan()

        # Pemberian nama terhadap masing-masing data didalam variabel
        data.usia = df.loc[i, "Age"]
        data.tinggi = inch_to_cm(df.loc[i, "Height (in)"])
        data.nama = df.loc[i, "Name"]
        data.kehadiran = df.loc[i, "Presence"]
        i = (i+1)%size

        # # Mencetak hasil variabel kedalam console publisher.py
        # rospy.loginfo(
        #     "\nusia: %ld\ntinggi: %lf\nnama: %s\nkehadiran: %s" % (
        #         data.usia,
        #         data.tinggi,
        #         data.nama,
        #         "Hadir" if data.kehadiran else "Tidak hadir"
        #     )
        # )

        # Mengirim variabel kedalam topik "kehadiran"
        message_pub.publish(data)

        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass