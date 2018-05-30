#include <marderid.h>
#define pi 3.141592653
ARToolKitPlus::ARMarkerInfo* markInfo;
int markNum;
unsigned char cameraBuffer[numPixels];
TrackerSingleMarker tracker(width, height, 8, 6, 6, 6, 0);
double Visual_Eular[3];
double Visual_Position[3];
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
void rotToEular_rad(double *rot, double *eular)
{
    double R11=rot[0];
    double R21=rot[4];
    double R31=rot[8];
    double R32=rot[9];
    double R33=rot[10];
    double pitch=asin(R31);
    double yaw = atan2(R32,R33);
    double roll =atan2(R21,R11);
    eular[0]=pitch;
    eular[1]=yaw;
    eular[2]=roll;
}
void rotToEular_angle(double *rot, double *eular)
{
    double R11=rot[0];
    double R21=rot[4];
    double R31=rot[8];
    double R32=rot[9];
    double R33=rot[10];
    double pitch=asin(R31);
    double yaw = atan2(R32,R33);
    double roll =atan2(R21,R11);
    pitch=pitch/pi*180;
    yaw=yaw/pi*180;
    roll=roll/pi*180;
    eular[0]=pitch;
    eular[1]=yaw;
    eular[2]=roll;
}
int getCameraPose_init()
{

    tracker.setPixelFormat(ARToolKitPlus::PIXEL_FORMAT_LUM);
    if (!tracker.init("/home/wr/study_note/MARK/PGR_M12x0.5_2.5mm.cal", 1.0f, 1000.0f)) // load MATLAB file
    {
        printf("ERROR: init() failed\n");
        return -1;
    }
    tracker.setPatternWidth(80);
    tracker.setBorderWidth(useBCH ? 0.125 : 0.25);
    tracker.setThreshold(150);//阈值，也可以自动阈值
    tracker.setUndistortionMode(ARToolKitPlus::UNDIST_LUT);
    tracker.setMarkerMode(useBCH ? ARToolKitPlus::MARKER_ID_BCH : ARToolKitPlus::MARKER_ID_SIMPLE);
    return 0;
}
void getCameraPose(Mat& src)
{
    Mat frame;
    double*outputMatrix;
    double traslation_Matrix[16]={0};
    double eular[3]={0};
    src.copyTo(frame);
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
        //printf("\n\nFound marker %d  (confidence %d%%)\n\nPose-Matrix:\n  ", markerId[0], (int(conf * 100.0f)));
        for (int i = 0; i < 16; i++)
        {
            traslation_Matrix[i]=tracker.getModelViewMatrix()[i];
            //cout<<
        }
        drawMarkerInfo(src,markInfo);
        rotToEular_angle(traslation_Matrix,eular);
        Visual_Position[0]=traslation_Matrix[12];
        Visual_Position[1]=traslation_Matrix[13];
        Visual_Position[2]=traslation_Matrix[14];
        Visual_Eular[0]=eular[0];
        Visual_Eular[1]=eular[1];
        Visual_Eular[2]=eular[2];
    }
    else
    {
        Visual_Position[0]=0;
        Visual_Position[1]=0;
        Visual_Position[2]=0;
        Visual_Eular[0]=0;
        Visual_Eular[1]=0;
        Visual_Eular[2]=0;
    }

}
