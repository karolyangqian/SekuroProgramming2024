#include "ros/ros.h"
#include "package1/magnitude.h"

int main(int argc, char **argv){
    // Inisialisasi 
    ros::init(argc,argv,"magnitude_client");
    
    // Inisialisasi Handler Node
    ros::NodeHandle nh;

    // Inisialisasi client dari handler
    ros::ServiceClient client = nh.serviceClient<package1::magnitude>("magnitude");

    // Rate pengiriman pesan sebesar 1hz (1 pesan setiap detik)
    ros::Rate loop_rate(1);

    while(ros::ok()) {
        // Inisialisasi variabel sesuai tipe data srv
        package1::magnitude data;

        // Memberi nilai kepada seluruh data request
        data.request.komponenX = 12;
        data.request.komponenY = 24;
        data.request.komponenZ = 36;

        if (client.call(data)){
            ROS_INFO("[Client] Magnitude yang dicari adalah: %lf", data.response.magnitude);
        }
        else {
            ROS_INFO("[Client] Service gagal dipanggil");
        }

        ros::spinOnce();
        loop_rate.sleep();
    }

}