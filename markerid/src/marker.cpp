#include "ros/ros.h"
#include <geometry_msgs/TransformStamped.h>//发布位姿的
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include <ros/time.h>
#include <geometry_msgs/PoseStamped.h>

#include <tf/transform_broadcaster.h>
#include <image_transport/image_transport.h>
#include <ARToolKitPlus/TrackerSingleMarker.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/image_encodings.h>
//#include <cstdio>
using ARToolKitPlus::TrackerSingleMarker;
using namespace cv;

const bool useBCH = false;//选择哪一种二维码
const int width = 640, height = 480, bpp = 1;
const int numPixels = width * height * bpp;
unsigned char cameraBuffer[numPixels];

TrackerSingleMarker tracker(width, height, 8, 6, 6, 6, 0);
//cv::void imshow(cv::String const&, cv::_InputArray const&);
std::string  int2str(int num)
{
    std::stringstream ss;
    ss << num;
    std::string text = ss.str();
    return text;
}
void drawMarkerInfo(cv::Mat &image,ARToolKitPlus::ARMarkerInfo* markInfo)
{
    cv::Point center,corner0,corner1,corner2,corner3 ;
    center=cv::Point(markInfo->pos[0],markInfo->pos[1]);
    corner0=cv::Point(markInfo->vertex[(4-markInfo->dir+0)%4][0],markInfo->vertex[(4-markInfo->dir+0)%4][1]);
    corner1=cv::Point(markInfo->vertex[(4-markInfo->dir+1)%4][0],markInfo->vertex[(4-markInfo->dir+1)%4][1]);
    corner2=cv::Point(markInfo->vertex[(4-markInfo->dir+2)%4][0],markInfo->vertex[(4-markInfo->dir+2)%4][1]);
    corner3=cv::Point(markInfo->vertex[(4-markInfo->dir+3)%4][0],markInfo->vertex[(4-markInfo->dir+3)%4][1]);

    cv::line(image,corner0,corner1,CV_RGB(255,0,0),1,8);
    cv::line(image,corner1,corner2,CV_RGB(255,0,0),1,8);
    cv::line(image,corner2,corner3,CV_RGB(255,0,0),1,8);
    cv::line(image,corner3,corner0,CV_RGB(255,0,0),1,8);
    cv::rectangle(image,cv::Point(center.x-1, center.y-1),cv::Point(center.x+1, center.y+1),CV_RGB(0,255,0),1,8); //圈取图像中心点

    //string dir_str = int2str(one_mark.dir);
    std::string tx0 = "0";
    std::string tx1 = "1";
    std::string tx2 = "2";
    std::string tx3 = "3";

    cv::putText(image,tx0,corner0,CV_FONT_HERSHEY_COMPLEX,1,CV_RGB(0,0,255));
    cv::putText(image,tx1,corner1,CV_FONT_HERSHEY_COMPLEX,1,CV_RGB(0,0,255));
    cv::putText(image,tx2,corner2,CV_FONT_HERSHEY_COMPLEX,1,CV_RGB(0,0,255));
    cv::putText(image,tx3,corner3,CV_FONT_HERSHEY_COMPLEX,1,CV_RGB(0,0,255));


    std::string text ="Id:"+ int2str(markInfo->id);
    cv::putText(image,text,cv::Point(center.x+80,center.y),CV_FONT_HERSHEY_COMPLEX,1,CV_RGB(0,0,255));

}

void chatterCallback(const sensor_msgs::ImageConstPtr& msg)
{
    cv::Mat im_raw;
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
    //cv::cvtColor(cv_ptr->image, im_gray, CV_RGB2GRAY);
    cv::cvtColor(im_raw,im_gray,cv::COLOR_BGR2GRAY);
    for(int ii=0;ii<im_gray.rows;ii++)
    {
        uchar *data = im_gray.ptr<unsigned char>(ii);
        for(int jj=0;jj<im_gray.cols;jj++)
        {
            cameraBuffer[640*ii+jj]=data[jj];
            //std::cout<<im_gray.rows<<" "<<im_gray.cols<<std::endl;
        }
    }
    ARToolKitPlus::ARMarkerInfo* markInfo;
    int markNum;
    std::vector<int> markerId = tracker.calc(cameraBuffer,&markInfo,&markNum);
    tracker.selectBestMarkerByCf();
    float conf = tracker.getConfidence();
        //printf("\n\nFound marker %d  (confidence %d%%)\n\nPose-Matrix:\n  ", markerId[0], (int(conf * 100.0f)));
            // use the result of calc() to setup the OpenGL transformation
            // glMatrixMode(GL_MODELVIEW)
            // glLoadMatrixf(tracker.getModelViewMatrix());
        if(!markerId.empty())
        {
            printf("\n\nFound marker %d  (confidence %d%%)\n\nPose-Matrix:\n  ", markerId[0], (int(conf * 100.0f)));
            for (int i = 0; i < 16; i++)
            printf("%.2f  %s", tracker.getModelViewMatrix()[i], (i % 4 == 3) ? "\n  " : "");
        }
        else
        {
            std::cout<<"no found"<<std::endl;
        }
        drawMarkerInfo(im_raw,markInfo);
    cv::imshow("image_mark",im_raw);
    cv::waitKey(30);
    //cv::imshow("image_marker",im_raw);
}
int main(int argc,char** argv)
{
    ros::init(argc, argv, "detect_marker");
    ros::NodeHandle nh;///image_raw
    ros::Subscriber sub=nh.subscribe("/image_raw",1,&chatterCallback);

    

    
        tracker.setPixelFormat(ARToolKitPlus::PIXEL_FORMAT_LUM);
        if (!tracker.init("/home/wr/catkin_ws/src/markerid/src/PGR_M12x0.5_2.5mm.cal", 1.0f, 1000.0f)) // load MATLAB file
        {
            printf("ERROR: init() failed\n");
            return -1;
        }

        //tracker.getCamera()->printSettings();

            // define size of the marker in OpenGL units
        tracker.setPatternWidth(7);

            // the marker in the BCH test image has a thin border...
        tracker.setBorderWidth(useBCH ? 0.125 : 0.25);

            // set a threshold. alternatively we could also activate automatic thresholding
        tracker.setThreshold(150);//阈值，也可以自动阈值

            // let's use lookup-table undistortion for high-speed
            // note: LUT only works with images up to 1024x1024
        tracker.setUndistortionMode(ARToolKitPlus::UNDIST_LUT);

            // switch to simple ID based markers
            // use the tool in tools/IdPatGen to generate markers
        tracker.setMarkerMode(useBCH ? ARToolKitPlus::MARKER_ID_BCH : ARToolKitPlus::MARKER_ID_SIMPLE);

        
        ros::spin();
        
      
    ros::shutdown();
    //delete(tracker);
    return 0;
}
