#include "../include/sailor2/dataLib.hpp"

#include <qdatetime.h>
#include <QDateTime>

#include <QTimer>
//#include <string>
#include <QPoint>

namespace sailor2 {
int state=1;
cv::Mat im_raw;
boundingBoxs dec_box;
int Check_Sign=0;
int Check_imu=1;

double Visual_Traslation_Matrix[16]={0};
double Visual_Eular[3]={0};
double Visual_Position[3]={0};
double TimeStamp=0.0;
int Visual_ID = 0;

float Water_Temperature = 0;
float Water_Deep = 0;
float Water_Deep_Offset=0;
float Water_Deep_c=0;
//绘图Deep Temp缓存
double Plot_Water_time[300]={0};
double Plot_Water_Temperature_buff[300]={0};
double Plot_Water_Deep_buff[300]={0};


float IMU_L_Acc[3]={0};
float IMU_L_Vel[3]={0};
float IMU_L_Dis[3]={0};
float IMU_A_Acc[3]={0};
float IMU_A_Vel[3]={0};
float IMU_A_Ang[3]={0};

//绘图角度缓存
double Plot_Angle_X_buff[300]={0};
double Plot_Angle_Y_buff[300]={0};
double Plot_Angle_Z_buff[300]={0};
double Plot_Angle_time[300]={0};

float IMU_L_Acc_Offset[3]={0};
float IMU_A_Vel_Offset[3]={0};
float IMU_A_Ang_Offset[3]={0};
float IMU_DATA_PACKAGE[500][9]={0};

float IMU_L_Acc_c[3]={0};
float IMU_L_Vel_c[3]={0};
float IMU_L_Dis_c[3]={0};
float IMU_A_Acc_c[3]={0};
float IMU_A_Vel_c[3]={0};
float IMU_A_Ang_c[3]={0};


double Data_acc[3]={0};
double Data_vel[3]={0};
double Data_dis[3] = {0};//the end of displacement data
double Data_eul[3] = {0};//tne end of eular angle data


int Motor_PWM_Show[4]={0};
int Motor_PWM_Control[4]={0};
int Motor_PWM_ADD=1;
int Motor_PWM_Control_hover[4]={0};


int Code_ID=0;
int Taget_ID=0;

double Taget_1[6]={900,0,0,0,0,0};

double AUV_L1=0.071;
double AUV_L2=0.071;
double AUV_L3=0.150;
double AUV_L4=0.020;
double AUV_fG=140;
double AUV_fb=141;

double PID_ADD_0=0;
double PID_ADD_1=0;


/*////向底层设置PID的值////*/
float Stablilize_Yaw_PID_Input_Buff[3]={0};
float Yaw_Rate_PID_Input_Buff[3]={0};
float Depth_PID_Input_Buff[3]={0};
float Depth_Rate_PID_Input_Buff[3]={0};
float Target_Position_Buff[6]={0};
float Current_Position_Buff[6]={0};




void float_to_char(float f,unsigned char *sailor)
{
    union change
    {
        float d;
        unsigned char dat[4];
    }r1;
    r1.d = f;
    *sailor = r1.dat[0];
    *(sailor+1) = r1.dat[1];
    *(sailor+2) = r1.dat[2];
    *(sailor+3) = r1.dat[3];
}

void  int_to_char(int t,unsigned char *sailor)
{
    *sailor = t >>8;
    *(sailor+1) = t;
}

void char_to_float(unsigned char *sailor, float* f)
{
    union change
    {
        float d;
        unsigned char dat[4];
    }r1;
    r1.dat[0] = *sailor;
    r1.dat[1] = *(sailor+1);
    r1.dat[2] = *(sailor+2);
    r1.dat[3] = *(sailor+3);
    *f=r1.d;
}
void char_to_int(unsigned char *sailor,int *t)
{
    *t = *(sailor+1);
    *t |= *sailor <<8;
}
}
