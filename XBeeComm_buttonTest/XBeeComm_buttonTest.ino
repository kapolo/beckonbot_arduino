#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

//const int button_pin = 7;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

const char hello[] = "Hello from Node 1!";

void setup()
{
  //pinMode(button_pin, INPUT);
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}
