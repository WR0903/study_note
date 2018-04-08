#include <iostream>

using namespace std;
#define maxsize 9//数据大小

/*.....在结构体里即有数组,也有数组里数据大小,方便后面读取....*/
typedef struct
{
    int r[maxsize+1];
    int length;
} SqList;

/*.....创建数组....*/
void creatL(SqList *L)
{
    cout<<"请输入数据的大小"<<endl;
    cin>>L->length;
    cout<<"请输入每个数据"<<endl;
    for(int i=1;i<=L->length;i++)
        cin>>L->r[i];
    cout<<"原始数组为:"<<endl;
    for(int i=1;i<=L->length;i++)
        cout<<L->r[i]<<" ";
    cout<<endl;
}

/*.....交换数组里面任意两个元素的位置....*/
void swap(SqList *L,int i,int j)
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
/*.....将小于枢轴的元素放在左面,大于枢轴的元素放在右边....*/
int Partition(SqList *L,int low,int hight)
{
    int pivotkey;
    pivotkey=L->r[low];
    while(low<hight)
    {
        while(low<hight&&L->r[hight]>=pivotkey)
            hight--;
        swap(L,low,hight);
        while(low<hight&&L->r[low]<=pivotkey)
            low++;
        swap(L,low,hight);
    }
    return low;
}
/*.....用递归进行快排....*/
void QSort(SqList *L,int low,int hight)
{
    int pivot;
    if(low<hight)
    {
        pivot=Partition(L,low,hight);
        QSort(L,low,pivot-1);
        QSort(L,pivot+1,hight);
    }
}

int main(int argc, char *argv[])
{

    SqList *l;
    l=new SqList;
    creatL(l);
    QSort(l,1,l->length);
    for(int i=1;i<=l->length;i++)
        cout<<l->r[i]<<" ";
    cout<<endl;
    cout << "Hello World!" << endl;
    return 0;
}
