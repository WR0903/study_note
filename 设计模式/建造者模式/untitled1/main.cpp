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

class Build
{
public:
    Build()
    {
        m_house=new House;
    }

    void makeBuild()
    {
        buildDoor(m_house);
        buildWall(m_house);
        buildWindow(m_house);
    }

    void buildDoor(House *h)
    {
        h->setDoor("门");
    }

    void buildWall(House *h)
    {
        h->setWall("墙");
    }

    void buildWindow(House *h)
    {
        h->setWindow("窗");
    }
    House *getHouse()
    {
        return m_house;
    }
private:
    House *m_house;
};

int main(int argc, char *argv[])
{
    /*客户直接造房子
    House *house=new House;
    house->setDoor("门");
    house->setWall("墙");
    house->setWindow("窗");
    */
    Build *mybuild=new Build;
    House *myHouse=NULL;
    mybuild->makeBuild();
    myHouse=mybuild->getHouse();
    cout<<myHouse->getDoor()<<endl;
    cout<<myHouse->getWall()<<endl;
    cout<<myHouse->getWindow()<<endl;
    cout << "Hello World!" << endl;
    return 0;
}
