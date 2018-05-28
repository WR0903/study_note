#include <cstdio>
#include <ARToolKitPlus/TrackerSingleMarker.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
using ARToolKitPlus::TrackerSingleMarker;
using namespace cv;
using namespace std;
std::string  int2str(int num);
void drawMarkerInfo(cv::Mat &image,ARToolKitPlus::ARMarkerInfo* markInfo);

int main(int argc, char** argv)
{
    const bool useBCH = false;//选择哪一种二维码
    const int width = 640, height = 480, bpp = 1;
    size_t numPixels = width * height * bpp;
    ARToolKitPlus::ARMarkerInfo* markInfo;
    int markNum;

    unsigned char cameraBuffer[numPixels];
    VideoCapture capture(0);
    TrackerSingleMarker tracker(width, height, 8, 6, 6, 6, 0);
    tracker.setPixelFormat(ARToolKitPlus::PIXEL_FORMAT_LUM);
    if (!tracker.init("/home/wr/study_note/ArToolKitPlus/untitled/PGR_M12x0.5_2.5mm.cal", 1.0f, 1000.0f)) // load MATLAB file
    {
        printf("ERROR: init() failed\n");
        return -1;
    }
    tracker.setPatternWidth(80);
    tracker.setBorderWidth(useBCH ? 0.125 : 0.25);
    tracker.setThreshold(150);//阈值，也可以自动阈值
    tracker.setUndistortionMode(ARToolKitPlus::UNDIST_LUT);
    tracker.setMarkerMode(useBCH ? ARToolKitPlus::MARKER_ID_BCH : ARToolKitPlus::MARKER_ID_SIMPLE);
    while(1)
    {
        Mat frame,src;
        capture>>frame;
        frame.copyTo(src);
        cv::cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
        for(int ii=0;ii<frame.rows;ii++)
        {
            uchar *data = frame.ptr<unsigned char>(ii);
            for(int jj=0;jj<frame.cols;jj++)
            {
                cameraBuffer[640*ii+jj]=data[jj];
            }
        }

        std::vector<int> markerId = tracker.calc(cameraBuffer,&markInfo,&markNum);
        tracker.selectBestMarkerByCf();
        float conf = tracker.getConfidence();
        if(!markerId.empty())
        {
            printf("\n\nFound marker %d  (confidence %d%%)\n\nPose-Matrix:\n  ", markerId[0], (int(conf * 100.0f)));
            for (int i = 0; i < 16; i++)
                printf("%.2f  %s", tracker.getModelViewMatrix()[i], (i % 4 == 3) ? "\n  " : "");
        }
        drawMarkerInfo(src,markInfo);
        imshow("1",src);
        waitKey(30);
    }


    return 0;
}
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
