# stack
栈容器，先进后出．
* 栈的定义
```
stack<int> s;//定义一个栈
for(int i=0;i<10;i++)
{
    s.push(i+1);//栈中加入元素
}
cout<<"size:"<<s.size()<<endl;
while(!s.empty())
{
    int tmp=s.top();//获取栈顶元素
    cout<<tmp<<" ";
    s.pop();//栈顶元素弹出
}
```
除此之外，栈中还可以放入对象和指针
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
void stack2()
{
    teacher t1,t2,t3;
    t1.age=31;
    t2.age=32;
    t3.age=33;

    stack<teacher> s;
    s.push(t1);
    s.push(t2);
    s.push(t3);
    while(!s.empty())
    {
        teacher tmp=s.top();
        tmp.printT();
        s.pop();
    }
}

void stack3()
{
    teacher t1,t2,t3;
    t1.age=31;
    t2.age=32;
    t3.age=33;

    stack<teacher *> s;
    s.push(&t1);
    s.push(&t2);
    s.push(&t3);
    while(!s.empty())
    {
        teacher *p=s.top();
        p->printT();
        s.pop();
    }
}
```

