# for_each
```
#include <iostream>

using namespace std;
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <functional>

void printD(vector<int> &v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
}
void showV(int &n)
{
    cout<<n<<" ";
}
class cmyshow
{
public:
    cmyshow()
    {
        m=0;
    }
    void operator()(int &n)
    {
        m++;
        cout<<n<<" ";
    }
    void printM()
    {
        cout<<"mum:"<<m<<" ";
    }
private:
    int m;
};
void main41()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    printD(v1);
    cout<<endl;
    cmyshow mya;//mya 传给形参
    cmyshow my1=for_each(v1.begin(),v1.end(),mya);//函数对象，回调函数
    //形参的值返回到 my1
    cout<<endl;
    for_each(v1.begin(),v1.end(),showV);//函数对象，回调函数
    cout<<endl;
    my1.printM();
    mya.printM();
}

int main(int argc, char *argv[])
{
    main41();
    cout << "Hello World!" << endl;
    return 0;
}
```
