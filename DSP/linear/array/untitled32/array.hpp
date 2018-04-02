#include <iostream>

#include <array.h>

using namespace std;

bool array_list::GetElem(SqList l,int i,ElemType *e)
{
    if(l.length==0||i<1||i>l.length)
        return false;
    *e=l.data[i-1];
    return true;
}



void array_list::InitList(SqList* l)
{

}
bool array_list::ListEmpty(SqList l)
{

}
void array_list::ClearList(SqList* l)
{

}
int array_list::LocateElem(SqList l,ElemType e)
{

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
bool array_list::ListDelete(SqList *l,int i,ElemType *e)
{
    int k;
    if(l->length==0)
        return false;
    if(i<1||i>l->length)
        return false;
    *e=l->data[i-1];
    if(i<l->length)
    {
        for(k=i;k<l->length;k++)
            l->data[k-1]=l->data[k];
    }
    l->length--;
    return true;
}
void array_list::ListLength(SqList l)
{

}
