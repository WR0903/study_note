#ifndef LINEAR_H
#define LINEAR_H

#include <iostream>
using namespace std;


typedef int ElemType;//修改存放数据类型
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

class linear_list
{
public:
    LinkList LL;
    int n;

public:
    void InitList();
    bool ListEmpty();
    void ClearList();
    bool GetElem(int i,ElemType &e);
    int LocateElem(ElemType e);
    bool ListInsert(int i,ElemType e);
    bool ListDelete(int i,ElemType &e);
    int ListLength();
};



#endif // LINEAR_H
