# queue
队列
* 基本的用法
```
queue<int> q;
q.push(1);
q.push(2);
q.push(3);
cout<<"front:"<<q.front()<<endl;
cout<<"size:"<<q.size()<<endl;
while(!q.empty())
{
    cout<<q.front()<<" ";
    q.pop();
}
```
除此之外，也可以放类和指针
```
class teacher
{
public:
    teacher() {}
    int age;
    char name[32];
public:
    void printT()
    {
        cout<<"age:"<<age<<endl;
    }
};

void queue2()
{
    teacher t1,t2,t3;
    t1.age=31;
    t2.age=32;
    t3.age=33;
    queue<teacher> q;
    q.push(t1);
    q.push(t2);
    q.push(t3);
    while(!q.empty())
    {
        teacher tmp=q.front();
        tmp.printT();
        q.pop();
    }
}
void queue3()
{
    teacher t1,t2,t3;
    t1.age=31;
    t2.age=32;
    t3.age=33;
    queue<teacher *> q;
    q.push(&t1);
    q.push(&t2);
    q.push(&t3);
    while(!q.empty())
    {
        teacher *tmp=q.front();
        tmp->printT();
        q.pop();
    }
}


```
