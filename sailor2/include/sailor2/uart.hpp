#ifndef UART_H
#define UART_H

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<stdlib.h>
#include <iostream>

namespace sailor2 {
int Tx1UartInit_com2(int & fd);//pwm control  open uart(J17 header) in tx1
int Tx1UartInit_com1(int & fd);//updat data read data of pwm /imu /water  //open uart(J21 header) in tx1 8_9
int set_opt(int fd,int nSpeed,int nBits,char nEvent,int nStop);
int open_port(int fd, int comport);
void Data16to8(u_int16_t *data16, u_int8_t *data8,int len);
void Data8to16(u_int8_t *data8,int *data16, int len);
}
#endif // UART_H
