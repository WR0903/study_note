#include "../include/sailor2/stm32.hpp"
#include "../include/sailor2/commandLib.hpp"
namespace sailor2{
static const double G_TO_MPSS = 9.80665;
unsigned char Commend_Buff[41]={0};//初始化数据包
unsigned char Receive_Buff[41]={0};//初始化数据包
int Receive_Buff_Valid_Pass=0;
STM32::STM32(QObject *parent) : QObject(parent)
{
    Cor_count=0;
    count=0;
    Uart_FD=0;//COM1
    Updata_timer = new QTimer(0);
    Stm32_commend = 0;
    connect(Updata_timer,SIGNAL(timeout()),this,SLOT(updata_data()));
}
STM32::~STM32(void)
{

}
void STM32::update_start()
{
    if(Tx1UartInit_com2(Uart_FD)==0)
   {
       Check_Sign = 1;
   }

//    check imu setting
   if(Check_imu)
   {
       // Load the RTIMULib.ini config file
//        RTIMUSettings *settings = new RTIMUSettings("/home/nvidia/Sailor1/config","RTIMULib.ini");
//         imu = RTIMU::createIMU(settings);
//        if ((imu == NULL) || (imu->IMUType() == RTIMU_TYPE_NULL))
//        {
//            std::cerr<<"No Imu found";
//        }
//        else
//        {
//            // Initialise the imu object
//            imu->IMUInit();

//            // Set the Fusion coefficient
//            imu->setSlerpPower(0.02);
//            // Enable the sensors
//            imu->setGyroEnable(true);
//            imu->setAccelEnable(true);
//            imu->setCompassEnable(true);
//            Check_imu=0;
//        }

   }
// if((Check_Sign==0)&&(Check_imu==0))
   if((Check_Sign==1))//改回0
   {
       Q_EMIT this->check_successful();
       Updata_timer->start(30);
     //  print_timer->start(5000);
   }
   else
   {
       Q_EMIT this->check_faild();
   }
}
//停止更新数据
void STM32::update_stop()
{
    Updata_timer->stop();
}
//更新界面数据显示
void STM32::updata_data()
{
    int nread,nwrite;
    int roll=0;//delay
    unsigned char pwm_buff[8]={0};
    Commend_Buff_Setting(STM32toTX1_PWM_DATA,&pwm_buff[0],0);
    nwrite= write(Uart_FD,Commend_Buff,41);
    while(roll<2000)
    {
      roll++;
    }
    nread=read(Uart_FD,Receive_Buff,41);
    Receive_Buff_Valid();
    if(Receive_Buff_Valid_Pass)
    {
      for(int i=3;i<11;i=i+2)
       {
           int int_buff=0;
           char_to_int(&Receive_Buff[i],&int_buff);
           Motor_PWM_Show[(i-3)/2]=int_buff;
       }
    }
/*//////////////////////////////TX2直接读取IMU数据部分//////////////////*/
//     if (imu->IMURead())
//     {
//         RTIMU_DATA imu_data = imu->getIMUData();
//         RTVector3 quaternion_vec;
//         IMU_L_Acc_c[0]=imu_data.accel.x() * G_TO_MPSS;
//         IMU_L_Acc_c[1]=imu_data.accel.y() * G_TO_MPSS;
//         IMU_L_Acc_c[2]=imu_data.accel.z() * G_TO_MPSS;
//         //angle vel
//         IMU_A_Vel_c[0]=imu_data.gyro.x();
//         IMU_A_Vel_c[1]=imu_data.gyro.y();
//         IMU_A_Vel_c[2]=imu_data.gyro.z();
//         //angle
//         IMU_A_Ang_c[0]=imu_data.fusionQPose.x();
//         IMU_A_Ang_c[1]=imu_data.fusionQPose.y();
//         IMU_A_Ang_c[2]=imu_data.fusionQPose.z();
//         //quaternion to euler
//         imu_data.fusionQPose.toEuler(quaternion_vec);
//         IMU_A_Ang_c[0]=180*quaternion_vec.y()/3.1415926;
//         IMU_A_Ang_c[1]=180*quaternion_vec.x()/3.1415926;
//         IMU_A_Ang_c[2]=180*quaternion_vec.z()/3.1415926;

//     }
     unsigned char imu_buff[36]={0};
     Commend_Buff_Setting(STM32toTX1_IMU_DATA,&imu_buff[0],0);
     nwrite= write(Uart_FD,Commend_Buff,41);
     roll=0;//delay
     while(roll<2000)
     {
         roll++;
     }
     nread=read(Uart_FD,Receive_Buff,41);

     Receive_Buff_Valid();
     if(Receive_Buff_Valid_Pass)
     {

         float IMU_buff[3]={0.0};
         for(int i=0;i<12;i=i+4)
         {
             float float_buff=0.0;
             char_to_float(&Receive_Buff[i+3],&float_buff);
             IMU_buff[i/4]=float_buff;
         }
         IMU_L_Acc[0]=IMU_buff[0]; IMU_L_Acc_c[0]=IMU_L_Acc[0]-IMU_L_Acc_Offset[0];
         IMU_L_Acc[1]=IMU_buff[1]; IMU_L_Acc_c[1]=IMU_L_Acc[1]-IMU_L_Acc_Offset[1];
         IMU_L_Acc[2]=IMU_buff[2]; IMU_L_Acc_c[2]=IMU_L_Acc[2]-IMU_L_Acc_Offset[2];

         IMU_buff[3]={0.0};
         for(int i=12;i<24;i=i+4)
         {
             float float_buff;
             char_to_float(&Receive_Buff[i+3],&float_buff);
             IMU_buff[(i-12)/4]=float_buff;
         }
         IMU_A_Vel[0]=IMU_buff[0]; IMU_A_Vel_c[0]=IMU_A_Vel[0]-IMU_A_Vel_Offset[0];
         IMU_A_Vel[1]=-IMU_buff[1]; IMU_A_Vel_c[1]=IMU_A_Vel[1]-IMU_A_Vel_Offset[1];
         IMU_A_Vel[2]=-IMU_buff[2]; IMU_A_Vel_c[2]=IMU_A_Vel[2]-IMU_A_Vel_Offset[2];

         IMU_buff[3]={0.0};
         for(int i=24;i<36;i=i+4)
         {
             float float_buff;
             char_to_float(&Receive_Buff[i+3],&float_buff);
             IMU_buff[(i-24)/4]=float_buff;
         }
         IMU_A_Ang[0]=IMU_buff[2]; IMU_A_Ang_c[0]=IMU_A_Ang[0]-IMU_A_Ang_Offset[0];
         IMU_A_Ang[1]=IMU_buff[1]; IMU_A_Ang_c[1]=IMU_A_Ang[1]-IMU_A_Ang_Offset[1];
         IMU_A_Ang[2]=IMU_buff[0]; IMU_A_Ang_c[2]=IMU_A_Ang[2]-IMU_A_Ang_Offset[2];
     }
     unsigned char water_buff[8]={0};
     Commend_Buff_Setting(STM32toTX1_WATER_DATA,&water_buff[0],0);
     nwrite= write(Uart_FD,Commend_Buff,41);
     roll=0;//delay
     nread=read(Uart_FD,Receive_Buff,41);
     Receive_Buff_Valid();
     if(Receive_Buff_Valid_Pass)
     {

         float Water_buff[2]={0};
         for(int i=0;i<8;i=i+4)
         {
             float float_buff;
             char_to_float(&Receive_Buff[i+3],&float_buff);
             Water_buff[i/4]=float_buff;
         }
         Water_Deep=Water_buff[0]; Water_Deep_c=Water_Deep-Water_Deep_Offset;
         Water_Temperature=Water_buff[1];
     }
     count++;
     Q_EMIT this->display_update();
}
//改变PWM数值
void STM32::change_pwm()
{
    int nwrite,nread;
    unsigned char commend = TX1toSTM32_PWM_DATA;
    unsigned char pwm_buff[8]={0};

    for(int i=0;i<4;i++)
    {
        Motor_PWM_Control[i];
        int_to_char(Motor_PWM_Control[i],&pwm_buff[2*i]);
    }

    Commend_Buff_Setting(commend,&pwm_buff[0],8);
    nwrite= write(Uart_FD,Commend_Buff,41);
}
//改变航向角PID
void STM32::change_Stablilize_Yaw_PID()
{
    int nwrite;
    unsigned char commend = TX1toSTM32_Stabilize_Yaw_PID_KpKiKd_DATA;
    unsigned char PID_buff[12]={0};
   float_to_char(Stablilize_Yaw_PID_Input_Buff[0],&PID_buff[0]);//有问题
   float_to_char(Stablilize_Yaw_PID_Input_Buff[1],&PID_buff[4]);//有问题
   float_to_char(Stablilize_Yaw_PID_Input_Buff[2],&PID_buff[8]);//有问题
   Commend_Buff_Setting(commend,&PID_buff[0],12);
   nwrite= write(Uart_FD,Commend_Buff,41);
}
//改变航向角速度PID
void STM32::change_Yaw_Rate_PID()
 {
    int nwrite;
    u_int8_t commend = TX1toSTM32_Yaw_Rate_PID_KpKiKd_DATA;
    unsigned char PID_buff[12]={0};
   float_to_char(Yaw_Rate_PID_Input_Buff[0],&PID_buff[0]);//有问题
   float_to_char(Yaw_Rate_PID_Input_Buff[1],&PID_buff[4]);//有问题
   float_to_char(Yaw_Rate_PID_Input_Buff[2],&PID_buff[8]);//有问题
   Commend_Buff_Setting(commend,&PID_buff[0],12);
   nwrite= write(Uart_FD,Commend_Buff,41);
}
//改变深度PID的值
void STM32::change_Depth_PID()
 {
    int nwrite;
    u_int8_t commend = TX1toSTM32_Depth_PID_KpKiKd_DATA;
    unsigned char PID_buff[12]={0};
    float_to_char(Depth_PID_Input_Buff[0],&PID_buff[0]);//有问题
    float_to_char(Depth_PID_Input_Buff[1],&PID_buff[4]);//有问题
    float_to_char(Depth_PID_Input_Buff[2],&PID_buff[8]);//有问题
    Commend_Buff_Setting(commend,&PID_buff[0],12);
    nwrite= write(Uart_FD,Commend_Buff,41);
}
//启动PID控制
void STM32::start_PID_Control()
{
    int nwrite;
    u_int8_t commend = TX2toSTM32_start_PID_Control;
    unsigned char PID_buff[12]={0};
    Commend_Buff_Setting(commend,&PID_buff[0],12);
    nwrite= write(Uart_FD,Commend_Buff,41);
}
//停止PID控制
void STM32::stop_PID_Control()
{
    int nwrite;
    u_int8_t commend = TX2toSTM32_stop_PID_Control;
    unsigned char PID_buff[12]={0};
    Commend_Buff_Setting(commend,&PID_buff[0],12);
    nwrite= write(Uart_FD,Commend_Buff,41);
}
//改变深度加速度PID
void STM32::change_Depth_Rate_PID()
 {
    int nwrite;
    u_int8_t commend = TX1toSTM32_Depth_Acclerate_Rate_PID_KpKiKd_DATA;
    unsigned char PID_buff[12]={0};
    float_to_char(Depth_Rate_PID_Input_Buff[0],&PID_buff[0]);//有问题
    float_to_char(Depth_Rate_PID_Input_Buff[1],&PID_buff[4]);//有问题
    float_to_char(Depth_Rate_PID_Input_Buff[2],&PID_buff[8]);//有问题
    Commend_Buff_Setting(commend,&PID_buff[0],12);
    nwrite= write(Uart_FD,Commend_Buff,41);
}
void STM32::imu_data_correction()
{}
void STM32::imu_data_correction_process()
{}
//向STM32发送目标位置
void STM32::change_Target_Position()
{
    int nwrite;
    u_int8_t commend =TX1toSTM32_Taeget_Positioin_DATA;
    unsigned char Position_buff[24]={0};
    float_to_char(Target_Position_Buff[0],&Position_buff[0]);//
    float_to_char(Target_Position_Buff[1],&Position_buff[4]);//
    float_to_char(Target_Position_Buff[2],&Position_buff[8]);//
    float_to_char(Target_Position_Buff[3],&Position_buff[12]);//
    float_to_char(Target_Position_Buff[4],&Position_buff[16]);//
    float_to_char(Target_Position_Buff[5],&Position_buff[20]);//
    Commend_Buff_Setting(commend,&Position_buff[0],24);
    nwrite= write(Uart_FD,Commend_Buff,41);
}
//向stm32发送当前位置
void STM32::change_Current_Position()
{
    int nwrite;
    u_int8_t commend =  TX1toSTM32_Current_Positioin_DATA;
    unsigned char Position_buff[24]={0};
    float_to_char(Current_Position_Buff[0],&Position_buff[0]);//
    float_to_char(Current_Position_Buff[1],&Position_buff[4]);//
   // float_to_char(Current_Position_Buff[2],&Position_buff[8]);//
    float_to_char(Water_Deep,&Position_buff[8]);//
    float_to_char(Current_Position_Buff[3],&Position_buff[12]);//
    float_to_char(Current_Position_Buff[4],&Position_buff[16]);//
    float_to_char(Current_Position_Buff[5],&Position_buff[20]);//
    Commend_Buff_Setting(commend,&Position_buff[0],24);
    nwrite= write(Uart_FD,Commend_Buff,41);
}
//标准化通信数据包
void STM32::Commend_Buff_Setting(unsigned char Send_Commend,unsigned char *Data,int num)
{
    Commend_Buff[0]=Data_Send_Start ;
    Commend_Buff[40]=Data_Send_Stop ;
    Commend_Buff[1]=Send_Commend ;
    int_to_char(num,&Commend_Buff[2]);
    unsigned char Data_Valid=NO_Data;
    if(num>0)
    {
        for(int i=0;i<num;i++)
        {

            Commend_Buff[i+3]=*(Data+i);
        }
    }
     Commend_Buff[39]=Data_Valid;
}
//校验数据包准确性
void STM32::Receive_Buff_Valid(void)
{
    Receive_Buff_Valid_Pass= 0;
   if((Receive_Buff[0]==Data_Receive_Start)&&(Receive_Buff[40]==Data_Receive_Stop))
   {
        Receive_Buff_Valid_Pass= 1;
   }
   else
   {
      Receive_Buff_Valid_Pass= 0;
   }


}
/*/////////////////////还未写完/////////////////////////*/
void STM32::count_print(void)
{

}
}
