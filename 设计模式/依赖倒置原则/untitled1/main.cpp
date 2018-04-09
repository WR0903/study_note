#include <iostream>

using namespace std;

class HardDisk
{
public:
    virtual void work()=0;
};
class Memory
{
public:
    virtual void work()=0;
};
class Cpu
{
public:
    virtual void work()=0;
};

class Computer
{
public:
    Computer(HardDisk *hardDisk,Memory *memory,Cpu *cpu)
    {
        m_HardDisk=hardDisk;
        m_Memory=memory;
        m_Cpu=cpu;
    }
    void work()
    {
        m_HardDisk->work();
        m_Memory->work();
        m_Cpu->work();
    }
private:
    HardDisk *m_HardDisk;
    Memory *m_Memory;
    Cpu *m_Cpu;
};

class InterCpu : public Cpu
{
public:
    void work()
    {
        cout<<"我是InterCpu"<<endl;
    }
};

class XSHardDisk :public HardDisk
{
public:
    void work()
    {
        cout<<"我是西部数据硬盘"<<endl;
    }
};

class JSDMemory :public Memory
{
public:
    void work()
    {
        cout<<"我是金士顿内存"<<endl;
    }
};


int main(int argc, char *argv[])
{
    HardDisk *hardDisk=NULL;
    Memory *memory=NULL;
    Cpu *cpu=NULL;
    hardDisk=new XSHardDisk;
    memory=new JSDMemory;
    cpu=new InterCpu;
    Computer *com=new Computer(hardDisk,memory,cpu);
    com->work();
    delete com;
//    delete cpu;
//    delete memory;
//    delete hardDisk;
    cout << "Hello World!" << endl;
    return 0;
}
