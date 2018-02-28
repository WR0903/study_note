#set
是个集合，元素唯一，自动排序，不能按照数组方式插入，红黑树,从小到大
* 基本操作
```
void set1()
{
    set<int> set1;
    for(int i=0;i<5;i++)
    {
        int tmp=rand();
        set1.insert(tmp);
    }
    set1.insert(100);
    set1.insert(100);
    set1.insert(100);
    for(set<int>::iterator it=set1.begin();it!=set1.end();it++)
    {
        cout<<*it<<" ";
    }
    while(!set1.empty())
    {
        set<int>::iterator it=set1.begin();
        cout<<*it<<endl;
        set1.erase(it);
    }
}
```
```
void set2()
{
    set<int,greater<int>> set3;//从大到小
    for(int i=0;i<5;i++)
    {
        int tmp=rand();
        set3.insert(tmp);
    }
    set3.insert(100);
    set3.insert(100);
    set3.insert(100);
    for(set<int>::iterator it=set3.begin();it!=set3.end();it++)
    {
        cout<<*it<<" ";
    }
    while(!set3.empty())
    {
        set<int>::iterator it=set3.begin();
        cout<<*it<<endl;
        set3.erase(it);
    }
}
```
* 对类的排序机制
```
class student
{
public:
    student(string name,int age)
    {
        this->name=name;
        this->age=age; 
    }
public:
    string name;
    int age;
};
struct Funcstudent//仿函数
{
    bool operator()(const student &left,const student &right)
    {
        if(left.age<right.age)//如果左边的小，就返回真，从小到大按照年龄进行排序
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
void set3()
{

    student s1("s1",31);
    student s2("s2",32);
    student s3("s3",33);
    student s4("s4",34);
　　　　student s5("s5",34);
    set<student,Funcstudent> set1;
    set1.insert(s1);
    set1.insert(s2);
    set1.insert(s3);
    set1.insert(s4);
　　　　set1.insert(s5);//没有插入成功
    for(set<student,Funcstudent>::iterator it=set1.begin();it!=set1.end();it++)
    {
        cout<<it->age<<"\t"<<it->name<<endl;
    }
}
```
