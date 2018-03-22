# template
```
#include <iostream>

using namespace std;

void myswap01(int &a,int &b)
{
    int c=0;
    c=a;
    a=b;
    b=c;

}

void myswap02(char &a,char &b)
{
    char c=0;
    c=a;
    a=b;
    b=c;

}

template<typename T>
void myswap(T &a,T &b)
{
    T c;
    c=a;
    a=b;
    b=c;
}
int main02()//函数魔板
{
    int x=10;
    int y=20;
    myswap<int>(x,y);
    cout<<x<<" "<<y;
    return 0;
}
int main11(int argc, char *argv[])
{
    int x=10;
    int y=20;
    myswap01(x,y);
    char a='a';
    char b='b';
    myswap02(a,b);

    cout<<"x:"<<x<<" "<<"y:"<<y;
    cout<<"a:"<<a<<" "<<"b:"<<b;
    cout << "Hello World!" << endl;
    return 0;
}
template<typename T>
int mySort(T *array,int size)
{
    int tmp;
    if(array==NULL)
    {
        return -1;
    }
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(array[i]<array[j])
            {
                tmp=array[i];
                array[i]=array[j];
                array[j]=tmp;
            }
        }
    }
    return 0;
}
template<typename T>
int printS(T *array,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}

int main()
{
    int myarray[]={11,3,445,22,453,322};
    int size=sizeof(myarray)/sizeof(*myarray);
    mySort<int>(myarray,size);
    printf("排序之后\n");
    printS<int>(myarray,size);
}
```
