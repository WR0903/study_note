#include <string>
#include <opencv2/opencv.hpp>
#include <iostream>
#include<stdio.h>
#include<malloc.h>
#include <mapping.h>

using namespace cv;
using namespace std;

/* ．．．．．．．  地图显示   ．．．．．．．．*/
void mapping1::mapping1_init()//无参构造函数
{
    //start_num=702;
    //flag[]={0};
    for(int i=0;i<729;i++)
    {
        flag[i]=0;
    }
    for(int i=0;i<10;i++)
    {
        flag[10+i*27]=1;
    }
    for(int i=0;i<3;i++)
    {
        flag[254+i]=1;
    }
    for(int i=0;i<5;i++)
    {
        flag[257+i-54]=1;
        flag[257+i-27]=1;
        flag[257+i]=1;
        flag[257+i+27]=1;
    }
    for(int i=0;i<4;i++)
    {
        flag[73+i]=1;
        flag[73+i+27]=1;
        flag[73+i+54]=1;
    }
    for(int i=0;i<6;i++)
    {
        flag[185+i*27]=1;
    }
    for(int i=0;i<15;i++)
    {
        flag[363+i]=1;
    }
    for(int i=0;i<7;i++)
    {
        flag[328+i]=1;
    }
    for(int i=0;i<5;i++)
    {
        flag[334+(i+1)*27]=1;
    }
    for(int i=0;i<7;i++)
    {
        flag[493+i]=1;
        flag[493+i+27]=1;
        flag[493+i+54]=1;
    }
    for(int i=0;i<8;i++)
    {
        flag[621+i]=1;
    }
    for(int i=0;i<4;i++)
    {
        flag[606+i]=1;
        flag[606+i+27]=1;
        flag[606+i+54]=1;
        flag[606+i+81]=1;
        flag[606+i+108]=1;
    }
    flag[stop_num]=3;//目标点,
    flag[start_num]=4;//起始点
}


void mapping1::map_show()//地图显示
{
    for(int i=0;i<729;i++)
    {
        root_points[i][0] = Point((i%27+1)*20, (i/27+1)*20);
        root_points[i][1] = Point((i%27+1)*20+20, (i/27+1)*20);
        root_points[i][2] = Point((i%27+1)*20+20, (i/27+1)*20+20);
        root_points[i][3] = Point((i%27+1)*20, (i/27+1)*20+20);
        const Point* ppt[1] = { root_points[i] };
        int npt[] = { 4 };
        if(1==flag[i])
        {
            fillPoly(img, ppt, npt, 1, Scalar(0,0,0));
        }
        else if(0==flag[i])
        {
            fillPoly(img, ppt, npt, 1, Scalar(255,255,255));
        }
        else if(3==flag[i])
        {
            fillPoly(img, ppt, npt, 1, Scalar(0,0,255));
        }
        else if(4==flag[i])
        {
            fillPoly(img, ppt, npt, 1, Scalar(255,0,0));
        }
        else
        {
            fillPoly(img, ppt, npt, 1, Scalar(0,255,255));
        }
    }
    for(int i=0;i<28;i++)
    {
        line(img,Point((i+1)*20,20),Point((i+1)*20,560),Scalar(0,0,255),1,CV_AA);
        line(img,Point(20,(i+1)*20),Point(560,(i+1)*20),Scalar(0,0,255),1,CV_AA);
    }
}

void mapping1::CreateALGraph()//建图
{
    this->GG = (AGraph*)malloc(sizeof(AGraph)) ;
    int i ;
    node *s ;
    this->GG->n=729;
    for( i = 0 ; i <this->GG->n ; i++)
    {
        this->GG->adjList[i].vertex=flag[i];//flag
        this->GG->adjList[i].firstedge = NULL ; //将顶点的边表头指针设置为空
        /*   判断边的信息  */
        if((flag[i]!=1)&&(i%27!=0)&&(flag[i-1]!=1))//右边的边
        {
            this->GG->e++;
            s = (node*)malloc(sizeof(node)) ;
            s->adjvex = i-1 ;
            s->next = this->GG->adjList[i].firstedge ;
            this->GG->adjList[i].firstedge = s ;
        }

        if((flag[i]!=1)&&((i+1)%27!=0)&&(flag[i+1]!=1))//右边的边
        {
            this->GG->e++;
            s = (node*)malloc(sizeof(node)) ;
            //边上的第一个节点
            s->adjvex = i+1 ;
            s->next = this->GG->adjList[i].firstedge ;
            this->GG->adjList[i].firstedge = s ;
        }

        if((flag[i]!=1)&&(i-27>0)&&(flag[i-27]!=1))//下面的边
        {
            this->GG->e++;
            s = (node*)malloc(sizeof(node)) ;
            //边上的第一个节点
            s->adjvex = i;
            s->next = this->GG->adjList[i-27].firstedge ;
            this->GG->adjList[i-27].firstedge = s ;
            //边上的第二个节点
            s = (node*)malloc(sizeof(node)) ;
            s->adjvex = i-27;
            s->next = this->GG->adjList[i].firstedge ;
            this->GG->adjList[i].firstedge = s ;
        }

        if((flag[i]!=1)&&(i+27<729)&&(flag[i+27]!=1))//下面的边
        {
            this->GG->e++;
            s = (node*)malloc(sizeof(node)) ;
            s->adjvex = i;
            s->next = this->GG->adjList[i+27].firstedge ;
            this->GG->adjList[i+27].firstedge = s ;
        }
    }
}

void mapping1::a_star()//A*算法
{

    for(int i=0;i<729;i++)
    {
        aa_node[i].num=i;
        aa_node[i].know=false;
        aa_node[i].dv=99999;
        if(4==flag[i])
        {
            aa_node[i].dv=0;
            start_num=i;
        }
        if(3==flag[i])
        {
            stop_num=i;
        }
        aa_node[i].pv_num=0;
    }
    while(aa_node[stop_num].know!=true)
    {
        int num_tmp,dv_tmp;
        num_tmp=0;
        dv_tmp=99999;
        for(int i=0;i<729;i++)
        {
            if(true==aa_node[i].know)
                continue;
            if(aa_node[i].dv<dv_tmp)
            {
                dv_tmp=aa_node[i].dv;
                num_tmp=aa_node[i].num;
            }
        }
        aa_node[num_tmp].know=true;

        node *stmp;
        stmp = (node*)malloc(sizeof(node)) ;
        stmp= GG->adjList[aa_node[num_tmp].num].firstedge ;
        int tmp;
        while(stmp!=NULL)
        {
            tmp=stmp->adjvex;

            if((aa_node[num_tmp].dv+1)<aa_node[tmp].dv)
            {
                aa_node[tmp].dv=aa_node[num_tmp].dv+1;
                aa_node[tmp].pv_num=num_tmp;
            }
            stmp=stmp->next;
        }
    }
    int tmp_n=aa_node[stop_num].pv_num;
    while(tmp_n!=start_num)
    {
        flag[tmp_n]=2;
        tmp_n=aa_node[tmp_n].pv_num;
    }

}

