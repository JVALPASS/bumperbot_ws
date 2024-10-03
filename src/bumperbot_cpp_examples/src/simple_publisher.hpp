#ifndef SIMPLE_PUBLISHER_HPP
#define SIMPLE_PUBLISHER_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class SimplePublisher : public rclcpp::Node
{
public:
    SimplePublisher();

private:
    uint32_t counter_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;

    void timerCallback();
};

#endif // SIMPLE_PUBLISHER_HPP