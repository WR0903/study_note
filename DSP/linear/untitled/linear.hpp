#include <iostream>

#include <linear.h>

using namespace std;

void linear_list::InitList()
{
    this->n=10;
    LinkList p;
    int i;
    srand(time(0));
    LL=(LinkList)malloc(sizeof(Node));
    LL->next=NULL;
    for(i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;
        p->next=LL->next;
        LL->next=p;
    }
}
bool linear_list::ListEmpty()
{
    if(0==n)
    {
        return true;
    }
    return false;
}
void linear_list::ClearList()
{
    LinkList p,q;
    p=LL->next;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    LL->next=NULL;
}
bool linear_list::GetElem(int i,ElemType &e)
{
    int j;
    LinkList p;
    p=LL->next;
    j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return false;
    e=p->data;
    return true;
}
int linear_list::LocateElem(ElemType e)
{
    LinkList tmp;
    int i;
    tmp=LL->next;
    for(i=0;i<n;i++)
    {
        if(e==tmp->data)
            break;
        tmp=tmp->next;
    }
    return i;
}
bool linear_list::ListInsert(int i,ElemType e)
{
    int j;
    LinkList p,s;
    p=LL;
    j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
    {
        return false;
    }
    s=(LinkList)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next=s;
    n++;
    return true;
}
bool linear_list::ListDelete(int i,ElemType &e)
{
    int j;
    LinkList p,q;
    p=LL;
    j=1;
    while(p->next&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i)
        return false;
    q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);
    n--;
    return true;
}
int linear_list::ListLength()
{
    return n;
}
