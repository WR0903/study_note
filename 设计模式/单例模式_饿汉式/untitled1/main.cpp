#include <iostream>

using namespace std;

class Singelton
{
public:
    static Singelton *getInstance()
    {
        return m_pSingle;
    }
    static void freeInstance()
    {
        if(m_pSingle!=NULL)
        {
            delete m_pSingle;
            m_pSingle = NULL;
        }
        //return m_pSingle;
    }
private:
    Singelton()
    {
        cout<<"Singelton构造函数执行"<<endl;
    }
private:
    static Singelton *m_pSingle;
};
Singelton *Singelton::m_pSingle=new Singelton;
int main(int argc, char *argv[])
{
    cout<<"1"<<endl;//先执行全局变量,再从main执行.
    Singelton *p1=Singelton::getInstance();
    Singelton *p2=Singelton::getInstance();
    if(p1==p2)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    Singelton::freeInstance();
    cout << "Hello World!" << endl;
    return 0;
}
