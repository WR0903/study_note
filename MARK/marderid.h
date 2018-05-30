#ifndef MARDERID_H
#define MARDERID_H

#include <cstdio>
#include <ARToolKitPlus/TrackerSingleMarker.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
using ARToolKitPlus::TrackerSingleMarker;
using namespace cv;
using namespace std;

const bool useBCH = false;//选择哪一种二维码
const int width = 640, height = 480, bpp = 1;
const int numPixels = width * height * bpp;
//double Visual_Eular[3];
//double Visual_Position[3];


std::string  int2str(int num);
void drawMarkerInfo(cv::Mat &image,ARToolKitPlus::ARMarkerInfo* markInfo);
void rotToEular_rad(double *rot, double *eular);
void rotToEular_angle(double *rot, double *eular);
int getCameraPose_init();
void getCameraPose(Mat& src);
#endif // MARDERID_H
