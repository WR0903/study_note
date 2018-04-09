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

class Factory
{
public:
    Factory() {}
    Fruit *creat(int i)
    {
        if(i==0)
            return new Banana;
        else if(i==1)
            return new Apple;
        else
        {
            cout << "不支持"<<endl;
            return NULL;
        }
    }
};

int main(int argc, char *argv[])
{
    Factory *f=new Factory;
    Fruit *fr=NULL;
    fr=f->creat(0);
    fr->getFruit();
    //delete fr;
    fr=f->creat(1);
    fr->getFruit();
    //delete fr;

    delete f;

    cout << "Hello World!" << endl;
    return 0;
}
