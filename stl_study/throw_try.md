# throw_try
```
#include <iostream>

using namespace std;

void divide(int x,int y)
{
    if (y==0)
    {
        throw x;//异常跨函数
    }
    cout<<"divide结果"<<x/y<<endl;
}

int main(int argc, char *argv[])
{
    try
    {
       divide(10,2);
       divide(10,0);
    }
    catch(int e)
    {
        cout<<e<<"不能被０整除"<<endl;
    }
    catch(...)//其他的异常
    {
        cout<<"其他的异常"<<endl;
    }
    cout << "Hello World!" << endl;
    return 0;
}
```
