#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

const int button_pin = 7;
const char message[]="button pressed!";
char buf[4];

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

const char hello[] = "Hello from Node 1!";

void setup()
{
  pinMode(button_pin, INPUT);
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  if (digitalRead(button_pin)>0){
    //itoa (messagecount, buf, 10);
    str_msg.data = message; // buf;
    chatter.publish( &str_msg );
    //messagecount += 1;
    }
  nh.spinOnce();
  delay(100);
}
