#include <chrono>
#include <cstdlib>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "example_interfaces/msg/bool.hpp"

using namespace std::chrono_literals;

bool front_detect, left_detect, right_detect;

void callback_front(const example_interfaces::msg::Bool::SharedPtr msg){
    front_detect = msg->data;
}

void callback_left(const example_interfaces::msg::Bool::SharedPtr msg){
    left_detect = msg->data;
}

void callback_right(const example_interfaces::msg::Bool::SharedPtr msg){
    right_detect = msg->data;
}

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("avoidance");
    auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    auto subs_front = node->create_subscription<example_interfaces::msg::Bool>("/front/obstacle", 10, callback_front);
    auto subs_left = node->create_subscription<example_interfaces::msg::Bool>("/left/obstacle", 10, callback_left);
    auto subs_right = node->create_subscription<example_interfaces::msg::Bool>("/right/obstacle", 10, callback_right);
    
    geometry_msgs::msg::Twist vel_msg;
    rclcpp::WallRate loop_rate(50ms);
    
    while (rclcpp::ok()){
        rclcpp::spin_some(node);
        loop_rate.sleep();
        
        if (!front_detect){
            vel_msg.linear.x=0.22;
            vel_msg.angular.z=0.0;
            publisher->publish(vel_msg);
        } 
        
        else if (!left_detect){
            vel_msg.linear.x=0.0;
            vel_msg.angular.z=0.4;
            publisher->publish(vel_msg);
        } 
        
        else if (!right_detect){
            vel_msg.linear.x=0.0;
            vel_msg.angular.z=-0.4;
            publisher->publish(vel_msg);
        }

        
    }
    
    rclcpp::shutdown();
    return 0;
}
