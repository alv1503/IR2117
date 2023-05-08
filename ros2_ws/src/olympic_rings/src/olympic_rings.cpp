#include <chrono>
#include "rclcpp/rclcpp.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <memory>
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/srv/set_pen.hpp"
#include "turtlesim/srv/teleport_absolute.hpp"
#include "turtlesim/srv/teleport_relative.hpp"

using namespace std::chrono_literals;
using turtlesim::srv::SetPen;
using turtlesim::srv::TeleportAbsolute;
using turtlesim::srv::TeleportRelative;


int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  
  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("rings");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
  
  geometry_msgs::msg::Twist vel_msg;
  
  rclcpp::WallRate loop_rate(100ms);
  
  node->declare_parameter("radius", 1.0);
  double radius = node->get_parameter("radius").get_parameter_value().get<double>();
  float v_angular = 1.2, v_linear  = radius * v_angular;
  
  int j, iterations = 2*M_PI / (v_angular * 0.1);

  int r[5] = {0, 0, 223, 244, 0};
  int g[5] = {129, 0, 0, 195, 159};
  int b[5] = {200, 0, 36, 0, 61};
  
  double desplazamiento_x[5] = {-2.166667, 0, 2.166667, -1.166667, 1.166667};
  double desplazamiento_y[5] = {0, 0, 0, -1, -1};

  rclcpp::Client<SetPen>::SharedPtr client_set_pen = node->create_client<SetPen>("/turtle1/set_pen");
  auto request_set_pen = std::make_shared<SetPen::Request>();
  auto result_set_pen = client_set_pen->async_send_request(request_set_pen);

  rclcpp::Client<TeleportAbsolute>::SharedPtr client_teleport_absolute = node->create_client<TeleportAbsolute>("/turtle1/teleport_absolute");
  auto request_teleport_absolute = std::make_shared<TeleportAbsolute::Request>();
  auto result_teleport_absolute = client_teleport_absolute->async_send_request(request_teleport_absolute);

  for (int i = 0; i < 4; i++){
    request_set_pen->r = r[i];
    request_set_pen->g = g[i];
    request_set_pen->b = b[i];
    request_set_pen->width = 5;
    request_set_pen->off = 1;

    result_set_pen = client_set_pen->async_send_request(request_set_pen);
    
    request_teleport_absolute = std::make_shared<TeleportAbsolute::Request>();
    request_teleport_absolute->x = 5.544445 + desplazamiento_x[i] * radius;
    request_teleport_absolute->y = 5.544445 + desplazamiento_y[i] * radius;
    request_teleport_absolute->theta = 0;
    
    result_teleport_absolute = client_teleport_absolute->async_send_request(request_teleport_absolute);
        
        
    request_set_pen->off = 0;
    result_set_pen = client_set_pen->async_send_request(request_set_pen);

    loop_rate.sleep();

    j = 0; 
    while (rclcpp::ok() && (j <= iterations)) {
        vel_msg.linear.x = v_linear;
        vel_msg.angular.z = v_angular;
        publisher->publish(vel_msg);
        
        j++;
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    vel_msg.linear.x = 0.0;
    vel_msg.angular.z = 0.0;
    publisher->publish(vel_msg);

    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  
  rclcpp::shutdown();
  return 0;
}
