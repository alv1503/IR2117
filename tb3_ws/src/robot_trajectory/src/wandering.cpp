#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

std::shared_ptr< rclcpp::Publisher<sensor_msgs::msg::LaserScan> > publisher;

double front;
double left;
double right;
double back;

void topic_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
    front = msg->ranges[0];
    left = msg->ranges[90];
    right = msg->ranges[270];
    back = msg->ranges[180];
    
    std::cout << "Front: " << front <<
                "\tBack: " << back  <<
                "\nLeft: " << left  <<
                "\tRight: "<< right << "\n" << std::endl;
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("wandering");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  auto subscriber = node->create_subscription<sensor_msgs::msg::LaserScan>("scan", 10, topic_callback);
  
  geometry_msgs::msg::Twist vel;
  
  rclcpp::WallRate loop_rate(10ms);

  while (rclcpp::ok()) {
    vel.linear.x = 0;
    vel.angular.z = 0;
    publisher->publish(vel);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  
  rclcpp::shutdown();
  return 0;
}

