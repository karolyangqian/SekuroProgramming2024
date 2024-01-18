#include "ros/ros.h"
#include "package1/pesan.h"

int main(int argc, char**argv) {
    // Inisialisasi Node
    ros::init(argc,argv,"kehadiran_publisher");

    // Inisialisasi Handler Node
    ros::NodeHandle nh;
    // Insialisasi Publisher dari Handler
    ros::Publisher data_publisher = nh.advertise<package1::pesan>("kehadiran", 1000);

    // Rate pengiriman pesan sebesar 1hz (1 pesan setiap detik)
    ros::Rate loop_rate(1);

    // ros::ok() menyatakan true jika file ini di run. false jika file file ini dimatikan atau roscore dimatikan
    while(ros::ok()) { 

        // Variabel dengan tipe msg yang ditentukan
        package1::pesan data;

        // Pemberian nama terhadap masing-masing data didalam variabel
        data.usia = 17;
        data.tinggi = 165.5;
        data.nama = "Ucup";
        data.kehadiran = false;

        // // Mencetak hasil variabel kedalam console simple_publisher_node.cpp
        // ROS_INFO("\nMENGIRIM KEHADIRAN:\nusia: %ld\ntinggi: %lf\nnama: %s\nkehadiran: %s\n ", 
        // data.usia, 
        // data.tinggi, 
        // data.nama.c_str(), 
        // data.kehadiran ? "hadir" : "tidak hadir"
        // );

        // Mengirim variabel kedalam topik "topik_utama"
        data_publisher.publish(data);

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}