/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include <ros/ros.h>
#include "../include/sailor2/main_window.hpp"
#include <string>
/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace sailor2 {
static int current_index;
QString pose_str;
using namespace Qt;
//string a;
/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
    ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    this->get_slam_pose();//获取slam位姿
    camera_timer   = new QTimer(this);//相机定时器
    video_timer   = new QTimer(this);//录像定时器
    Stm32 = new STM32();
    Data_class=0;
    ui.textEdit->append(tr("Shark"));
    ui.textEdit->append(tr("Please push the System Check button to start Shark control"));
    ui.Control_groupBox->setEnabled(false);
    ui.Telecontrol_Module->setEnabled(false);
    ui.Control_Module->setEnabled(false);
    ui.Visual_groupBox->setEnabled(false);
    ui.videoRecordState->setStyleSheet("background:transparent");
    ui.videoRecordState->setVisible(false);
    //界面时间更新
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));

    timer->start(1000);
    connect(camera_timer, SIGNAL(timeout()), this, SLOT(readcamera_Frame()));//该槽函数就是显示图片，并把slam的位姿显示在界面上

   // 更新当前位置
    connect(camera_timer, SIGNAL(timeout()), Stm32,SLOT(change_Current_Position()));
    //自动写视频
    connect(video_timer, SIGNAL(timeout()), this, SLOT(writeVideo_Frame()));
    //new a STM32 thread
    Stm32_Thread.start(QThread::HighestPriority);
    Stm32->moveToThread(&Stm32_Thread);
    Stm32->Updata_timer->moveToThread(&Stm32_Thread);
  //  Stm32->Imu_Data_Correction_timer->moveToThread(&Stm32_Thread);
    connect(ui.Start_Check,SIGNAL(clicked()),Stm32,SLOT(update_start()));
    //STM32 check
    connect(Stm32,SIGNAL(check_successful()),this,SLOT(start_check_successful()));
    connect(Stm32,SIGNAL(check_faild()),this,SLOT(start_check_faild()));
    //update IMU and PWM display
    connect(Stm32,SIGNAL(display_update()),this,SLOT(pwm_imu_dispay()));
    //manual input pwm
    connect(this,SIGNAL(emit_new_pwm()),Stm32,SLOT(change_pwm()));

    //
    connect(this,SIGNAL(emit_new_Current_Position()),Stm32,SLOT(change_Current_Position()));
    //manual Stabalize_Yaw_Pid_Confiig/////////////pengjun1.18/////////////////
    connect(this,SIGNAL(emit_new_Stablilize_Yaw_PID()),Stm32,SLOT(change_Stablilize_Yaw_PID()));
    connect(this,SIGNAL(emit_new_Yaw_Rate_PID()),Stm32,SLOT(change_Yaw_Rate_PID()));
    connect(this,SIGNAL(emit_new_Depth_PID()),Stm32,SLOT(change_Depth_PID()));
    connect(this,SIGNAL(emit_new_Depth_Rate_PID()),Stm32,SLOT(change_Depth_Rate_PID()));
    connect(this,SIGNAL(emit_new_Target_Position()),Stm32,SLOT(change_Target_Position()));
    connect(this,SIGNAL(emit_start_PID_Control()),Stm32,SLOT(start_PID_Control()));
    connect(this,SIGNAL(emit_stop_PID_Control()),Stm32,SLOT(stop_PID_Control()));
    //Reset STM32
    //connect(ui.STM32_Reset,SIGNAL(clicked()),Stm32,SLOT(STM32_Reset()));
    //connect(this,SIGNAL(emit_STM32_Reset_Update_Start()),Stm32,SLOT(update_start()));
    //connect(this,SIGNAL(emit_STM32_Reset_Update_Stop()),Stm32,SLOT(update_stop()));
    //Remote control
    ui.Start_Check->setShortcut(Qt::Key_0);  //check
    ui.open_camera->setShortcut(Qt::Key_1);   //open camera
    ui.Visual_Sign->setShortcut(Qt::Key_2);   //camera pose
    ui.AUV_Hover->setShortcut(Qt::Key_3);     //start hover
    ui.Data_Fusion->setShortcut(Qt::Key_5);    //data fusion
    ui.File->setShortcut(Qt::Key_6);
    ui.Setting->setShortcut(Qt::Key_7);
    ui.Help->setShortcut(Qt::Key_9); //hua yuan
    ui.Test->setShortcut(Qt::Key_8);
    ui.pic_camera->setShortcut(Qt::Key_F);    //take picture
    ui.shoot_video->setShortcut(Qt::Key_R);    //take video
    ui.stop_video->setShortcut(Qt::Key_C);     //stop video
    ui.AUV_STOP->setShortcut(Qt::Key_Space);   //AUV stop
    ui.Tele_Ahead->setShortcut(Qt::Key_Up);  //qian jin
    ui.Ahead_plus->setShortcut(Qt::Key_W);    //qian jin jia su
    ui.Ahead_reduce->setShortcut(Qt::Key_S);  //qian jin jian su
    ui.Tele_Back->setShortcut(Qt::Key_Down);  //dao tui
    ui.Tele_Left->setShortcut(Qt::Key_Left); //zuo zhuan
    ui.Left_plus->setShortcut(Qt::Key_A);  //zuo zhuan jia su
    ui.Left_reduce->setShortcut(Qt::Key_D); //zuo zhuan jian su
    ui.Tele_Right->setShortcut(Qt::Key_Right); //you zhuan
    ui.Tele_UP->setShortcut(Qt::Key_Q);  // shang fu
    ui.Tele_DOWN->setShortcut(Qt::Key_Z); //xia chen
    ui.Down_plus->setShortcut(Qt::Key_X);  //xia chen jia su
    ui.Down_reduce->setShortcut(Qt::Key_E); //xia chen jian su

    ui.IMU_Upaate_Sign->setShortcut(Qt::Key_I); // IMU_update_sign
    ui.STM32_Reset->setShortcut(Qt::Key_O); //data_correction
    ui.AUV_START->setShortcut(Qt::Key_F1);
    ui.AUV_STOP->setShortcut(Qt::Key_F2);
}

