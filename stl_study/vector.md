# vector
存放元素的容器
* 容器的声明和放入元素以及删除元素  
```
vector<int> v1;
v1.push_back(1);
v1.pop_back();
```
* 容器迭代器  
`vector<int>::iterator it;`  
* 容器的开始和结尾  
`v1.begin();//指针`  
`v1.end();`  
`v1.front()=10;//获取头部元素`
`v1.back()=88;//获取尾部元素`
* 算法的计数  
`int num1=count(v1.begin(),v1.end(),3);//计算v1容器中３的个数`  

* 设计案例  
```
#include <iostream>

using namespace std;
#include <vector>
#include <algorithm>

void vect1()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<endl;
    }

    int num1=count(v1.begin(),v1.end(),3);
    cout<<num1<<endl;
}

class teacher
{
public:
    int age;
    char namep[64];
    void printT()
    {
      cout<<"age:"<<endl;
    }
protected:
private:
};
void vect2()
{
    teacher t1,t2,t3;
    t1.age=31;
    t2.age=32;
    t3.age=33;
    vector<teacher> v1;
    v1.push_back(t1);
    v1.push_back(t2);
    v1.push_back(t3);
    for(vector<teacher>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<it->age<<endl;
    }

    //int num1=count(v1.begin(),v1.end(),3);
    //cout<<num1<<endl;
}

void vect3()
{
    teacher t1,t2,t3;
    t1.age=31;
    t2.age=32;
    t3.age=33;
    teacher *p1,*p2,*p3;
    p1=&t1;
    p2=&t2;
    p3=&t3;
    vector<teacher *> v1;//把ｔｅａｃｈｅｒ的内存首地址放在容器里
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    for(vector<teacher *>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<(*it)->age<<endl;
    }

    //int num1=count(v1.begin(),v1.end(),3);
    //cout<<num1<<endl;
}

int main(int argc, char *argv[])
{

    vect1();
    vect2();
    vect3();
    cout << "Hello World!" << endl;
    return 0;
}
```
