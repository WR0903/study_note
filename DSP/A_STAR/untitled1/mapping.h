#ifndef MAPPING_H
#define MAPPING_H
#include <string>
#include <opencv2/opencv.hpp>
#include <iostream>
#include<stdio.h>
#include<malloc.h>

using namespace cv;
using namespace std;
/*  一些预定义  */
#define MaxVerNum 729 /*定义最大节点数*/
int flag[729];
Mat img(580, 580, CV_8UC3);//读入图像


/*   建图需要的结构体  */
struct node
{
    int adjvex ;//节点号
    struct node *next ; //指向下一个邻接节点域
};
struct vnode//链表头节点
{
    int vertex; //放flag
    node *firstedge ; //边表头指针
};
struct AGraph
{
    vnode adjList[729] ; //邻接表
    int n; //顶点数
    int e=0; //边数
};
/*   a*算法需要的结构体  */
struct a_node
{
    int num;
    bool know;
    int dv;
    int pv_num;
};


/* ．．．．．．．  地图显示   ．．．．．．．．*/
class mapping1
{

private:

    AGraph *GG ;
    a_node aa_node[729];
   //Mat img(580, 580, CV_8UC3);//读入图像
   Point root_points[729][4];

public:
    mapping1()
    {
        start_num=702;
        stop_num=26;
    }
    int start_num,stop_num;
    void mapping1_init();//无参构造函数
    void map_show();
    void CreateALGraph();
    void a_star();
};


#endif // MAPPING_H
