#include <iostream>

using namespace std;

class Singelton
{
public:
    static Singelton *getInstance()
    {
        if(m_pSingle==NULL)
        {
            m_pSingle=new Singelton;
        }
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
Singelton *Singelton::m_pSingle=NULL;
int main(int argc, char *argv[])
{
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
