#include <iostream>

using namespace std;

class Fruit
{
public:
    Fruit() {}
    virtual void getFruit()=0;
};

class Banana :public Fruit
{
public:
    Banana() {}
    virtual void getFruit()
    {
        cout<<"我是香蕉"<<endl;
    }
};
class Apple :public Fruit
{
public:
    Apple() {}
    virtual void getFruit()
    {
        cout<<"我是苹果"<<endl;
    }
};

class AbFactory
{
public:
    AbFactory() {}
    virtual Fruit *creat()=0;
};

class BananaF :public AbFactory
{
public:
    BananaF() {}
    virtual Fruit *creat()
    {
        return new Banana;
    }
};

class AppleF :public AbFactory
{
public:
    AppleF() {}
    virtual Fruit *creat()
    {
        return new Apple;
    }
};

int main(int argc, char *argv[])
{
    AbFactory *f=NULL;
    Fruit *fruit=NULL;
    f=new AppleF;
    fruit=f->creat();
    fruit->getFruit();
    delete f;
    delete fruit;
    f=NULL;
    fruit=NULL;
    f=new BananaF;
    fruit=f->creat();
    fruit->getFruit();
    cout << "Hello World!" << endl;
    return 0;
}
