#include "bumperbot_cpp_examples/simple_turtlesim_kinematics.hpp"

using std::placeholders::_1;

SimpleTurtlesimKinematics::SimpleTurtlesimKinematics(const std::string &name) : Node(name){
    this->turtle1_pose_sub_ = create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, 
        std::bind(&SimpleTurtlesimKinematics::turtle1PoseCallback, this, _1));
    this->turtle2_pose_sub_= create_subscription<turtlesim::msg::Pose>("/turtle2/pose", 10, 
        std::bind(&SimpleTurtlesimKinematics::turtle2PoseCallback, this, _1));   
}

void SimpleTurtlesimKinematics::turtle1PoseCallback(const turtlesim::msg::Pose &pose){
    this->last_turtle1_pose_ = pose;
}
void SimpleTurtlesimKinematics::turtle2PoseCallback(const turtlesim::msg::Pose &pose){
    this->last_turtle2_pose_ = pose;
    float Tx = this->last_turtle2_pose_.x - this->last_turtle1_pose_ .x;
    float Ty = this->last_turtle2_pose_.y - this->last_turtle1_pose_ .y;

    RCLCPP_INFO_STREAM(get_logger(), "\nTRanslation vectir turtle1 -> turtle2 \n" <<
        "Tx" << Tx << "\n" <<
        "Ty" << Ty << "\n");
}

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimpleTurtlesimKinematics>("simple_turtlesim_kinematics");
    rclcpp::spin(node);
    rclcpp::shutdown();

}