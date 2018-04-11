#include <iostream>

using namespace std;
#include <string>

class House
{
public:
    House() {}
    void setDoor(string door)
    {
        this->m_door=door;
    }
    void setWall(string wall)
    {
        this->m_wall=wall;
    }
    void setWindow(string window)
    {
        this->m_window=window;
    }
    string getDoor()
    {
        return this->m_door;
    }
    string getWall()
    {
        return this->m_wall;
    }
    string getWindow()
    {
        return this->m_window;
    }
private:
    string m_door;
    string m_wall;
    string m_window;
};
class Builder
{
public:
    Builder() {}
    virtual void buildWall()=0;
    virtual void buildDoor()=0;
    virtual void buildWindow()=0;
    virtual House *getHouse()=0;
};

class FlatBuilder :public Builder//公寓工程队
{
public:
    FlatBuilder()
    {
        m_house=new House;
    }
    virtual void buildWall()
    {
        m_house->setWall("公寓墙");
    }

    virtual void buildDoor()
    {
        m_house->setDoor("公寓门");
    }

    virtual void buildWindow()
    {
        m_house->setWindow("公寓窗");
    }

    virtual House *getHouse()
    {
        return m_house;
    }

private:
    House *m_house;
};

class VillaBuilder :public Builder//别墅工程队
{
public:
    VillaBuilder()
    {
        m_house=new House;
    }
    virtual void buildWall()
    {
        m_house->setWall("别墅墙");
    }

    virtual void buildDoor()
    {
        m_house->setDoor("别墅门");
    }

    virtual void buildWindow()
    {
        m_house->setWindow("别墅窗");
    }

    virtual House *getHouse()
    {
        return m_house;
    }

private:
    House *m_house;
};

class Director//设计师
{
public:
    Director(Builder *builder)
    {
        m_builder=builder;
    }
    void Construct()
    {
        m_builder->buildDoor();
        m_builder->buildWall();
        m_builder->buildWindow();
    }
private:
    Builder *m_builder;
};

int main(int argc, char *argv[])
{
    House *house=new House;
    Builder *builder=new VillaBuilder;
    Director *director=new Director(builder);//设计师指挥工程队干活
    director->Construct();
    house=builder->getHouse();
    cout<<house->getDoor()<<endl;
    cout<<house->getWall()<<endl;
    cout<<house->getWindow()<<endl;
    free(house);
    free(builder);
    free(director);
    builder=new FlatBuilder;
    director=new Director(builder);
    director->Construct();
    house=builder->getHouse();
    cout<<house->getDoor()<<endl;
    cout<<house->getWall()<<endl;
    cout<<house->getWindow()<<endl;
    free(house);
    free(builder);
    free(director);
    house=NULL;
    builder=NULL;
    director=NULL;
    cout << "Hello World!" << endl;
    return 0;
}
