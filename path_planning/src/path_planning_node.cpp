//
// Created by aaron on 08/01/19.
//

#include "ros/ros.h"
#include "nav_msgs/Path.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/PoseStamped.h"
#include <iostream>
#include <vector>

#define SET_SPEED 0.5

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

    /* poses.push_back(point(-7.5, 0, 0.3));
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
     poses.push_back(point(-6.5, 1, 0.0));*/

/* Path around high bay from computer */
   /* poses.push_back(point(0.4, 0, SET_SPEED));
    poses.push_back(point(1.9, .1, SET_SPEED));
    poses.push_back(point(3, 0.7, SET_SPEED));
    poses.push_back(point(4.1, 1.6, SET_SPEED));
    poses.push_back(point(5.4, 2.6, SET_SPEED));
    poses.push_back(point(7.1, 3.5, SET_SPEED));
    poses.push_back(point(10.4, 5.7, SET_SPEED));
    poses.push_back(point(12.7, 8, SET_SPEED));
    poses.push_back(point(15, 10.2, SET_SPEED));
    poses.push_back(point(16.2, 12.7, SET_SPEED));
    poses.push_back(point(16.4, 14, SET_SPEED));
    poses.push_back(point(15, 16.9, SET_SPEED));
    poses.push_back(point(14.1, 18.1, SET_SPEED));
    poses.push_back(point(13.1, 19.0, SET_SPEED));
    poses.push_back(point(11.3, 19.7, SET_SPEED));
    poses.push_back(point(9.7, 19.6, SET_SPEED));
    poses.push_back(point(7.6, 17.3, 0));
*/

    /*
    poses.push_back(point(2.485,-.727 ,0.3));
    poses.push_back(point(5.730, -2.107 ,0.3));
    poses.push_back(point(4.505, -8.191 ,0.3));
    poses.push_back(point( 8.029, -1.809 ,0.3));
    poses.push_back(point( 6.472, -0.588 ,0.3));
    poses.push_back(point(10.742, -8.873, 0.3));
    poses.push_back(point(11.041, -2.696,0.3));
    poses.push_back(point(7.998, 1.256 ,0.3));
    poses.push_back(point(12.29,1.180,0.3));
     */

    /*poses.push_back(point(2,-0.1,0.3));
        poses.push_back(point(8,-0.5,0.3));
            poses.push_back(point(8.5,-1,0.3));
                poses.push_back(point(8.5,-2,0.3));
                    poses.push_back(point(7.5,-3,0.3));
                        poses.push_back(point(2,-3,0.3));*/

//around highbay
/*
    poses.push_back(point(0,0,SET_SPEED));
    poses.push_back(point(3.0,0.62,SET_SPEED));
    poses.push_back(point(5.3,2.1,SET_SPEED));
    poses.push_back(point(7.0,4.6,SET_SPEED));
    poses.push_back(point(7.6,7.1,SET_SPEED));
    poses.push_back(point(7.1,10.1,SET_SPEED));
    poses.push_back(point(5.3,12.7,SET_SPEED));
    poses.push_back(point(3.0,13.6,SET_SPEED));
    poses.push_back(point(-2.3,14.1,SET_SPEED));
    poses.push_back(point(-5.1,12.6,SET_SPEED));
poses.push_back(point(-6.6,10.4,SET_SPEED));
poses.push_back(point(-7.4,7.7,SET_SPEED));
poses.push_back(point(-6.8,3.9,SET_SPEED));
poses.push_back(point(-6.3,3.9,SET_SPEED));
poses.push_back(point(-3.14,1,SET_SPEED));
poses.push_back(point(0,0,SET_SPEED));
*/  
//test moving around obstacles
poses.push_back(point(0,0,SET_SPEED));
poses.push_back(point(1.0,0,SET_SPEED));
poses.push_back(point(1.6,-0.05,SET_SPEED));
poses.push_back(point(2.11,-0.05,SET_SPEED));
poses.push_back(point(2.65, -0.48,SET_SPEED));
poses.push_back(point(3.65, -0.89,SET_SPEED));
poses.push_back(point(4.35,-0.92,SET_SPEED));
poses.push_back(point(5.275,-0.36,SET_SPEED));
poses.push_back(point(6.6,-0.414,SET_SPEED));
poses.push_back(point(6.75,0.2,SET_SPEED));
poses.push_back(point(5.67,0.404,SET_SPEED));
poses.push_back(point(4.72,0.84,SET_SPEED));
poses.push_back(point(3.15,0.219,SET_SPEED));
poses.push_back(point(0.5,0.3,SET_SPEED));

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
