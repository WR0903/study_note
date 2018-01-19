#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "slamBase.h"

// 给定index，读取一帧数据
FRAME readFrame( int index, ParameterReader& pd );
// 度量运动的大小
double normofTransform( cv::Mat rvec, cv::Mat tvec );

int main( int argc, char** argv )
{
    ParameterReader pd;
    int startIndex  =   atoi( pd.getData( "start_index" ).c_str() );
    int endIndex    =   atoi( pd.getData( "end_index"   ).c_str() );

    // initialize
    cout<<"Initializing ..."<<endl;
    int currIndex = startIndex; // 当前索引为currIndex
    FRAME lastFrame = readFrame( currIndex, pd ); // 上一帧数据
    // 我们总是在比较currFrame和lastFrame
  //  string detector = pd.getData( "detector" );
  //  string descriptor = pd.getData( "descriptor" );
    CAMERA_INTRINSIC_PARAMETERS camera = getDefaultCamera();//读取相机内参
    computeKeyPointsAndDesp( lastFrame);//计算特征点
    PointCloud::Ptr cloud = image2PointCloud( lastFrame.rgb, lastFrame.depth, camera );//把上一帧图像放在点云里
    
    pcl::visualization::CloudViewer viewer("viewer");

    // 是否显示点云
    bool visualize = pd.getData("visualize_pointcloud")==string("yes");

 //   int min_inliers = atoi( pd.getData("min_inliers").c_str() );
    double max_norm = atof( pd.getData("max_norm").c_str() );

    for ( currIndex=startIndex+1; currIndex<endIndex; currIndex++ )
    {
        cout<<"Reading files "<<currIndex<<endl;//显示第几帧图像
        FRAME currFrame = readFrame( currIndex,pd ); // 读取currFrame当前图像
        computeKeyPointsAndDesp( currFrame);//计算当前图像的特征点
        // 比较currFrame 和 lastFrame
        RESULT_OF_PNP result = estimateMotion( lastFrame, currFrame, camera );
       // if ( result.inliers < min_inliers ) //inliers不够，放弃该帧
        //    continue;
        // 计算运动范围是否太大，如果太大就扔掉这帧图像
        double norm = normofTransform(result.rvec, result.tvec);
        cout<<"norm = "<<norm<<endl;
        if ( norm >= max_norm )
            continue;
        Eigen::Isometry3d T = cvMat2Eigen( result.rvec, result.tvec );//变换矩阵
        cout<<"T="<<T.matrix()<<endl;//输出变换矩阵
        
        //cloud = joinPointCloud( cloud, currFrame, T.inverse(), camera );
        cloud = joinPointCloud( cloud, currFrame, T, camera );
        
        if ( visualize == true )
            viewer.showCloud( cloud );

        lastFrame = currFrame;
        //cv::waitKey(0);
    }

    pcl::io::savePCDFile( "/home/wr/WHR/RGB-D/PART3/CODE/data/result.pcd", *cloud );
    return 0;
}

FRAME readFrame( int index, ParameterReader& pd )
{
    FRAME f;
    string rgbDir   =   pd.getData("rgb_dir");
    string depthDir =   pd.getData("depth_dir");
    
    string rgbExt   =   pd.getData("rgb_extension");
    string depthExt =   pd.getData("depth_extension");

    stringstream ss;
    ss<<rgbDir<<index<<rgbExt;
    string filename;
    ss>>filename;
    f.rgb = cv::imread( filename );

    ss.clear();
    filename.clear();
    ss<<depthDir<<index<<depthExt;
    ss>>filename;

    f.depth = cv::imread( filename, -1 );
    return f;
}

double normofTransform( cv::Mat rvec, cv::Mat tvec )
{
    return fabs(min(cv::norm(rvec), 2*M_PI-cv::norm(rvec)))+ fabs(cv::norm(tvec));
}
