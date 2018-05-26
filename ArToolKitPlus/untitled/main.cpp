#include <cstdio>
#include <ARToolKitPlus/TrackerSingleMarker.h>
#include <opencv2/opencv.hpp>
#include <iostream>
using ARToolKitPlus::TrackerSingleMarker;
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    const bool useBCH = false;//选择哪一种二维码
    const int width = 640, height = 480, bpp = 1;
    size_t numPixels = width * height * bpp;

    unsigned char cameraBuffer[numPixels];
    //cout<<cameraBuffer[1]<<endl;
    VideoCapture capture(0);
    while(1)
    {
        Mat frame;//=imread("/home/wr/soft/ARToolKitPlus/ARToolKitPlus-2.3.1/sample/data/image_320_240_8_marker_id_simple_nr031.jpg");
        capture>>frame;
        cv::cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
        for(int ii=0;ii<frame.rows;ii++)
        {
            uchar *data = frame.ptr<unsigned char>(ii);
            for(int jj=0;jj<frame.cols;jj++)
            {
                cameraBuffer[640*ii+jj]=data[jj];
            }
        }
        imshow("1",frame);
        TrackerSingleMarker tracker(width, height, 8, 6, 6, 6, 0);
        tracker.setPixelFormat(ARToolKitPlus::PIXEL_FORMAT_LUM);
        if (!tracker.init("/home/wr/study_note/ArToolKitPlus/untitled/PGR_M12x0.5_2.5mm.cal", 1.0f, 1000.0f)) // load MATLAB file
        {
            printf("ERROR: init() failed\n");
            return -1;
        }

       // tracker.getCamera()->printSettings();

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

        // do the OpenGL camera setup
        // glMatrixMode(GL_PROJECTION)
        // glLoadMatrixf(tracker.getProjectionMatrix());

        // here we go, just two calls to find the camera pose
        std::vector<int> markerId = tracker.calc(cameraBuffer);
        tracker.selectBestMarkerByCf();
        float conf = tracker.getConfidence();

        // use the result of calc() to setup the OpenGL transformation
        // glMatrixMode(GL_MODELVIEW)
        // glLoadMatrixf(tracker.getModelViewMatrix());
        if(!markerId.empty())
        {
            printf("\n\nFound marker %d  (confidence %d%%)\n\nPose-Matrix:\n  ", markerId[0], (int(conf * 100.0f)));
            for (int i = 0; i < 16; i++)
                printf("%.2f  %s", tracker.getModelViewMatrix()[i], (i % 4 == 3) ? "\n  " : "");
        }
        waitKey(30);
    }


    return 0;
}
