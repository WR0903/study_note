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
* priority_queue
```
void queue1()
{
    priority_queue<int> p1;//默认是最大值优先队列
    priority_queue<int, vector<int>,less<int>> p2;//最大值优先队列
    priority_queue<int, vector<int>,greater<int>> p3;//最小值优先队列
    p1.push(33);
    p1.push(11);
    p1.push(55);
    p1.push(22);
    cout<<"top"<<p1.top()<<endl;
    cout<<"size"<<p1.size()<<endl;
    while(p1.size()>0)
    {
        cout<<p1.top()<<" ";
        p1.pop();
    }
    cout<<endl;
    p3.push(33);
    p3.push(11);
    p3.push(55);
    p3.push(22);
    cout<<"top"<<p3.top()<<endl;
    cout<<"size"<<p3.size()<<endl;
    while(p3.size()>0)
    {
        cout<<p3.top()<<" ";
        p3.pop();
    }
}
```

