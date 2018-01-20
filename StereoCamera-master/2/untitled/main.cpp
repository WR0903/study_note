#include <iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    cv::Mat image, Extractcorner;
    vector<cv::Point2f> corners;    //用来储存所有角点坐标
    cv::Size board_size = cv::Size(8,11);   //标定板每行，每列角点数
    image = cv::imread("4.png");
    imshow("2",image);

    Extractcorner = image.clone();

    cv::Mat imageGray,dst;
    cv::cvtColor(image, imageGray, CV_RGB2GRAY);

    equalizeHist(imageGray,dst);
    threshold(dst,dst,70,255,CV_THRESH_BINARY);
    imshow("1",dst);
      waitKey(0);
    bool patternfound = cv::findChessboardCorners(image, board_size, corners, cv::CALIB_CB_FAST_CHECK + cv::CALIB_CB_ADAPTIVE_THRESH + cv::CALIB_CB_NORMALIZE_IMAGE);
    if (!patternfound)
    {
        std::cout << "can not find chessboard corners!" << std::endl;
        exit(1);
    }
    else
    {
        //亚像素精确化
        cv::cornerSubPix(imageGray, corners, cv::Size(11, 11), cv::Size(-1, -1), cv::TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.1));
    }

    //角点检测图像显示
    for (int i = 0; i < corners.size(); i++)
    {
        cv::circle(Extractcorner, corners[i], 5, cv::Scalar(255, 0, 255), 2);
    }
    cv::imshow("Extractcorner", Extractcorner);

    cv::waitKey(0);

    return 0;
}
