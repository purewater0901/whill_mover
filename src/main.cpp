#include <iostream>
#include <ros/ros.h>
#include <ros_whill/SetSpeedProfile.h>
#include <sensor_msgs/Joy.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "whill_contrller");

    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<sensor_msgs::Joy>("/whill/controller/joy", 10);

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        sensor_msgs::Joy msg;

        msg.header.stamp = ros::Time::now();
        msg.axes.resize(2);
        msg.axes[0] = 0.0;
        msg.axes[1] = 0.3;

        pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}