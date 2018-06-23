#include"../include/sailor2/uart.hpp"
namespace sailor2 {
int set_opt(int fd,int nSpeed,int nBits,char nEvent,int nStop)
{
    struct termios newtio,oldtio;
    if (tcgetattr(fd,&oldtio)!=0)//save the previous setting
    {
        perror("SetupSerial 1");
        return -1;
    }
    bzero(&newtio,sizeof(newtio));
    newtio.c_cflag |= CLOCAL|CREAD; //激活选项有CLOCAL和CREAD，用于本地连接和接收使用
    newtio.c_cflag &= ~CSIZE;
    switch (nBits) //set data bits
    {
    case 7:
        newtio.c_cflag |=CS7;
        break;
    case 8:
        newtio.c_cflag |=CS8;
        break;
    }

    switch( nEvent ) //set even or odd check
    {
    case 'O':                     //奇校验
        newtio.c_cflag |= PARENB;
        newtio.c_cflag |= PARODD;
        newtio.c_iflag |= (INPCK | ISTRIP);
        break;
    case 'E':                     //偶校验
        newtio.c_iflag |= (INPCK | ISTRIP);
        newtio.c_cflag |= PARENB;
        newtio.c_cflag &= ~PARODD;
        break;
    case 'N':                    //无校验
        newtio.c_cflag &= ~PARENB;
        break;
    }
    switch( nSpeed ) //set baud rate
        {
        case 2400:
            cfsetispeed(&newtio, B2400);
            cfsetospeed(&newtio, B2400);
            break;
        case 4800:
            cfsetispeed(&newtio, B4800);
            cfsetospeed(&newtio, B4800);
            break;
        case 9600:
            cfsetispeed(&newtio, B9600);
            cfsetospeed(&newtio, B9600);
            break;
        case 115200:
            cfsetispeed(&newtio, B115200);
            cfsetospeed(&newtio, B115200);
            break;
        default:
            cfsetispeed(&newtio, B9600);
            cfsetospeed(&newtio, B9600);
            break;
        }
        if( nStop == 1 ) //set stop bits
        {
            newtio.c_cflag &=  ~CSTOPB;
        }
        else if ( nStop == 2 )
        {
            newtio.c_cflag |=  CSTOPB;
        }
        newtio.c_cc[VTIME]  = 0;//设置最少等待时间
        newtio.c_cc[VMIN] = 1;//设置最少等待字符
        tcflush(fd,TCIFLUSH);//flush the input quene
        if((tcsetattr(fd,TCSANOW,&newtio))!=0)//put the setting into FD
        {
            perror("com set error");
            return -1;
        }
       // printf("set done!\n");
        return 0;

}

int open_port(int fd,int comport)
{
    char *dev[]={"/dev/ttyS0","/dev/ttyS1","/dev/ttyS2"};
    long  vdisable;
    if (comport==1)//this com is J21_8(TX) J21_9(X)
        //参数--O_NOCTTY:通知linux系统，这个程序不会成为这个端口的控制终端.
        //O_NDELAY:通知linux系统不关心DCD信号线所处的状态(端口的另一端是否激活或者停止).
    {   fd = open( "/dev/ttyS0", O_RDWR|O_NOCTTY|O_NDELAY);
        if (-1 == fd)
        {
            perror("Can't Open Serial Port");
            return(-1);
        }
        else
        {
            std::cout<<"open ttyS0 ....."<<std::endl;
        }
    }

    else if(comport==2)
    {    fd = open( "/dev/ttyTHS2", O_RDWR|O_NOCTTY|O_NDELAY);
        if (-1 == fd)
        {
            perror("Can't Open Serial Port");
            return(-1);
        }
        else
        {
           std::cout<<"open ttyTHS2 ....."<<std::endl;
        }
    }
    else if (comport==3)
    {
        fd = open( "/dev/ttyS2", O_RDWR|O_NOCTTY|O_NDELAY);
        if (-1 == fd)
        {
            perror("Can't Open Serial Port //F_SETFL：设置文件flag为0，即默认，即阻塞状态");
            return(-1);
        }
        else
        {
            std::cout<<"open ttyS2 ....."<<std::endl;
        }
    }
    if(fcntl(fd, F_SETFL, 0)<0)  //F_SETFL：设置文件flag为0，即默认，即阻塞状态
    {
        std::cout<<"fcntl failed!"<<std::endl;
    }
    else
    {
        std::cout<<fcntl(fd, F_SETFL,0)<<std::endl;
    }
    if(isatty(STDIN_FILENO)==0)//测试打开的文件描述符是否应用一个终端设备，以进一步确认串口是否正确打开
    {
        //printf("standard input is not a terminal device\n");
    }
    else
    {
        std::cout<<"isatty success!\n"<<std::endl;
    }
    std::cout<<fd<<std::endl;
    return fd;
}

int Tx1UartInit_com1(int & fd)
{
    int i;
    if((fd=open_port(fd,1))<0 ) //open uart(J21 header) in tx1 8_9  ttys0
    {
        perror("open_port1 error");
        return 0;
    }

    if((i=set_opt(fd,115200,8,'N',1))<0)
    {
        perror("set_opt error");
        return 0;
    }
    return 1;
}

// set new init 2
int Tx1UartInit_com2(int & fd)
{
    int i;
    if((fd=open_port(fd,2))<0 ) //open uart3(J17 header) in tx1
    {
        perror("open_port1 error");
        return 0;
    }

    if((i=set_opt(fd,115200,8,'N',1))<0)
    {
        perror("set_opt error");
        return 0;
    }
    return 1;
}


void Data16to8(u_int16_t *data16, u_int8_t *data8, int len)
{
    int i,k,n;
    u_int8_t data[200]={0};
    for(i=0;i<len;i++)
     {
        k=i/2;
        if(i%2==0)
        {
            data[i] |= data16[k];
        }
        if(i%2==1)
        {
            data[i] |= data16[k]>>8;
        }
    }
    for(n=0;n<len;n++)
    {
        data8[n]=data[n];
        data[n]=0;
    }

}


void Data8to16(u_int8_t *data8, int *data16, int len)
{
    int i,n,lenfor16;
    lenfor16=len/2;
    u_int16_t data[200]={0};
    for(i=0;i<lenfor16;i++)
    {
        data[i] |= data8[2*i];
        data[i] |= data8[2*i+1]<<8;
    }
    for(n=0;n<lenfor16;n++)
    {
        data16[n]=data[n];
        data[n]=0;
    }
}
}
