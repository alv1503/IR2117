#define _USE_MATH_DEFINES

#include <cmath>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"

using namespace std::chrono_literals;

int message;
std::shared_ptr< rclcpp::Publisher<nav_msgs::msg::Odometry> > publisher;

double pos_x;
double pos_y;
double pos_z;
double orientation_x;
double orientation_y;
double orientation_z;
double orientation_w;
double x_ini;
double y_ini;
double z_ini;
bool first = true;

void topic_callback(const nav_msgs::msg::Odometry::SharedPtr msg){
  orientation_x = msg->pose.pose.orientation.x;
  orientation_y = msg->pose.pose.orientation.y;
  orientation_z = msg->pose.pose.orientation.z;
  orientation_w = msg->pose.pose.orientation.w;

  double siny_cosp = 2* (orientation_w*orientation_z + orientation_x*orientation_y);
  double cospy_cosp = 1 - 2*(orientation_y*orientation_y + orientation_z*orientation_z);
  double pos_z = atan2(siny_cosp, cospy_cosp);
  
  if (first){
      x_ini = msg->pose.pose.position.x;
      y_ini = msg->pose.pose.position.y;
      z_ini = pos_z;
      first = false;
  }
  
  else{
      pos_x = msg->pose.pose.position.x;
      pos_y = msg->pose.pose.position.y;
  }
  
  
  std::cout << "Initial x: " << x_ini << "\tInitial y: " << y_ini << "\tInitial z: " << z_ini << "\nx: " << pos_x << "\ty: " << pos_y << "\tz: " << pos_z << std::endl;
}

int main(int argc, char * argv[]){
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("square");
  auto subscriber = node->create_subscription<nav_msgs::msg::Odometry>("odom", 10, topic_callback);
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  
  geometry_msgs::msg::Twist message;
  rclcpp::WallRate loop_rate(10ms);

  node->declare_parameter("linear_speed", 0.1);
  node->declare_parameter("angular_speed", M_PI/20);
  node->declare_parameter("square_length", 1.0);
  
  double linear_speed = node->get_parameter("linear_speed").get_parameter_value().get<double>();
  double angular_speed = node->get_parameter("angular_speed").get_parameter_value().get<double>();
  double square_length = node->get_parameter("square_length").get_parameter_value().get<double>();
  
  for (int j = 0; j < 4; j++){
    int i = 0;
    double linear_iterations = square_length / (0.01 * linear_speed);

    while (rclcpp::ok() && (i<linear_iterations)){
        i++;
        message.linear.x = linear_speed;
        message.angular.z = 0.0;
        publisher->publish(message);
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    
    i = 0;
    double t = M_PI_2/angular_speed;
    double angular_iterations = t/0.01;
    while (rclcpp::ok() && (i<angular_iterations)){
        i++;
        message.linear.x = 0.0;
        message.angular.z = angular_speed;
        publisher->publish(message);
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
  }
  message.linear.x = 0.0;
  message.angular.z = 0.0;
  publisher->publish(message);
  
  rclcpp::shutdown();
  return 0;
}