MainWindow::~MainWindow() {}
//Mat转换成Qimage

void MainWindow::safe_stop_ahead_back()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[0]=888;
    Motor_PWM_Control[1]=888;
    Q_EMIT this->emit_new_pwm();
    usleep(500000);//500ms
}

double stringToDouble(const string& str){
    istringstream iss(str);
    double num;
    iss >> num;
    return num;
}

vector<string> split(string& sailor)//根据空格划分
{
    vector<string> pose;
    size_t last = 0;
    size_t index = sailor.find_first_of(" ",last);
    while(index != string::npos)
    {
        pose.push_back(sailor.substr(last,index-last));
        last= index+1;
        index = sailor.find_first_of(" ",last);
    }
    if(index-last > 0)
    {
        pose.push_back(sailor.substr(last,index-last));
    }
    return pose;
}
void* thread1(void *ptr)
{
    ros::Rate loop_rate(30);
    int count = 0;
    while ( ros::ok() ) {
        //std::cout<<"1"<<std::endl;
        //cv::imshow("")

        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    //return 0;
}

void MainWindow::get_slam_pose()
{
    current_index=1;
    pthread_t id;
    int ret;
    ret=pthread_create(&id,NULL,thread1,NULL);
    if(ret)
    {
        cout<<"thread error!"<<endl;
        return ;
    }
    //pthread_join(id,NULL);
}

void MainWindow::pwm_imu_dispay()
{
    //ui.IMU_Upaate_Sign->isChecked()
    if(ui.IMU_Upaate_Sign->isChecked())
    {
        ui.IMU_A_Ang_X->setText(QString::number(IMU_A_Ang_c[0]));//(Data_vel[0]));
        ui.IMU_A_Ang_Y->setText(QString::number(IMU_A_Ang_c[1]));//(Data_vel[1]));
        ui.IMU_A_Ang_Z->setText(QString::number(IMU_A_Ang_c[2]));//(Data_vel[2]));
        ui.IMU_L_Acc_X->setText(QString::number(IMU_L_Acc_c[0]));//(Data_acc[0]));
        ui.IMU_L_Acc_Y->setText(QString::number(IMU_L_Acc_c[1]));//(Data_acc[1]));
        ui.IMU_L_Acc_Z->setText(QString::number(IMU_L_Acc_c[2]));//(Data_acc[2]));
        ui.IMU_A_Vel_X->setText(QString::number(IMU_A_Vel_c[0]));//(Data_dis[0]));
        ui.IMU_A_Vel_Y->setText(QString::number(IMU_A_Vel_c[1]));//(Data_dis[1]));
        ui.IMU_A_Vel_Z->setText(QString::number(IMU_A_Vel_c[2]));//(Data_dis[2]));
        //plot the Angle change picture
       //Angle_Plot();/////////////////////////////////////////////////////////////////////

        if(ui.IMU_Rec->isChecked())
        {
            int i;
            fstream imu_file("/home/nvidia/Desktop/imu_rec.txt",ios::out|ios::app);
            if(!imu_file.is_open())
            {
                ui.textEdit->append("The imu_file open is failed");
            }
            for(i=0;i<3;i++)
            {
                imu_file<<IMU_A_Ang_c[i]<<" ";
            }
            imu_file<<"\n";
            imu_file.close();
        }


   }
    ui.Motor_PWM_0->setText(QString::number( Motor_PWM_Show[0]));
    ui.Motor_PWM_1->setText(QString::number( Motor_PWM_Show[1]));
    ui.Motor_PWM_2->setText(QString::number( Motor_PWM_Show[2]));
    ui.Motor_PWM_3->setText(QString::number( Motor_PWM_Show[3]));
    ui.Water_Deep->setText(QString::number(Water_Deep));
    ui.Water_Temp->setText(QString::number(Water_Temperature));
    if(ui.Deep_Rec->isChecked())
    {
        int i;
        fstream Deep_rec("/home/nvidia/Desktop/Deep_rec.txt",ios::out|ios::app);
        if(!Deep_rec.is_open())
        {
            ui.textEdit->append("The Deep_rec open is failed");
        }
        Deep_rec<<Water_Deep<<" ";
        Deep_rec<<"\n";
        Deep_rec.close();

    }
    //plot the Deep and Temp change picture
    //Water_Deep_Temp_Plot();
    if(ui.Visual_Rec->isChecked())
    {
        int i;
        fstream visual_rec("/home/nvidia/Desktop/visual_rec.txt",ios::out|ios::app);
        if(!visual_rec.is_open())
        {
            ui.textEdit->append("The visual_rec file open is failed");
        }
       for(i=0;i<3;i++)
       {
           visual_rec<<Visual_Position[i]<<" ";
       }
       visual_rec<<"\n";
       visual_rec.close();
    }
}
//打开摄像头
void MainWindow::on_open_camera_clicked()
{

     //capture.open(0);
     camera_timer->start(50);
     //ui->groupBox_3->setEnabled(true);
     ui.shoot_video->setEnabled(true);
     ui.open_camera->setEnabled(false);
     ui.stop_video->setEnabled(false);


     //cout<<"open camera"<<endl;

    //cout<<"open camera"<<endl;

}
//读取摄像头并显示在窗口
void MainWindow::readcamera_Frame()
{
    camera_frame=im_raw;
    //std::cout<<camera_frame.<<std::endl;
    if(!camera_frame.empty())
    {
        camera_image=cvMat2QImage(camera_frame);
//        if(ui->Visual_Sign->isChecked())
//        {
//             //Mat frame_out;
//            // camera_frame.copyTo(frame_out);
//             //QImage frame_out_qt=cvMat2QImage(frame_out);
//             //QImage camera_result=frame_out_qt.scaled(ui->camera->width(),ui->camera->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation).rgbSwapped();
//            // ui->camera->setPixmap(QPixmap::fromImage(camera_result));
             ui.Euler_X_display->setText(QString::number(Visual_Eular[0]));
             ui.Euler_Y_display->setText(QString::number(Visual_Eular[1]));
             ui.Euler_Z_display->setText(QString::number(Visual_Eular[2]));
             ui.Dis_X_display->setText(QString::number(Visual_Position[0]));
             ui.Dis_Y_display->setText(QString::number(Visual_Position[1]));
             ui.Dis_Z_display->setText(QString::number(Visual_Position[2]));

//             if(ui->Visual_Rec->isChecked())
//             {
//                 int i;
//                 fstream file("/home/nvidia/Desktop/visual_rec.txt",ios::out|ios::app);
//                 if(!file.is_open())
//                 {
//                     ui->textEdit->append("The file open is failed");
//                 }
//                // if(Visual_ID>0)
//                 {
//                    for(i=0;i<3;i++)
//                    {
//                        file<<Visual_Eular[i]<<" ";
//                    }
//                    file<<"\n";
//                    for(i=0;i<3;i++)
//                    {
//                        file<<IMU_A_Ang[i]<<" ";
//                    }
//                    file<<"\n";
//                    for(i=0;i<3;i++)
//                    {
//                        file<<Data_eul[i]<<" ";
//                    }
//                    file<<"\n";
//                    for(i=0;i<3;i++)
//                    {
//                        file<<Visual_Position[i]<<" ";
//                    }
//                    file<<"\n";
//                 }
//                 else
//                 {
//                    for(i=0;i<3;i++)
//                    {
//                        file<<-1<<" ";
//                    }
//                    file<<"\n";
//                    for(i=0;i<3;i++)
//                    {
//                        file<<IMU_A_Ang[i]<<" ";
//                    }
//                    file<<"\n";
//                    for(i=0;i<3;i++)
//                    {
//                        file<<Data_eul[i]<<" ";
//                    }
//                    file<<"\n";
//                    for(i=0;i<3;i++)
//                    {
//                        file<<-1<<" ";
//                    }
//                    file<<"\n";
//                }
//                file.close();
//            }
//        }
//        else
//        {
            QImage camera_result=camera_image.scaled(ui.camera->width(),ui.camera->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation).rgbSwapped();
            ui.camera->setPixmap(QPixmap::fromImage(camera_result));
//        }
    }

}

void MainWindow::writeVideo_Frame()
{
    createVideo << camera_frame;
}
//开始录制视频
void MainWindow::on_shoot_video_clicked()
{
    string strN =".avi";
    string str = timeStr + strN;
    createVideo.open(str,CV_FOURCC('M', 'J', 'P', 'G'), 25.0, Size(camera_frame.cols,camera_frame.rows));
    cout<<"record video"<<endl;
    ui.videoRecordState->setVisible(true);
    ui.shoot_video->setEnabled(false);
    ui.stop_video->setEnabled(true);
    ui.realtime->setVisible(false);
    video_timer->start(40);
}
//结束视频录制
void MainWindow::on_stop_video_clicked()
{
    video_timer->stop();
    ui.videoRecordState->setVisible(false);
    ui.shoot_video->setEnabled(true);
    ui.stop_video->setEnabled(false);

}
//关闭摄像头
void MainWindow::on_close_camera_clicked()
{
    camera_timer->stop();
    capture.release();
    ui.camera->clear();
    ui.realtime->setVisible(true);
    ui.videoRecordState->setVisible(false);
    ui.open_camera->setEnabled(true);
}
//采集图像
void MainWindow::on_pic_camera_clicked()
{
    QImage camera_result=camera_image.scaled(ui.camera->width(),ui.camera->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation).rgbSwapped();
    ui.camera->setPixmap(QPixmap::fromImage(camera_result));
    Mat frame_src = camera_frame;

    string strN ="_ori.jpg";
    string str = timeStr + strN;
    imwrite(str, frame_src);;

}
//实时时间显示
void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    QString strForFile = time.toString("yyyy-MM-dd hh-mm-ss");
    stamp = time.toString("hh:mm:ss:");
    timeStr = strForFile.toStdString();
    ui.realtime->setText(str);
}
//Mat转换成Qimage
QImage cvMat2QImage(Mat& mat)
{
    QImage* qimg=new QImage;
    *qimg = QImage((unsigned char*)mat.data, // uchar* data
            mat.cols, mat.rows, // width height
            QImage::Format_RGB888); //format
    return *qimg;
}
//Qimage转换成Mat
Mat QImage2cvMat(QImage image)
{
    Mat mat;
    switch(image.format())
    {
        case QImage::Format_ARGB32:
        case QImage::Format_RGB32:
        case QImage::Format_ARGB32_Premultiplied:
            mat = Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
            break;
        case QImage::Format_RGB888:
            mat = Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
            cvtColor(mat, mat, CV_BGR2RGB);
            break;
        case QImage::Format_Indexed8:
            mat = Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
            break;
    }
    return mat;
}

