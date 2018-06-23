#ifndef STM32_H
#define STM32_H

#include <QObject>
#include <iostream>
#include <string.h>
#include <QTimer>
#include "uart.hpp"
#include "dataLib.hpp"
namespace sailor2 {


class STM32 : public QObject
{
    Q_OBJECT
public:
    explicit STM32(QObject *parent = 0);
    QTimer * Updata_timer;
    QTimer * Imu_Data_Correction_timer;
    QTimer * print_timer;
    unsigned char Stm32_commend;
    ~STM32(void);
private:
    int Cor_count;
    long long int count;
    int Uart_FD;
    int Uart_FC;
//signals:
Q_SIGNALS:
    void check_successful();
    void check_faild();
    void display_update();
public Q_SLOTS:
    void update_start(void);
    void update_stop(void);
    void updata_data(void);
    void change_pwm(void);
    void imu_data_correction(void);
    void imu_data_correction_process(void);
    void count_print(void);
    void change_Yaw_Rate_PID();
    void change_Stablilize_Yaw_PID();
    void change_Depth_PID();
    void change_Depth_Rate_PID();
    void change_Target_Position();
    void change_Current_Position();
    void Commend_Buff_Setting(unsigned char Send_Commend,unsigned char *sailor,int num);
    void Receive_Buff_Valid(void);
    void start_PID_Control();
    void stop_PID_Control();
};
}
#endif // STM32_H
