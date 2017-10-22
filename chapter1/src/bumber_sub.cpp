#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>
#include "chapter1/demo_msg.h"

#include "sstream"

void number_callback(const chapter1::demo_msg::ConstPtr& msg)
{
    ROS_INFO("Received [%d]",msg->number);
    ROS_INFO("recieced this [%s]",msg->greeting.c_str());
}
int main(int argc, char **argv)
{
    ros::init(argc, argv,"demo_topic_subscriber");
    ros::NodeHandle node_obj;
    ros::Subscriber number_subscriber = node_obj.subscribe("/numbers",10,number_callback);
    ros::spin();
return 0;
}