#include <iostream>
//#include <process.h>
//#include <windows.h>
#include <unistd.h>
#include <pthread.h>


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
    static void prints()
    {
        cout<<coute++<<endl;
    }
private:
    Singelton()
    {
        cout<<"Singelton构造函数执行"<<endl;
    }
private:
    static Singelton *m_pSingle;
    static int coute;
};
Singelton *Singelton::m_pSingle=NULL;
int Singelton::coute=0;

void *thread(void *ptr)
{

    Singelton::getInstance()->prints();
    return 0;
}
void *thread1(void *ptr)
{

    Singelton::getInstance()->prints();
    return 0;
}
void *thread2(void *ptr)
{

    Singelton::getInstance()->prints();
    return 0;
}
void *thread3(void *ptr)
{

    Singelton::getInstance()->prints();
    return 0;
}
void *thread4(void *ptr)
{

    Singelton::getInstance()->prints();
    return 0;
}

int main(int argc, char *argv[])
{
    pthread_t id;
    pthread_t idd;
    pthread_t idd1;
    pthread_t idd2;
    pthread_t idd3;
    int ret = pthread_create(&id, NULL, thread, NULL);
    if(ret) {
        cout << "Create pthread error!" << endl;
        return 1;
    }
    pthread_join(id, NULL);//等待线程结束
    int retd = pthread_create(&idd, NULL, thread1, NULL);
    if(retd) {
        cout << "Create pthread error!" << endl;
        return 1;
    }

    int retd1 = pthread_create(&idd1, NULL, thread2, NULL);
    if(retd1) {
        cout << "Create pthread error!" << endl;
        return 1;
    }
    int retd2 = pthread_create(&idd2, NULL, thread3, NULL);
    if(retd2) {
        cout << "Create pthread error!" << endl;
        return 1;
    }
    int retd3 = pthread_create(&idd3, NULL, thread4, NULL);
    if(retd3) {
        cout << "Create pthread error!" << endl;
        return 1;
    }



    pthread_join(idd, NULL);//等待线程结束
    pthread_join(idd1, NULL);//等待线程结束
    pthread_join(idd2, NULL);//等待线程结束
    pthread_join(idd3, NULL);//等待线程结束

    for(int i = 0;i < 3;i++) {
        cout <<  "This is the main process." << endl;
        sleep(1);
    }

    cout << "Hello World!" << endl;
    return 0;
}
