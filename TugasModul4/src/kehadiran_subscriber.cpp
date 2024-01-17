#include "ros/ros.h"
#include "package1/pesan.h"
#include "ascii-art-main/Ascii.h"

using namespace ascii;

std::string ros_ascii_info(std::string text) {
    // Membuat ASCII art
    Ascii font = Ascii(boomer);
    font.print(text);
    std::string letters;
    for (int i = 0; i < font.getletters().size(); i++)
    {
        for (int j = 0; j < font.getletters()[i].size(); j++)
        {
            letters += font.getletters()[i][j];
        }
        letters += "\n";
    }
    return letters;
}

void callbackHandler(const package1::pesan::ConstPtr &msg) {
    // Mencetak pesan yang diterima
    ROS_INFO("\n%s\nKEHADIRAN TERDENGAR:\nusia: %ld\ntinggi: %lf\nnama: %s\nkehadiran: %s\n ",
        ros_ascii_info(msg->kehadiran ? "HADIR" : "ABSEN").c_str(),
        msg->usia, 
        msg->tinggi, 
        msg->nama.c_str(), 
        msg->kehadiran ? "hadir" : "tidak hadir"
        );
}

int main(int argc, char ** argv){
    // Inisialisasi Node
    ros::init(argc,argv,"kehadiran_subscriber");

    // Inisialisasi Handler Node
    ros::NodeHandle nh;

    // Insialisasi Subscriber dari Handler
    ros::Subscriber data_subscriber = nh.subscribe("kehadiran", 1000, callbackHandler);

    ros::spin();

    return 0;
}