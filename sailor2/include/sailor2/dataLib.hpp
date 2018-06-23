#ifndef DATALIB_H
#define DATALIB_H


#include <qdatetime.h>
#include <QDateTime>
#include <iostream>
#include <QTimer>
#include <string>
#include <QPoint>
#include <opencv2/opencv.hpp>

namespace sailor2 {
using namespace std;


//string class_1;
struct boundingBoxs
{
    string class_1;
    double probability_1;
    int x_min;
    int y_min;
    int x_max;
    int y_max;
};

extern int state;
//stri

extern int Check_Sign;
extern int Check_imu;
extern cv::Mat im_raw;
extern boundingBoxs dec_box;
extern double Visual_Traslation_Matrix[16];
extern double Visual_Eular[3];
extern double Visual_Position[3];
extern double TimeStamp;
extern int Visual_ID;

extern float Water_Temperature;
extern float Water_Deep;
extern float Water_Deep_Offset;
extern float Water_Deep_c;


extern float IMU_L_Acc[3];//linear acceleration
extern float IMU_L_Vel[3];//linear velocity
extern float IMU_L_Dis[3];//linear displacement
extern float IMU_A_Acc[3];
extern float IMU_A_Vel[3];
extern float IMU_A_Ang[3];

//绘图角度缓存
extern double Plot_Angle_time[300];
extern double Plot_Angle_X_buff[300];
extern double Plot_Angle_Y_buff[300];
extern double Plot_Angle_Z_buff[300];

//绘图温度深度缓存
extern double Plot_Water_time[300];
extern double Plot_Water_Temperature_buff[300];
extern double Plot_Water_Deep_buff[300];


extern float IMU_L_Acc_Offset[3];
extern float IMU_A_Vel_Offset[3];
extern float IMU_A_Ang_Offset[3];
extern float IMU_DATA_PACKAGE[500][9];

extern float IMU_L_Acc_c[3];//linear acceleration after correction
extern float IMU_L_Vel_c[3];//linear velocity after correction
extern float IMU_L_Dis_c[3];//linear displacement after correction
extern float IMU_A_Acc_c[3];
extern float IMU_A_Vel_c[3];
extern float IMU_A_Ang_c[3];



extern double  Data_acc[3];
extern double  Data_vel[3];
extern double Data_dis[3];
extern double Data_dis_world[3];
extern double Data_eul[3];


extern int Motor_PWM_Show[4];
extern int Motor_PWM_Control[4];
extern int Motor_PWM_ADD;

//PICTURE PARAMETERES
extern int Code_ID;
extern int Taget_ID;

//TAGET PATAMETERS
extern double Taget_1[6];


//AUV PARAMETERS
extern double AUV_L1;
extern double AUV_L2;
extern double AUV_L3;
extern double AUV_L4;
extern double AUV_fG;
extern double AUV_fb;

extern double PID_ADD_0;
extern double PID_ADD_1;


extern float Stablilize_Yaw_PID_Input_Buff[3];
extern float Yaw_Rate_PID_Input_Buff[3];
extern float Depth_PID_Input_Buff[3];
extern float Depth_Rate_PID_Input_Buff[3];
extern float Target_Position_Buff[6];
extern float Current_Position_Buff[6];

void float_to_char(float f,unsigned char *sailor);

void int_to_char(int t,unsigned char *sailor);

void char_to_float(unsigned char *sailor, float* f);

void char_to_int(unsigned char *sailor,int *t);

}

#endif // DATALIB_H
