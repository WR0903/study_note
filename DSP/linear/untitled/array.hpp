#include <iostream>

#include <array.h>

using namespace std;

bool array_list::GetElem(SqList *l,int i,ElemType &e)
{
    if(l->length==0||i<1||i>l->length)
        return false;
    e=l->data[i-1];
    return true;
}



void array_list::InitList(SqList* l)
{
    //l->data[]=0;
    l->length=1;
    //l->length=1;
}
bool array_list::ListEmpty(SqList *l)
{
    if(l->length==0)
        return true;
    else
        return false;
}
void array_list::ClearList(SqList* l)
{
    while(l->length>0)
    {
        l->data[l->length-1]=0;
        l->length--;
    }

}
int array_list::LocateElem(SqList l,ElemType e)
{
    int i;
    int flag=0;
    for(i=0;i<l.length;i++)
    {
        if(e==l.data[i])
        {
            flag=1;
            return i+1;
        }
    }
    if(0==flag)
    {
        return 0;
    }
}
bool array_list::ListInsert(SqList *l,int i,ElemType e)
{
    int k;
    if(l->length==MAXSIZE)
        return false;
    if(i<1||i>l->length)
        return false;
    if(i<l->length)
    {
        for(k=l->length-1;k>=i-1;k--)//插入从后开始插
            l->data[k+1]=l->data[k];
    }
    l->data[i-1]=e;
    l->length++;
    return true;
}
bool array_list::ListDelete(SqList *l,int i,ElemType &e)
{
    int k;
    if(l->length==0)
        return false;
    if(i<1||i>l->length)
        return false;
    e=l->data[i-1];
    if(i<l->length)
    {
        for(k=i;k<l->length;k++)
            l->data[k-1]=l->data[k];
    }
    l->length--;
    return true;
}
int array_list::ListLength(SqList l)
{
    return l.length;
}
