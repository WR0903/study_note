# algorithm
* for_each用法，find_if用法，transform用法，sort用法
```
#include <iostream>

using namespace std;
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <functional>

//template<typename T>
template <typename T>
class ShowElemt
{
public:
    //ShowElemt() {}
    void operator()(T &t)
    {
         cout<<t<<" ";
    }
};

void main01()
{
    int a=10;
    ShowElemt<int> showElemt;
    showElemt(a);//像个函数，仿函数
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    for_each(v1.begin(),v1.end(),ShowElemt<int>());//匿名仿函数对象

}
template<typename T>
class IsDiv
{
public:
    IsDiv(const T &divisor) {
        this->divisor=divisor;
    }
    bool operator()(T &t)
    {
        return(t%divisor==0);
    }
private:
    T divisor;
};
void main02()
{
    vector<int> v2;
    for(int i=10;i<33;i++)
    {
        v2.push_back(i);
    }
    int a=4;
    IsDiv<int>mydiv(a);
    vector<int>::iterator it;
    it=find_if(v2.begin(),v2.end(),IsDiv<int>(a));
    if(it!=v2.end())
    {
        cout<<*it<<endl;
    }
}

template<typename T>
class SumAdd
{
public:
    SumAdd() {}
    T operator()(T &t1,T &t2)
    {
        return t1+t2;
    }
};

void main03()
{
    vector<int> v1,v2;
    vector<int> v3;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);

    v3.resize(10);
    transform(v1.begin(),v1.end(),v2.begin(),v3.begin(),SumAdd<int>());//二元谓词
    for(vector<int>::iterator it=v3.begin();it!=v3.end();it++)
    {
        cout<<*it<<endl;
    }
}

bool MyCompare(const int &a,const int &b)
{
    return a<b;
}
void main04()
{
    vector<int> v1(10);
    for(int i=0; i<10;i++)
    {
        int tmp=rand()%100;
        v1[i]=tmp;
    }
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<endl;
    }
    cout<<endl;
    sort(v1.begin(),v1.end(),MyCompare);//排序算法
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<endl;
    }
}

int main(int argc, char *argv[])
{
   // main01();
    main04();
    cout << "Hello World!" << endl;
    return 0;
}
```
