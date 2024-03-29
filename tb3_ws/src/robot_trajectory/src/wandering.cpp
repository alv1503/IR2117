#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <vector>
#include <Eigen/Dense>

using namespace std::chrono_literals;

double front;
double left;
double right;
double back;

Eigen::VectorXd front_view_left(10);
Eigen::VectorXd front_view_right(10);

double min_left;
double min_right;

bool turn_right = false;
bool turn_left = false;

void topic_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
    front = msg->ranges[0];
    left = msg->ranges[90];
    right = msg->ranges[270];
    back = msg->ranges[180];
    
    for(int i = 0; i < 10; i++){
        front_view_right(i) = msg->ranges[i];
        front_view_left(i) = msg->ranges[i + 350];
    }
    
    min_left = front_view_left.minCoeff();
    min_right = front_view_right.minCoeff();
    
    if((min_left < 1) || (min_right < 1)){
        if(min_left < min_right){
            turn_right = true;
        }
        
        else{
            turn_left = true;
        }
    }
    
    else{
        turn_left = false;
        turn_right = false;
    }
    
    std::cout << "Front: " << front <<
                "\tBack: " << back  <<
                "\nLeft: " << left  <<
                "\tRight: "<< right << "\n" << std::endl;
    
    for(int i = 0; i < 20; i++){
        if(i < 10){
            std::cout << "Range " << i << ": " << front_view_left[i] << "\t";
        }
        
        else{
            std::cout << "Range " << (i + 340) << ": " << front_view_right[i - 10] << "\t";
        };
        
        if(i%2 == 0){std::cout << "\n";}
    }
    std::cout << "Min left: " << min_left << "\tMin right: " << min_right;
    std::cout << "\n" << std::endl;
    
}

int main(int argc, char * argv[]){
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("wandering");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  auto subscriber = node->create_subscription<sensor_msgs::msg::LaserScan>("scan", 10, topic_callback);
  
  geometry_msgs::msg::Twist vel;
  
  rclcpp::WallRate loop_rate(10ms);
  
  while (rclcpp::ok()){
    if((!turn_left) && (!turn_right)) {
        vel.linear.x = 0.22;
        vel.angular.z = 0;
    }
  
    else if(turn_right){
        vel.linear.x = 0.22;
        vel.angular.z = 0.5;
    }
    
    else{
        vel.linear.x = 0.22;
        vel.angular.z = -0.5;
    }
      
    publisher->publish(vel);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  
  vel.linear.x = 0;
  vel.angular.z = 0;
  publisher->publish(vel);
  
  rclcpp::shutdown();
  return 0;
}
