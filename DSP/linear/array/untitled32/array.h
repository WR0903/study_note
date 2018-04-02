#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

#define MAXSIZE 20
typedef int ElemType;//修改存放数据类型
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

class array_list
{
private:
    SqList *L;
public:
    void InitList(SqList* l);
    bool ListEmpty(SqList l);
    void ClearList(SqList* l);
    bool GetElem(SqList l,int i,ElemType *e);
    int LocateElem(SqList l,ElemType e);
    bool ListInsert(SqList *l,int i,ElemType e);
    bool ListDelete(SqList *l,int i,ElemType *e);
    void ListLength(SqList l);
};


#endif // ARRAY_H
