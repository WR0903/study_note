/**
 * @file /include/sailor2/main_window.hpp
 *
 * @brief Qt based gui for sailor2.
 *
 * @date November 2010
 **/
#ifndef sailor2_MAIN_WINDOW_H
#define sailor2_MAIN_WINDOW_H
//#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include <QPushButton>
#include <QWidget>
#include <QImage>
#include <QTimer>
#include <QThread>
#include <QTime>
#include <QFileDialog>
#include <QInputDialog>
#include <QLineEdit>
#include <string>
#include <iostream>
#include <fstream>
#include "uart.hpp"
#include "stm32.hpp"
#include "dataLib.hpp"
#include "QFile"
#include "QDebug"
#include <sstream>

namespace sailor2 {

using namespace std;
using namespace cv;

QImage cvMat2QImage(cv::Mat& mat);
Mat QImage2cvMat(QImage image);
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
        void safe_stop_ahead_back();//avoid damage electric machinery
        void safe_stop_up_down();//avoid damage electric machinery
        void get_slam_pose();
        vector<string> split(string& sailor);
        double stringToDouble(const string& str);
        ~MainWindow();



public Q_SLOTS:
        void timerUpdate();
        void on_open_camera_clicked();
        void readcamera_Frame();
        void writeVideo_Frame();
        void start_check_successful();
        void start_check_faild();
        void pwm_imu_dispay();
        void on_close_camera_clicked();
        void on_pic_camera_clicked();
        void on_shoot_video_clicked();
        void on_stop_video_clicked();
        void on_Tele_Auto_clicked(bool checked);
        void on_Tele_Ahead_clicked();
        void on_Tele_Back_clicked();
        void on_Tele_Right_clicked();
        void on_Tele_Left_clicked();
        void on_Tele_Look_UP_clicked();
        void on_Tele_Stoop_clicked();
        void on_Tele_UP_clicked();
        void on_AUV_START_clicked();
        void on_AUV_STOP_clicked();
        void on_AUV_GOUP_clicked();
        void on_SortPort_Send_clicked();

        void on_Ahead_plus_clicked();
        void on_Ahead_reduce_clicked();
        void on_Back_plus_clicked();
        void on_Back_reduce_clicked();
        void on_Left_plus_clicked();
        void on_Left_reduce_clicked();
        void on_Right_plus_clicked();
        void on_Right_reduce_clicked();
        void on_Tele_DOWN_clicked();
        void on_Down_reduce_clicked();
        void on_Down_plus_clicked();
        void on_Stablilize_Yaw_Send_clicked();
        void on_Yaw_Rate_Send_clicked();
        void on_Depth_Send_clicked();
        void on_Depth_Rate_Send_clicked();
        void on_Target_Position_Send_clicked();
        void on_AUV_Hover_clicked(bool checked);
        void on_AUV_START_clicked(bool checked);
        void on_AUV_Hover_clicked();
        void on_Tele_Auto_clicked();
        void on_AUV_Hover_Stop_clicked();
        void on_Tele_Ahead_clicked(bool checked);

        void on_STM32_Reset_clicked();
        void on_Test_clicked();
        void on_pushButton_clicked();


private:
        Ui::MainWindowDesign ui;
        QTimer    *video_timer;
        QTimer    *camera_timer;
        QImage    camera_image;
        VideoCapture capture;
        VideoWriter createVideo;
        Mat camera_frame;
        bool camera_state;

        string timeStr;
        QString stamp;
        int count;
        //STM32
        STM32 *Stm32;
        QThread Stm32_Thread;
        int Data_class;//use for commend input
	QNode qnode;
Q_SIGNALS:
        void emit_new_pwm();//emit the signals to change the underlying system pwm
        void emit_new_Stablilize_Yaw_PID();//emit the signals to change the underlying system pid
        void emit_new_Yaw_Rate_PID();
        void emit_new_Depth_PID();
        void emit_new_Depth_Rate_PID();
        void emit_new_Target_Position();
        void emit_new_Current_Position();
        void emit_start_PID_Control();
        void emit_stop_PID_Control();
        void emit_STM32_Reset();
        void emit_STM32_Reset_Update_Start();
        void emit_STM32_Reset_Update_Stop();
};

}  // namespace sailor2

#endif // sailor2_MAIN_WINDOW_H
