#include "linklist.h"
#include <stdio.h>
Node* creatList()//新建链表
{
    Node *p=new Node;
    p->data=-1;
    p->next=NULL;
    return p;
}
/*============================================
*
=============================================*/
void printList(Node *list)//打印链表所有成员
{
    printf("=======begin========\r\n");
    while(list)
    {
        printf("%d->",list->data);
        list=list->next;
    }
    printf("null\r\n=======end========\r\n");
}
/*============================================
*
=============================================*/
void makeEmpty(Node *list)//清空链表
{
    Node* p=list;
    while(list)
    {
        p=list;
        list=list->next;
        delete p;
    }
}
/*============================================
*
=============================================*/
bool insert(Node *list, int position, int data)//在具体位置插入数据
{
    if (list==NULL)
        return 0;
    while (--position && list)//找到插入的地方
    {
        list=list->next;
    }
    if (position)//说明位置不存在
    {
        return 0;
    }
    else
    {
        Node *p=new Node;
        p->data=data;
        p->next=list->next;
        list->next=p;
        return 1;
    }
}
/*============================================
*
=============================================*/
void remove(Node *list, int data)//删除一个节点
{
    Node *p;
    while (list && list->data!=data)
    {
        p=list;
        list=list->next;
    }
        p->next=list->next;
        delete list;
}
/*============================================
*
=============================================*/
bool find(Node *list, int data)//找到特定数据的第一个节点
{
    while (list && list->data!=data)
    {
        list=list->next;
    }
    return list;
}
/*============================================
*
=============================================*/
int findKth(Node *list, int position)
{
    while (--position && list)
    {
        list=list->next;
    }
    return list ? list->data : 0;
}
