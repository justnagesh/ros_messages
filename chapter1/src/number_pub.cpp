#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "iostream"
#include "chapter1/demo_msg.h"
#include "sstream"
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "demo_publisher");
    ros::NodeHandle node_obj;
    ros::Publisher publish_num = node_obj.advertise<chapter1::demo_msg>("/numbers",10);
    ros::Rate loop_rate(10);
    int number_count = 0;
    while (ros::ok())
    {
        chapter1::demo_msg msg;
        std::stringstream ss;
        string temo="hello nagesh  hi ";
        ss<< "hello nagesh ";
        msg.greeting=ss.str();
        // std::cout<< ss.str()<<endl;

        // std_msgs::Int32 msg;
        msg.number = number_count;
        ROS_INFO("%d",msg.number);
        ROS_INFO("%s",msg.greeting.c_str());
        ROS_INFO("hello nagesh  hi trst");
        ROS_INFO("hello nagesh  hi trst");
        publish_num.publish(msg);
        // msg.number= number_count
        ros::spinOnce();
        loop_rate.sleep();
        ++number_count;
    }
    return 0;
}

