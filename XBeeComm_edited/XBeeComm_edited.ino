
#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

// Altered code and added code -kapolo

int testButton = 12;

const char wandMessage= "";

const char hello[] = { wandMessage };

// End of code changes -kapolo

void setup()
{
  Serial1.begin(57600);// Added in - kapolo
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
