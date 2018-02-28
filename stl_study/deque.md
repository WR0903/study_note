# deque
存放数据的双端容器，使用方法和vector相似
* 案例
```
#include <iostream>

using namespace std;
#include <deque>
#include <algorithm>

void printd(deque<int> &d)
{
    for(deque<int>::iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<endl;
    }
}

void deque1()
{
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(3);
    d1.push_back(5);

    d1.push_front(-5);
    d1.push_front(-3);
    d1.push_front(-1);
    printd(d1);
    cout<<"头部元素"<<d1.front()<<endl;
    cout<<"尾部元素"<<d1.back()<<endl;
    d1.pop_back();
   // d1.pop_front();
    printd(d1);
    deque<int>::iterator it=find(d1.begin(),d1.end(),-3);
    if(it!=d1.end())
    {
        cout<<"-3的下标"<<distance(d1.begin(),it)<<endl;
    }
}

int main(int argc, char *argv[])
{
    deque1();
    cout << "Hello World!" << endl;
    return 0;
}
```

