# template_class
```
#include <iostream>

using namespace std;


template<typename T>
class Complex
{
public:
    Complex(T a=0,T b=0)
    {
        this->a=a;
        this->b=b;
    }
    void printCom()
    {
        cout<<"a:"<<a<<"b:"<<b<<endl;
    }
    Complex operator +(Complex &c2)
    {
       Complex tmp(a+c2.a,b+c2.b);
       return tmp;
    }
    //重载＜＜＞＞只能用友元函数，其他的正常
   friend ostream & operator <<(ostream &out,Complex &c3);
private:
    T a;
    T b;
};

ostream & operator <<(ostream &out,Complex<int> &c3)
{
    out<<"a:"<<c3.a<<"b:"<<c3.b<<endl;
}

int main(int argc, char *argv[])
{
    Complex<int> c1(1,2);
    c1.printCom();
    Complex<int> c2(3,4);
    Complex<int> c3=c1+c2;
    cout<<c3<<endl;
    cout << "Hello World!" << endl;
    return 0;
}
```
