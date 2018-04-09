#include <iostream>

using namespace std;
class BankWorker
{
public:
    BankWorker() {}
    void save()
    {
        cout<<"存款"<<endl;
    }
    void moveM()
    {
        cout<<"转账"<<endl;
    }
    void jiaofei()
    {
        cout<<"缴费"<<endl;
    }
};

class AvBankWorks
{
public:
    virtual void dothing()=0;
};

class SaveBanker : public AvBankWorks
{
public:
    SaveBanker() {}
    virtual void dothing()
    {
        cout<<"存款"<<endl;
    }
};

class MoveBanker : public AvBankWorks
{
public:
    MoveBanker() {}
    virtual void dothing()
    {
        cout<<"转账"<<endl;
    }
};
class jiaofeiBanker : public AvBankWorks
{
public:
    jiaofeiBanker() {}
    virtual void dothing()
    {
        cout<<"缴费"<<endl;
    }
};


int main(int argc, char *argv[])
{
    BankWorker *bw=new BankWorker;
    bw->jiaofei();
    bw->moveM();
    bw->save();
    cout << "Hello World!" << endl;
    AvBankWorks *b;//父类指针指向子类,有多态发生
    b=new MoveBanker;
    b->dothing();
    delete b;
    b=new SaveBanker;
    b->dothing();
    delete b;
    b=new jiaofeiBanker;
    b->dothing();
    delete b;
    return 0;
}
