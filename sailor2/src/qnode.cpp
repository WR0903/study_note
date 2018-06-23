/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
//#include <sailor2/>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/sailor2/qnode.hpp"
//#include "data"

#include <geometry_msgs/TransformStamped.h>//发布位姿的
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include <ros/time.h>
#include <geometry_msgs/PoseStamped.h>

#include <sailor2/BoundingBoxes.h>
#include <sailor2/BoundingBox.h>

#include <tf/transform_broadcaster.h>
#include <image_transport/image_transport.h>
#include <ARToolKitPlus/TrackerSingleMarker.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/image_encodings.h>
//#include <darknet_ros_msgs/ch>
//#include <darknet_ros_msgs/CheckForObjectsAction.h>
/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sailor2 {

//sailor2::BoundingBox aa;
sailor2::BoundingBoxes aa;
/*****************************************************************************
** Implementation
*****************************************************************************/
void chatterCallback(const sensor_msgs::ImageConstPtr& msg)
{

    cv::Mat im_gray;
    //cv_bridge::CvImagePtr cv_ptr;
    cv_bridge::CvImagePtr cv_ptr;//opencv格式，cv_bridge是链接ros图像与opencv图像的桥梁
    try
    {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);//msg转换成opencv格式，方便处理
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }
    //ROS_ASSERT(cv_ptr->image.channels()==3 || cv_ptr->image.channels()==1);

    cv_ptr->image.copyTo(im_raw);
}
void boundingboxcallback(const sailor2::BoundingBoxes& s)
{
    for(int i=0;i<s.bounding_boxes.size();i++)
    {
        dec_box.class_1=s.bounding_boxes.at(i).Class;
        dec_box.probability_1=s.bounding_boxes.at(i).probability;
        dec_box.x_min=s.bounding_boxes.at(i).xmin;
        dec_box.y_min=s.bounding_boxes.at(i).ymin;
        dec_box.x_max=s.bounding_boxes.at(i).xmax;
        dec_box.y_max=s.bounding_boxes.at(i).ymax;
        std::cout<<dec_box.class_1<<" "<<dec_box.probability_1 <<" " <<dec_box.x_min <<" " <<dec_box.y_min<<" "<<dec_box.x_max<<" "<<dec_box.y_max <<std::endl;
    }
}

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
    {
    ros::init(init_argc,init_argv,"sailor2");
    ros::NodeHandle n;
    chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
    //image_sub=n.subscribe("/darknet_ros/detection_image",1,&chatterCallback);
    boundingbox_sub=n.subscribe("/darknet_ros/bounding_boxes",1,&boundingboxcallback);

}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();

    }
	wait();
}






}  // namespace sailor2
