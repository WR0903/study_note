#include"CameraCalibration.h"
#include"StereoMatch.h"
#include<iostream>
#include <iomanip>
#include<ctime>
#include <sstream>
Mat pointClouds;
static void onMouse(int event, int x, int y, int /*flags*/, void* /*param*/);
enum { BM, SGBM };
int main() {
	int APPROACH;
	StereoCalib sc;
	StereoMatch sm;
	StereoCalib::CornerDatas cornerDatas[2];
	StereoCalib::CameraParams cameraParams[2];
	StereoCalib::StereoParams stereoParams;
	StereoCalib::RemapMatrixs remapMatrixs, remapMatrixs_left, remapMatrixs_right;
//	VideoCapture cam, cam_left, cam_right;
	Mat frame, empty, im_left, im_right, disparity, match_left, match_right, im_disparity,depth;
    std::vector<std::string> filelist_left;//存放左眼相机的文件名称
    std::vector<std::string> filelist_right;//存放右眼相机的文件名称

    // generate list of chessboard image filename

    for (int i=0; i<19; i++)//for循环用来存放所有图像的名称
    {
        std::stringstream str_l,str_r;
        ///home/wr/WHR/StereoCamera-master/new
        str_l << "/home/wr/WHR/StereoCamera-master/new/HD/HD_L/HDleft" << std::setw(3) << std::setfill('0') << i << ".png";
        str_r << "/home/wr/WHR/StereoCamera-master/new/HD/HD_R/HDright" << std::setw(3) << std::setfill('0') << i << ".png";
        std::cout << str_l.str() << std::endl;
        std::cout << str_r.str() << std::endl;
        filelist_left.push_back(str_l.str());
        filelist_right.push_back(str_r.str());
    }
		bool first = true;
		int imageCount = 0;
		int chessborad_num, cols, rows, width;

    for(int i=0;i<filelist_left.size();i++)
    {
        im_left=imread(filelist_left[i]);
        im_right=imread(filelist_right[i]);
        if(im_left.empty()||im_right.empty())
            continue;
        sc.initCornerData(19, im_left.size(), /*Size(cols, rows)*/Size(8,11), /*width*/15, cornerDatas[0]);
        sc.initCornerData(19, im_right.size(), /*Size(cols, rows)*/Size(8,11), /*width*/15, cornerDatas[1]);
        int success = sc.detectCorners(im_left, im_right, cornerDatas[0], imageCount);//这个就是左右眼的参数了,不需要检测2次,因为后面也是将cornerDatas[1]复制到cornerDatas[0]
        //int success2 = sc.detectCorners(im_right, im_right, cornerDatas[1], imageCount);
        imshow("Findchessboardcorners_left", im_left);
        imshow("Findchessboardcorners_right", im_right);
        if (success) {
                        imageCount++;
                        if (imageCount == chessborad_num)break;

                    }
        waitKey(200);
    }
    sc.saveCornerData("/home/wr/WHR/StereoCamera-master/new/HD/cornerdata.yml", cornerDatas[0]);
    //双目定标
      sc.loadCornerData("/home/wr/WHR/StereoCamera-master/new/HD/cornerdata.yml", cornerDatas[0]);
//    sc.loadCornerData("/home/lumino/hitlumino/tailimage/HD/cornerdata_right.yml", cornerDatas[1]);
//    cornerDatas[0].imagePoints2 = cornerDatas[1].imagePoints1;
    sc.calibrateStereoCamera(cornerDatas[0], stereoParams, true);
    //双目矫正
    sc.rectifyStereoCamera(cornerDatas[0], stereoParams, remapMatrixs, StereoCalib::RECTIFY_BOUGUET);
    //sc.saveCalibrationDatas("/home/lumino/hitlumino/tailimage/HD/calibrationdatas.yml", StereoCalib::RECTIFY_BOUGUET, cornerDatas[0], stereoParams, remapMatrixs);
    sc.saveCalibrationDatas("/home/wr/WHR/StereoCamera-master/new/HD/calibrationdatas.yml", StereoCalib::RECTIFY_BOUGUET, cornerDatas[0], stereoParams, remapMatrixs);
    //误差分析
    double err;
    sc.getStereoCalibrateError(cornerDatas[0],stereoParams,err);
    cout<<"error :  "<<err<<endl;
    //图片矫正
    for(int i=0;i<filelist_left.size();i++)
    {
        std::stringstream str_l,str_r;
        str_l << "/home/wr/WHR/StereoCamera-master/new/HD/undist_left/unleft" << std::setw(3) << std::setfill('0') << i << ".png";
        str_r << "/home/wr/WHR/StereoCamera-master/new/HD/undist_right/unright" << std::setw(3) << std::setfill('0') << i << ".png";
//        str_l << "/home/lumino/hitlumino/tailimage/air_calibration_datas/undist_left/unleft" << std::setw(3) << std::setfill('0') << i << ".png";
//        str_r << "/home/lumino/hitlumino/tailimage/air_calibration_datas/undist_right/unright" << std::setw(3) << std::setfill('0') << i << ".png";
        Mat undis_left,undis_right;
        im_left=imread(filelist_left[i]);
        im_right=imread(filelist_right[i]);
        sc.remapImage(im_left, im_right, undis_left, undis_right, remapMatrixs);
        imwrite(str_l.str(),undis_left);
        imwrite(str_r.str(),undis_right);
    }
    std::cout<<"calib has been saved in /home/lumino/hitlumino/tailimage/HD"<<std::endl;

//    cout << "选择双目匹配算法：0-BM 1-SGBM 2-VAR :";
//    //cin >> APPROACH;
//    APPROACH=0;
//    for(int i=0;i<filelist_left.size();i++)
//    {
//        im_left=imread(filelist_left[i]);
//        im_right=imread(filelist_right[i]);
//        double minVal, maxVal;

//        if(im_left.empty()||im_right.empty()){
//            break;
//        }
//        resize(im_left, im_left, Size(1280,720));
//        resize(im_right, im_right, Size(1280,720));
//        clock_t start=clock();
//        if(im_left.empty()||im_right.empty())
//            continue;
//        sc.remapImage(im_left, im_right, im_left, im_right, remapMatrixs);
//        imshow("Rectified_left", im_left);
//        imshow("Rectified_right", im_right);
//        //计算视差
//        if (APPROACH == BM) {
//            //int SADWindowSize = 9;
//            //int numberOfDisparities = 16 * 8; /**< Range of disparity */
//            //numberOfDisparities = numberOfDisparities > 0 ? numberOfDisparities : ((im_left.cols / 8) + 15) & -16;
//            sm.m_BM->setROI1(remapMatrixs.roi1);//左右视图的有效像素区域，一般由双目校正阶段的 cvStereoRectify 函数传递，也可以自行设定。
//            sm.m_BM->setROI2(remapMatrixs.roi2);//一旦在状态参数中设定了 roi1 和 roi2，OpenCV 会通过cvGetValidDisparityROI 函数计算出视差图的有效区域，在有效区域外的视差值将被清零。
//            sm.m_BM->setPreFilterSize(15); //预处理滤波器窗口大小,5-21,odd
//            sm.m_BM->setPreFilterCap(31); //63,1-31//预处理滤波器的截断值，预处理的输出值仅保留[-preFilterCap, preFilterCap]范围内的值,
//            sm.m_BM->setBlockSize(19);  //SAD窗口大小5-21
//            sm.m_BM->setMinDisparity(0); //64 最小视差，默认值为 0
//            sm.m_BM->setNumDisparities(64);//48; //128视差窗口，即最大视差值与最小视差值之差, 窗口大小必须是 16 的整数倍
//            sm.m_BM->setTextureThreshold(10); //低纹理区域的判断阈值。如果当前SAD窗口内所有邻居像素点的x导数绝对值之和小于指定阈值，则该窗口对应的像素点的视差值为 0
//            sm.m_BM->setUniquenessRatio(5);  //5-15 视差唯一性百分比， 视差窗口范围内最低代价是次低代价的(1 + uniquenessRatio/100)倍时，最低代价对应的视差值才是该像素点的视差，否则该像素点的视差为 0
//            sm.m_BM->setSpeckleWindowSize(100);  //检查视差连通区域变化度的窗口大小, 值为 0 时取消 speckle 检查
//            sm.m_BM->setSpeckleRange(32);  //视差变化阈值，当窗口内视差变化大于阈值时，该窗口内的视差清零
//            sm.m_BM->setDisp12MaxDiff(1); //左视差图（直接计算得出）和右视差图（通过cvValidateDisparity计算得出）之间的最大容许差异。超过该阈值的视差值将被清零。该参数默认为 -1，即不执行左右视差检查。
//                                        //注意在程序调试阶段最好保持该值为 -1，以便查看不同视差窗口生成的视差效果。

//                                        // 计算视差*/
//            sm.bmMatch(im_left, im_right, disparity,match_left,match_right);
//            //-- Check its extreme values
//            minMaxLoc(disparity, &minVal, &maxVal);
//            cout << "Min disp: Max value" << minVal << maxVal; //numberOfDisparities.= (maxVal - minVal)

//                                                               //-- 4. Display it as a CV_8UC1 image
//            disparity.convertTo(disparity, CV_8U, 255 / (maxVal - minVal));//(numberOfDisparities*16.)
//            normalize(disparity, disparity, 0, 255, CV_MINMAX, CV_8UC1);    // obtain normalized image
//            GaussianBlur(disparity, disparity, Size(3, 3), 0);
//            imshow("disparity", disparity);
//        }
//		else if (APPROACH == SGBM) {
//			sm.m_SGBM.preFilterCap = 63;
//			int cn = 3;
//			sm.m_SGBM.SADWindowSize = 9;
//			sm.m_SGBM.P1 = 8 * cn*sm.m_SGBM.SADWindowSize*sm.m_SGBM.SADWindowSize;
//			sm.m_SGBM.P2 = 32 * cn*sm.m_SGBM.SADWindowSize*sm.m_SGBM.SADWindowSize;
//			sm.m_SGBM.minDisparity = 0;
//			sm.m_SGBM.numberOfDisparities = ((640 / 8) + 15) & -16;//32;
//			sm.m_SGBM.uniquenessRatio = 10;
//			sm.m_SGBM.speckleWindowSize = 100;
//			sm.m_SGBM.speckleRange = 32;
//			sm.m_SGBM.disp12MaxDiff = 1;
//			sm.m_SGBM.fullDP = 0;
//			sm.sgbmMatch(im_left, im_right, disparity, match_left, match_right);
//			//disparity.convertTo()
//			//-- Check its extreme values
//			//cv::minMaxLoc(disparity, &minVal, &maxVal);
//			//cout << "Min disp: Max value" << minVal << maxVal; //numberOfDisparities.= (maxVal - minVal)

//			//-- 4. Display it as a CV_8UC1 image
//			//disparity.convertTo(disparity, CV_8U, 255 / (maxVal - minVal));//(numberOfDisparities*16.)
//			//cv::normalize(disparity, disparity, 0, 255, CV_MINMAX, CV_8UC1);    // obtain normalized image
//			//imshow("disparity", disparity);
//		}

//        //GaussianBlur(disparity, disparity, Size(11, 11), 0);
//        sm.getPointClouds(disparity, pointClouds);
//        //Mat topDownview;
//        //sm.getTopDownView(pointClouds, topDownview);
//        //sm.savePointClouds(pointClouds, "pointclouds.txt");
//        sm.getDisparityImage(disparity, im_disparity,false);
//        //获取深度
//        double max_z = 1.8e4;
//        for (int y = 0; y < pointClouds.rows; y++)
//        {
//            for (int x = 0; x < pointClouds.cols; x++)
//            {
//                cv::Vec3f point = pointClouds.at<cv::Vec3f>(y, x);
//                if (fabs(point[2] - max_z) < FLT_EPSILON || point[2] > max_z || point[2]<0)
//                    point[2]=0;
//            }
//        }
//        vector<Mat> pos;
//        split(pointClouds,pos);
//        pos[2].convertTo(depth,CV_8U,255.0/1.8e4);
//        imshow("Match_left", match_left);
//        imshow("Match_right", match_right);
//        imshow("disparity", im_disparity);
//        imshow("depth",depth);
//        //imshow("topdownview", topDownview);
//        //imshow("pointclouds", pointClouds);
//        clock_t end=clock();
//        cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
//        if (waitKey(1) == 27){
//            sm.savePointClouds(pointClouds, "/Users/lrg/Stereo/Stereo/pointclouds.txt");
//            waitKey();
//        }
//    }
	return 0;
}
static void onMouse(int event, int x, int y, int /*flags*/, void* /*param*/) {

	if (event == CV_EVENT_LBUTTONDOWN)
	{
		/*// 根据深度阈值进行二值化处理
		double maxVal = 0, minVal = 0;
		cv::Mat depth2 = cv::Mat::zeros(depth.rows, depth.cols, CV_8UC1);
		cv::minMaxLoc(depth, &minVal, &maxVal);
		//double thrVal = minVal * 1.5;
		//threshold(depth, depthThresh, thrVal, 255, CV_THRESH_BINARY_INV);
		//depthThresh.convertTo(depthThresh, CV_8UC1);
		depth2.convertTo(depth2, CV_8U, 255 / (maxVal - minVal));//(numberOfDisparities*16.)
		normalize(depth2, depth2, 0, 255, CV_MINMAX, CV_8UC1);    // obtain normalized image*/
		cv::Vec3f point = pointClouds.at<cv::Vec3f>(y, x);
		cout << "("<< x << "," << y << ") distance:" << point[2] << endl;
	}
}
