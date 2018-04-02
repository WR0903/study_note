#include <iostream>

#include <array.h>

using namespace std;

bool array_list::GetElem(int i,ElemType &e)
{
    if(L->length==0||i<1||i>L->length)
        return false;
    e=L->data[i-1];
    return true;
}



void array_list::InitList()
{

    L->length=1;

}
bool array_list::ListEmpty()
{
    if(L->length==0)
        return true;
    else
        return false;
}
void array_list::ClearList()
{
    while(L->length>0)
    {
        L->data[L->length-1]=0;
        L->length--;
    }

}
int array_list::LocateElem(ElemType e)
{
    int i;
    int flag=0;
    for(i=0;i<L->length;i++)
    {
        if(e==L->data[i])
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
bool array_list::ListInsert(int i,ElemType e)
{
    int k;
    if(L->length==MAXSIZE)
        return false;
    if(i<1||i>L->length)
        return false;
    if(i<L->length)
    {
        for(k=L->length-1;k>=i-1;k--)//插入从后开始插
            L->data[k+1]=L->data[k];
    }
    L->data[i-1]=e;
    L->length++;
    return true;
}
bool array_list::ListDelete(int i,ElemType &e)
{
    int k;
    if(L->length==0)
        return false;
    if(i<1||i>L->length)
        return false;
    e=L->data[i-1];
    if(i<L->length)
    {
        for(k=i;k<L->length;k++)
            L->data[k-1]=L->data[k];
    }
    L->length--;
    return true;
}
int array_list::ListLength()
{
    return L->length;
}
