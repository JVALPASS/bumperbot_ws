#include "simple_publisher.hpp"
#include <chrono>

using namespace std::chrono_literals;

SimplePublisher::SimplePublisher() : Node("simple_publisher"), counter_{0} {
    pub_ = create_publisher<std_msgs::msg::String>("chatter", 10);
    timer_ = create_wall_timer(1s, std::bind(&SimplePublisher::timerCallback, this));

    RCLCPP_INFO(get_logger(), "publishing at 1Hz");
}

void SimplePublisher::timerCallback() {
    auto message = std_msgs::msg::String();
    message.data = "Hello ROS2 - counter: " + std::to_string(counter_++);

    pub_->publish(message);
}