#include <iostream>

using namespace std;

class Fruit
{
public:
    Fruit() {}
    virtual void SayName()=0;
};
class AbstractFactor
{
public:
    AbstractFactor() {}
    virtual Fruit *creatBanana()=0;
    virtual Fruit *creatApple()=0;
};



class NorthBanana :public Fruit
{
public:
    NorthBanana() {}
    virtual void SayName()
    {
        cout<<"我是北方香蕉"<<endl;
    }
};
class NorthApple :public Fruit
{
public:
    NorthApple() {}
    virtual void SayName()
    {
        cout<<"我是北方苹果"<<endl;
    }
};

class SouthBanana :public Fruit
{
public:
    SouthBanana() {}
    virtual void SayName()
    {
        cout<<"我是南方香蕉"<<endl;
    }
};
class SouthApple :public Fruit
{
public:
    SouthApple() {}
    virtual void SayName()
    {
        cout<<"我是南方苹果"<<endl;
    }
};

class NorthFacorty :public AbstractFactor
{
public:
    NorthFacorty() {}
    virtual Fruit *creatBanana()
    {
        return new NorthBanana;
    }
    virtual Fruit *creatApple()
    {
        return new NorthApple;
    }
};
class SouthFacorty :public AbstractFactor
{
public:
    SouthFacorty() {}
    virtual Fruit *creatBanana()
    {
        return new SouthBanana;
    }
    virtual Fruit *creatApple()
    {
        return new SouthApple;
    }
};

int main(int argc, char *argv[])
{
    Fruit *fruit=NULL;
    AbstractFactor *af=NULL;
    af=new SouthFacorty;
    fruit=af->creatApple();
    fruit->SayName();
    fruit=af->creatBanana();
    fruit->SayName();
    af=new NorthFacorty;
    fruit=af->creatApple();
    fruit->SayName();
    fruit=af->creatBanana();
    fruit->SayName();
    cout << "Hello World!" << endl;
    return 0;
}
