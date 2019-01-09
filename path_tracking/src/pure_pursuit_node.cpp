#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Twist.h>
#include <tf/LinearMath/Matrix3x3.h>
#include <tf/transform_listener.h>

#include "pure_pursuit.h"

class PurePursuitRos{
public:
    PurePursuitRos()
    {
        m_vel_pub = n.advertise<std_msgs::Float64>("linear_velocity_setpoint", 1);
        m_rot_pub = n.advertise<std_msgs::Float64>("rotation_setpoint", 1);
        m_path_sub = n.subscribe("path", 1, &PurePursuitRos::receive_path, this);
    }

    void process()
    {

    }

private:

    void receive_path(const nav_msgs::Path::ConstPtr& path)
    {
        m_path = to_path(*path);
    }

    Path to_path(const nav_msgs::Path& path)
    {
        Path converted;
        for(const auto& p: path.poses)
        {
            converted.push_back(to_point3d(p));
        }
        return converted;
    }

    Point3D to_point3d(const geometry_msgs::PoseStamped& ps)
    {
        return Point3D(ps.pose.position.x, ps.pose.position.y, ps.pose.position.z);
    }

    Point3D get_pose(){
        tf::StampedTransform transform;
        try{
            m_tf_listener.lookupTransform("/map", "/base_link",
                                     ros::Time(0), transform);

        }
        catch (tf::TransformException ex){
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
        }
        Point3D pose;
        pose.x = transform.getOrigin().x();
        pose.y = transform.getOrigin().y();
        tf::Matrix3x3 mat(transform.getRotation());
        double r,p,y;
        mat.getRPY(r,p,y);
        pose.z = y;
        return pose;
    }

    ros::NodeHandle n;
    ros::Publisher m_vel_pub;
    ros::Publisher m_rot_pub;
    ros::Subscriber m_path_sub;
    tf::TransformListener m_tf_listener;
    Path m_path;

};


int main(int argc, char **argv)
{
    ros::init(argc, argv, "pure_pursuit");

    PurePursuitRos pure_pursuit;

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        pure_pursuit.process();

        ros::spin();
    }


    return 0;
}
