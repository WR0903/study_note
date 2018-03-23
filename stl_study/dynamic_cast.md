# dynamic_cast
```
#include <iostream>

using namespace std;
class Animal
{
public:
    virtual void cry()=0;
};
class Dog:public Animal
{
public:
    virtual void cry()
    {
        cout<<"汪汪"<<endl;
    }
    void dohome()
    {
        cout<<"看家"<<endl;
    }
};

class Cat:public Animal
{
public:
    virtual void cry()
    {
        cout<<"喵喵"<<endl;
    }
    void dothing()
    {
        cout<<"抓老鼠"<<endl;
    }
};

void playObj(Animal *base)
{
    base->cry();//有继承，虚函数重写，父类指针，指向子类对象
    //dynamic_cast 运行时类型识别
    Dog * pDog=dynamic_cast<Dog *>(base);//向下转向　把父类转换成子类
    if (pDog!=NULL)
    {
        pDog->dohome();
    }

    Cat * pCat=dynamic_cast<Cat *>(base);
    if (pCat!=NULL)
    {
        pCat->dothing();
    }
}

int main()
{
    Dog d1;
    Cat c1;
    playObj(& d1);
    playObj(& c1);
}
```

