//
// Created by aaron on 08/01/19.
//

#include "ros/ros.h"
#include "nav_msgs/Path.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/PoseStamped.h"
#include <iostream>
#include <vector>

using geometry_msgs::PoseStamped;

PoseStamped point(double x, double y, double speed) {
    PoseStamped p1;
    p1.header.stamp = ros::Time::now();
    p1.header.frame_id = "map";
    p1.pose.position.x = x;
    p1.pose.position.y = y;
    p1.pose.position.z = speed;
    return p1;
}

int main(int argc, char **argv) {

    ros::init(argc, argv, "path_planning_node");

    ros::NodeHandle n;

    ros::Publisher path_pub = n.advertise<nav_msgs::Path>("path", 100);

    ros::Rate loop_rate(1);

    std::vector<PoseStamped> poses;

    nav_msgs::Path path;
    path.header.frame_id = "map";
    path.header.stamp = ros::Time::now();
    poses.push_back(point(-7.5, 0, 0.3));
    poses.push_back(point(-6.5, 0, 0.3));
    poses.push_back(point(-2.5,-1,0.3));
    poses.push_back(point(0, -1, 0.3));
    poses.push_back(point(1, -1, 0.3));
    poses.push_back(point(2, -1, 0.3));
    poses.push_back(point(4, -1, 0.3));
    poses.push_back(point(5.5, -1, 0.3));
    poses.push_back(point(5.5, 1, 0.3));
    poses.push_back(point(5, 1, 0.3));
    poses.push_back(point(4, 1, 0.3));
    poses.push_back(point(1, 1, 0.3));
    poses.push_back(point(0.5, 1, 0.3));
    poses.push_back(point(-6.2, 1, 0.3));
    poses.push_back(point(-6.5, 1, 0.0));
    path.poses.resize(poses.size());
    for (int i = 0; i < poses.size(); ++i) {
        PoseStamped p = poses.at(i);
        path.poses.at(i) = p;
    }

    int count = 0;
    while (ros::ok()) {

        path_pub.publish(path);
        count++;
        std::cout << "sent" << std::endl;
        ros::spinOnce();

        loop_rate.sleep();
    }


    return 0;
}