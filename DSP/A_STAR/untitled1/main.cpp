#include <string>
#include <opencv2/opencv.hpp>
#include <iostream>
#include<stdio.h>
#include<malloc.h>
#include <mapping.hpp>

using namespace cv;
using namespace std;
mapping1 ma;
void on_mouse(int event,int x,int y,int flags,void *ustc)//event鼠标事件代号，x,y鼠标坐标，flags拖拽和键盘操作的代号
{
   if (event == CV_EVENT_LBUTTONDOWN)//左键按下，读取初始坐标，并在图像上该点处划圆
   {
       if(x>20&&x<560&&y>20&&y<560)
       {
           int tmp=(y/20-1)*27+x/20-1;
           if(flag[tmp]!=1)
           {
               ma.stop_num=tmp;
               ma.mapping1_init();
               ma.a_star();
               ma.map_show();
            }
       }
   }
   if (event == CV_EVENT_RBUTTONDOWN)//左键按下，读取初始坐标，并在图像上该点处划圆
   {
       if(x>20&&x<560&&y>20&&y<560)
       {
           int tmp=(y/20-1)*27+x/20-1;
           if(flag[tmp]!=1)
           {
               ma.start_num=tmp;
               ma.mapping1_init();
               ma.a_star();
               ma.map_show();
            }
       }
   }
   if (event == CV_EVENT_MBUTTONDOWN)//左键按下，读取初始坐标，并在图像上该点处划圆
   {
       if(x>20&&x<560&&y>20&&y<560)
       {
               ma.start_num=702;
               ma.stop_num=26;
               ma.mapping1_init();
               ma.a_star();
               ma.map_show();
       }
   }
   imshow("image", img);
}


int main()
{
    ma.mapping1_init();
    ma.CreateALGraph() ;
    namedWindow("image",1);
    ma.a_star();
    ma.map_show();
    setMouseCallback("image",on_mouse,0);//调用回调函数
    //ma.a_star();
    //ma.map_show();
    imshow("image", img);
    waitKey(0);

    return 0;
}