void MainWindow::start_check_successful()
{
    ui.textEdit->append("the underlying system start successfully !");
    ui.Telecontrol_Module->setEnabled(true);
    ui.Control_Module->setEnabled(true);
    ui.Start_Check->setEnabled(false);
    ui.Control_groupBox->setEnabled(true);
    ui.Visual_groupBox->setEnabled(true);

}

void MainWindow::start_check_faild()
{
    ui.textEdit->append("the underlying system error!");
    ui.textEdit->append("error code :");
    ui.textEdit->append(QString::number(Check_Sign));
}

void MainWindow::on_Tele_Auto_clicked(bool checked)
{
    if(checked)
    {
        ui.textEdit->append("AUTOMATIC MODE");
        ui.Tele_Auto->setText("Manual");
        ui.Tele_Ahead->setEnabled(false);
        ui.Tele_Back->setEnabled(false);
        ui.Tele_Left->setEnabled(false);
        ui.Tele_Look_UP->setEnabled(false);
        ui.Tele_Right->setEnabled(false);
        ui.Tele_Stoop->setEnabled(false);
        ui.Tele_UP->setEnabled(false);
    }
    else
    {
        ui.textEdit->append("MANUAL MODE");
        ui.Tele_Auto->setText("Auto");
        ui.Tele_Ahead->setEnabled(true);
        ui.Tele_Back->setEnabled(true);
        ui.Tele_Left->setEnabled(true);
        ui.Tele_Look_UP->setEnabled(true);
        ui.Tele_Right->setEnabled(true);
        ui.Tele_Stoop->setEnabled(true);
        ui.Tele_UP->setEnabled(true);
    }
}
//avoid damage electric machinery


