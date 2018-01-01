#include<iostream>
#include "slamBase.h"
using namespace std;
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

Point2d pixel2cam ( const Point2d& p, const Mat& K )
{
    return Point2d
           (
               ( p.x - K.at<double> ( 0,2 ) ) / K.at<double> ( 0,0 ),
               ( p.y - K.at<double> ( 1,2 ) ) / K.at<double> ( 1,1 )
           );
}

int main( int argc, char** argv )
{
    // 声明并从data文件夹里读取两个rgb与深度图
    Mat rgb1 = imread( "/home/wr/study/RGB-D/PART1/CODE/data/rgb1.png");
    Mat rgb2 = imread( "/home/wr/study/RGB-D/PART1/CODE/data/rgb2.png");
    Mat depth1 = imread( "/home/wr/study/RGB-D/PART1/CODE/data/depth1.png", -1);
    Mat depth2 = imread( "/home/wr/study/RGB-D/PART1/CODE/data/depth2.png", -1);

    Ptr<FeatureDetector> detector = ORB::create();
    Ptr<DescriptorExtractor> descriptor = ORB::create();

    vector< KeyPoint > kp1, kp2; //关键点
    detector->detect( rgb1, kp1 );  //提取关键点
    detector->detect( rgb2, kp2 );

    cout<<"Key points of two images: "<<kp1.size()<<", "<<kp2.size()<<endl;

    // 可视化， 显示关键点
    Mat imgShow;
    drawKeypoints( rgb1, kp1, imgShow, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
    imshow( "keypoints", imgShow );
    imwrite( "/home/wr/study/RGB-D/PART1/CODE/data/keypoints.png", imgShow );
    waitKey(0); //暂停等待一个按键

    // 计算描述子
    Mat desp1, desp2;
    descriptor->compute( rgb1, kp1, desp1 );
    descriptor->compute( rgb2, kp2, desp2 );

    // 匹配描述子
    vector< DMatch > matches;
    Ptr<DescriptorMatcher> matcher  = DescriptorMatcher::create ( "BruteForce-Hamming" );
    matcher->match ( desp1, desp2, matches );
    cout<<"Find total "<<matches.size()<<" matches."<<endl;

    // 可视化：显示匹配的特征
    Mat imgMatches;
    drawMatches( rgb1, kp1, rgb2, kp2, matches, imgMatches );
    imshow( "matches", imgMatches );
    imwrite( "/home/wr/study/RGB-D/PART1/CODE/data/matches.png", imgMatches );
    waitKey( 0 );

    // 筛选匹配，把距离太大的去掉
    // 这里使用的准则是去掉大于四倍最小距离的匹配
    vector< DMatch > goodMatches;
    double minDis = 9999;
    for ( size_t i=0; i<matches.size(); i++ )
    {
        if ( matches[i].distance < minDis )
            minDis = matches[i].distance;
    }
    cout<<"min dis = "<<minDis<<endl;

    for ( size_t i=0; i<matches.size(); i++ )
    {
        if (matches[i].distance < 10*minDis)
            goodMatches.push_back( matches[i] );
    }

    // 显示 good matches
    cout<<"good matches="<<goodMatches.size()<<endl;
    drawMatches( rgb1, kp1, rgb2, kp2, goodMatches, imgMatches );
    imshow( "good matches", imgMatches );
    imwrite( "/home/wr/study/RGB-D/PART1/CODE/data/good_matches.png", imgMatches );
    waitKey(0);

    vector<Point3f> pts_3d;
    // 第二个帧的图像点
    vector< Point2f > pts_2d;

    // 相机内参
    CAMERA_INTRINSIC_PARAMETERS C;
    C.cx = 325.5;
    C.cy = 253.5;
    C.fx = 518.0;
    C.fy = 519.0;
    C.scale = 1000.0;

    Mat K = ( Mat_<double> ( 3,3 ) <<C.fx, 0, C.cx, 0, C.fy, C.cy,0, 0, 1);
    for (size_t i=0; i<goodMatches.size(); i++)
        {
            // query 是第一个, train 是第二个
            cv::Point2f p = kp1[goodMatches[i].queryIdx].pt;
            // 获取d是要小心！x是向右的，y是向下的，所以y才是行，x是列！
            ushort d = depth1.ptr<ushort>( int(p.y) )[ int(p.x) ];
            if (d == 0)
                continue;
            pts_2d.push_back( cv::Point2f( kp2[goodMatches[i].trainIdx].pt ) );

            // 将(u,v,d)转成(x,y,z)
            cv::Point3f pt ( p.x, p.y, d );
            cv::Point3f pd = point2dTo3d( pt, C );
            pts_3d.push_back( pd );
    }

    Mat rvec, tvec;
    // 求解pnp
    solvePnP( pts_3d, pts_2d, K, Mat(), rvec, tvec, false, SOLVEPNP_EPNP );
    cout<<"R="<<rvec<<endl;
    cout<<"t="<<tvec<<endl;



    return 0;
}
