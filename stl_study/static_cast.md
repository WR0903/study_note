# static_cast
```
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    double dpi=3.1415926;
    int num1=(int)dpi;//ｃ的风格
    int num2=static_cast<int>(dpi);//c++风格
    int num3=dpi;//c语言隐式转换

    cout<<num1<<" "<<num2<<" "<<num3<<endl;


    char *p1="henlnfaln  d";
    int * p2=NULL;
    p2=reinterpret_cast<int *>(p1);
    cout<<p1<<endl;
    cout<<p2<<endl;
    cout << "Hello World!" << endl;
    return 0;
}
```