//avoid damage electric machinery
void MainWindow::safe_stop_up_down()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[2]=888;
    Motor_PWM_Control[3]=888;
    Q_EMIT this->emit_new_pwm();
    usleep(500000);//500ms
}

void MainWindow::on_AUV_START_clicked()   //start
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[0]=888;
    Motor_PWM_Control[1]=888;
    Motor_PWM_Control[2]=888;
    Motor_PWM_Control[3]=888;
    Q_EMIT this->emit_new_pwm();
    ui.textEdit->append("AUV has been started,please select the control MODE");
//  connect(Self_control,SIGNAL(emit_renew_pwm()),Stm32,SLOT(change_pwm()));
}

void MainWindow::on_Tele_Ahead_clicked()  //jia su
{
    Q_EMIT this->emit_stop_PID_Control();
    safe_stop_ahead_back();
    Motor_PWM_Control[0]=900;
    Motor_PWM_Control[1]=900;

    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Ahead_plus_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[0]=Motor_PWM_Control[0]+Motor_PWM_ADD;
    Motor_PWM_Control[1]=Motor_PWM_Control[1]+Motor_PWM_ADD;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Ahead_reduce_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[0]=Motor_PWM_Control[0]-Motor_PWM_ADD;
    Motor_PWM_Control[1]=Motor_PWM_Control[1]-Motor_PWM_ADD;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Tele_Back_clicked()  //hou tui
{
    Q_EMIT this->emit_stop_PID_Control();
    safe_stop_ahead_back();
    Motor_PWM_Control[0]=860;
    Motor_PWM_Control[1]=860;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Back_plus_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[0]=Motor_PWM_Control[0]-Motor_PWM_ADD;
    Motor_PWM_Control[1]=Motor_PWM_Control[1]-Motor_PWM_ADD;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Back_reduce_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[0]=Motor_PWM_Control[0]+Motor_PWM_ADD;
    Motor_PWM_Control[1]=Motor_PWM_Control[1]+Motor_PWM_ADD;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Tele_Right_clicked()  //you zhuan
{
    Q_EMIT this->emit_stop_PID_Control();
    safe_stop_ahead_back();
    Motor_PWM_Control[0]=900;
    Motor_PWM_Control[1]=860;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Right_plus_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[0]=Motor_PWM_Control[0]+Motor_PWM_ADD;
    Motor_PWM_Control[1]=Motor_PWM_Control[1]-Motor_PWM_ADD;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Right_reduce_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[0]=Motor_PWM_Control[0]-Motor_PWM_ADD;
    Motor_PWM_Control[1]=Motor_PWM_Control[1]+Motor_PWM_ADD;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Tele_Left_clicked()   //zuo zhuan
{
    Q_EMIT this->emit_stop_PID_Control();
    safe_stop_ahead_back();
    Motor_PWM_Control[0]=860;
    Motor_PWM_Control[1]=900;

    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Left_plus_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[0]=Motor_PWM_Control[0]-Motor_PWM_ADD*2;
    Motor_PWM_Control[1]=Motor_PWM_Control[1]+Motor_PWM_ADD*2;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Left_reduce_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[0]=Motor_PWM_Control[0]+Motor_PWM_ADD*2;
    Motor_PWM_Control[1]=Motor_PWM_Control[1]-Motor_PWM_ADD*2;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Tele_Stoop_clicked()  //qian mian qi dong
{

}

void MainWindow::on_Tele_Look_UP_clicked()  //xia qian
{

}

void MainWindow::on_Tele_UP_clicked()   // shang fu
{
    Q_EMIT this->emit_stop_PID_Control();
    safe_stop_up_down();
    Motor_PWM_Control[2]=860;
    Motor_PWM_Control[3]=860;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Tele_DOWN_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    safe_stop_up_down();
    Motor_PWM_Control[2]=895;
    Motor_PWM_Control[3]=895;

    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Down_plus_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[2]=Motor_PWM_Control[2]+Motor_PWM_ADD;
    Motor_PWM_Control[3]=Motor_PWM_Control[3]+Motor_PWM_ADD;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_Down_reduce_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[2]=Motor_PWM_Control[2]-Motor_PWM_ADD;
    Motor_PWM_Control[3]=Motor_PWM_Control[3]-Motor_PWM_ADD;
    Q_EMIT this->emit_new_pwm();
}

void MainWindow::on_AUV_STOP_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[0]=0;
    Motor_PWM_Control[1]=0;
    Motor_PWM_Control[2]=0;
    Motor_PWM_Control[3]=0;
    Q_EMIT this->emit_new_pwm();
    ui.textEdit->append("AUV has been stoped,automatically rising");
}

void MainWindow::on_AUV_GOUP_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
    Motor_PWM_Control[0]=0;
    Motor_PWM_Control[1]=0;
    Motor_PWM_Control[2]=0;
    Motor_PWM_Control[3]=0;
   // Motor_PWM_Control[4]=885;
   // Motor_PWM_Control[5]=880;
    Q_EMIT this->emit_new_pwm();
    ui.textEdit->append("AUV rising quickly");
}

void MainWindow::on_SortPort_Send_clicked()
{
    QString Command_Input =ui.Command_Input_Text->text();

    bool ok;
    char *Command_input_char=Command_Input.toLocal8Bit().data();
    int Data_Input = Command_Input.toInt(&ok,10);
    if(!ok)
    {
        switch(Command_input_char[0])
        {
            case 'l':
                ui.textEdit->append("Motor control command,please input the Motor_PWM_ADD");
                ui.Command_Input_Text->clear();
                Data_class=1;
                break;
            case 'a':
                ui.textEdit->append("Motor control command,please input the Motor_0 PWM ");
                ui.Command_Input_Text->clear();
                Data_class=2;
                break;
            case 'b':
                ui.textEdit->append("Motor control command,please input the Motor_1 PWM ");
                ui.Command_Input_Text->clear();
                Data_class=3;
                break;
            case 'c':
                ui.textEdit->append("Motor control command,please input the Motor_2 PWM ");
                ui.Command_Input_Text->clear();
                Data_class=4;
                break;
            case 'd':
                ui.textEdit->append("Motor control command,please input the Motor_3 PWM ");
                ui.Command_Input_Text->clear();
                Data_class=5;
                break;

            default :
                ui.textEdit->append("Invalid command,please enter again ");
                ui.Command_Input_Text->clear();
                break;
        }

    }
    else
    {
        if(Data_Input>=0&&Data_Input<1600)
        {
            switch(Data_class)
            {
            case 1:
                ui.textEdit->append("Motor_PWM_ADD: "+Command_Input);
                ui.Command_Input_Text->clear();
                Motor_PWM_ADD=Data_Input;
                Data_class=0;
                break;
            case 2:
                ui.textEdit->append("Motor_0 :" +Command_Input );
                ui.Command_Input_Text->clear();
                Motor_PWM_Control[0]=Data_Input;
                Q_EMIT this->emit_new_pwm();
                Data_class=0;
                break;
            case 3:
                ui.textEdit->append("Motor_1 :" +Command_Input);
                ui.Command_Input_Text->clear();
                Motor_PWM_Control[1]=Data_Input;
                Q_EMIT this->emit_new_pwm();
                Data_class=0;
                break;
            case 4:
                ui.textEdit->append("Motor_2 :" +Command_Input);
                ui.Command_Input_Text->clear();
                Motor_PWM_Control[2]=Data_Input;
                Q_EMIT this->emit_new_pwm();
                Data_class=0;
                break;
            case 5:
                ui.textEdit->append("Motor_3 :" +Command_Input);
                ui.Command_Input_Text->clear();
                Motor_PWM_Control[3]=Data_Input;
                Q_EMIT this->emit_new_pwm();
                Data_class=0;
                break;

            default :
                ui.textEdit->append("Invalid command,please enter again ");
                ui.Command_Input_Text->clear();
                Data_class=0;
                break;
            }

        }
        else
        {
            ui.textEdit->append("Invalid value,please enter again ");
            ui.Command_Input_Text->clear();
        }

    }
}



/*///////////////////////////////////////////////////pengjun 1.14////////绘制图标///////////////////////////////////////////*/




/*///////////////////////////////////////////////////pengjun 1.14/////////////绘制图标//////////////////////////////////////*/
/*///////////////////////////////////////////////////pengjun 1.18/////////////设置PID参数//////////////////////////////////////*/
void MainWindow::on_Stablilize_Yaw_Send_clicked()
{
    QString Stablilize_Yaw_Kp_Input =ui.Stablilize_Yaw_Kp_Input->text();
    QString Stablilize_Yaw_Ki_Input =ui.Stablilize_Yaw_Ki_Input->text();
    QString Stablilize_Yaw_Kd_Input =ui.Stablilize_Yaw_Kd_Input->text();
    Stablilize_Yaw_PID_Input_Buff[0]=Stablilize_Yaw_Kp_Input.toFloat();/////将Stablilize_Yaw_Kp_Input中的值转化成float型
    Stablilize_Yaw_PID_Input_Buff[1]=Stablilize_Yaw_Ki_Input.toFloat();
    Stablilize_Yaw_PID_Input_Buff[2]=Stablilize_Yaw_Kd_Input.toFloat();
    Q_EMIT this->emit_new_Stablilize_Yaw_PID();
    Q_EMIT this->emit_start_PID_Control();

}

void MainWindow::on_Yaw_Rate_Send_clicked()
{
    QString Yaw_Rate_Kp_Input =ui.Yaw_Rate_Kp_Input->text();
    QString Yaw_Rate_Ki_Input =ui.Yaw_Rate_Ki_Input->text();
    QString Yaw_Rate_Kd_Input =ui.Yaw_Rate_Kd_Input->text();
    Yaw_Rate_PID_Input_Buff[0]=Yaw_Rate_Kp_Input.toFloat();
    Yaw_Rate_PID_Input_Buff[1]=Yaw_Rate_Ki_Input.toFloat();
    Yaw_Rate_PID_Input_Buff[2]=Yaw_Rate_Kd_Input.toFloat();
    Q_EMIT this->emit_new_Yaw_Rate_PID();
    Q_EMIT this->emit_start_PID_Control();
}

void MainWindow::on_Depth_Send_clicked()
{
    QString Depth_Kp_Input =ui.Depth_Kp_Input->text();
    QString Depth_Ki_Input =ui.Depth_Ki_Input->text();
    QString Depth_Kd_Input =ui.Depth_Kd_Input->text();
    Depth_PID_Input_Buff[0]=Depth_Kp_Input.toFloat();
    Depth_PID_Input_Buff[1]=Depth_Ki_Input.toFloat();
    Depth_PID_Input_Buff[2]=Depth_Kd_Input.toFloat();
    Q_EMIT this->emit_new_Depth_PID();
    Q_EMIT this->emit_start_PID_Control();
}

void MainWindow::on_Depth_Rate_Send_clicked()
{
    QString Depth_Rate_Kp_Input =ui.Depth_Rate_Kp_Input->text();
    QString Depth_Rate_Ki_Input =ui.Depth_Rate_Ki_Input->text();
    QString Depth_Rate_Kd_Input =ui.Depth_Rate_Kd_Input->text();
    Depth_Rate_PID_Input_Buff[0]=Depth_Rate_Kp_Input.toFloat();
    Depth_Rate_PID_Input_Buff[1]=Depth_Rate_Ki_Input.toFloat();
    Depth_Rate_PID_Input_Buff[2]=Depth_Rate_Kd_Input.toFloat();
    Q_EMIT this->emit_new_Depth_Rate_PID();
    Q_EMIT this->emit_start_PID_Control();
}

void MainWindow::on_Target_Position_Send_clicked()
{
    QString Target_Position_X_Input =ui.Target_Position_X_Input->text();
    QString Target_Position_Y_Input =ui.Target_Position_Y_Input->text();
    QString Target_Position_Z_Input =ui.Target_Position_Z_Input->text();
    QString Target_Position_Yaw_Input =ui.Target_Position_Yaw_Input->text();
    QString Target_Position_Roll_Input =ui.Target_Position_Roll_Input->text();
    QString Target_Position_Pitch_Input =ui.Target_Position_Pitch_Input->text();
    Target_Position_Buff[0]=Target_Position_X_Input.toFloat();
    Target_Position_Buff[1]=Target_Position_Y_Input.toFloat();
    Target_Position_Buff[2]=Target_Position_Z_Input.toFloat();
    Target_Position_Buff[3]=Target_Position_Yaw_Input.toFloat();
    Target_Position_Buff[4]=Target_Position_Roll_Input.toFloat();
    Target_Position_Buff[5]=Target_Position_Pitch_Input.toFloat();

    Q_EMIT this->emit_new_Target_Position();
    Q_EMIT this->emit_start_PID_Control();

}


/*///////////////////////////////////////////////////pengjun 1.18////////////////设置PID参数///////////////////////////////////*/


void MainWindow::on_AUV_Hover_clicked()
{
    Target_Position_Buff[2]=Water_Deep;
    Q_EMIT this->emit_new_Target_Position();
    Q_EMIT this->emit_start_PID_Control();

}


void MainWindow::on_AUV_Hover_Stop_clicked()
{
    Q_EMIT this->emit_stop_PID_Control();
}



void MainWindow::on_STM32_Reset_clicked()
{

}

void MainWindow::on_Test_clicked()
{
    Current_Position_Buff[0]=Target_Position_Buff[0]-0.01;//x位置
    Current_Position_Buff[1]=Target_Position_Buff[1];//y位置
    Current_Position_Buff[2]= Water_Deep;
    //Current_Position_Buff[2]=Visual_Position[2];//z位置
    Current_Position_Buff[3]=0.0;//绕x转动角度     Visual_Eular[0]//绕x转动角度 数据暂时缺失
    Current_Position_Buff[4]=0.0;//绕x转动角度   Visual_Eular[1]//绕y转动角度 数据暂时缺失
    Current_Position_Buff[5]=0.0;//绕x转动角度   Visual_Eular[2]//绕z转动角度 数据暂时缺失
    Q_EMIT this->emit_new_Current_Position();
}

void MainWindow::on_pushButton_clicked()
{
    ui.Tele_Ahead->setEnabled(false);
    ui.Tele_Back->setEnabled(false);
    ui.Tele_Left->setEnabled(false);
    ui.Tele_Look_UP->setEnabled(false);
    ui.Tele_Right->setEnabled(false);
    ui.Tele_Stoop->setEnabled(false);
    ui.Tele_UP->setEnabled(false);
    ui.Tele_DOWN->setEnabled(false);
    ui.Tele_Auto->setEnabled(false);
}

}  // namespace sailor2

