# map
* 基本的用法
```
void map1()
{
    map<int,string> map1;//新建一个ｍａｐ
    map1.insert(pair<int,string>(1,"teacher01"));//插入
    map1.insert(pair<int,string>(2,"teacher02"));
    map1.insert(pair<int,string>(3,"teacher03"));

    map1.insert(make_pair(4,"teacher04"));
    map1.insert(make_pair(5,"teacher05"));

    map1.insert(map<int,string>::value_type(6,"teacher06"));

    map1[7]="teacher07";


    for(map<int,string>::iterator it=map1.begin();it!=map1.end();it++)//遍历
    {
        cout<<it->first<<"\t"<<it->second<<endl;
    }
    cout<<"end"<<endl;
    while(!map1.empty())
    {
        map<int,string>::iterator it=map1.begin();
        cout<<it->first<<"\t"<<it->second<<endl;
        map1.erase(it);//删除
    }
}
* 检查是否插入成功
```
pair<map<int,string>::iterator,bool> mypair4=map1.insert(make_pair(4,"teacher04"));
map1.insert(make_pair(5,"teacher05"));
if(mypair4.second==true)
{
    cout<<mypair4.first->second<<endl;
}
else
{
    cout<<"error"<<endl;
}
```

* map 的查找
```
void map3()
{
    map<int,string> map1;
    map1.insert(pair<int,string>(1,"teacher01"));
    map1.insert(pair<int,string>(2,"teacher02"));
    map1.insert(pair<int,string>(3,"teacher03"));

    map1.insert(make_pair(4,"teacher04"));
    map1.insert(make_pair(5,"teacher05"));

    map1.insert(map<int,string>::value_type(6,"teacher06"));

    map1[7]="teacher07";

    map<int,string>::iterator it =map1.find(100);//查找键值为１００的位置
    if(it==map1.end())
    {
        cout<<"key 100 doesn't exit;"<<endl;
    }
    else
    {
        cout<<it->first<<"\t"<<it->second<<endl;
    }
    pair<map<int,string>::iterator,map<int,string>::iterator> mypair= map1.equal_range(5);//返回两个迭代器，形成ｐａｉｒ
    //first : >=5   second : >5;
    if(mypair.first==map1.end())
    {
        cout<<"key doesn't exit;"<<endl;
    }
    else
    {
        cout<<mypair.first->first<<"\t"<<mypair.first->second<<endl;
    }

    if(mypair.second==map1.end())
    {
        cout<<"key doesn't exit;"<<endl;
    }
    else
    {
        cout<<mypair.second->first<<"\t"<<mypair.second->second<<endl;
    }
}
```

* multimap的基本用法
```
class Person
{
public:
    Person() {}
public:
    string name;
    int age;
    string tel;
    double saly;
};

void map1()
{
    Person p1,p2,p3,p4,p5;
    p1.name="wang1";
    p1.age=31;

    p2.name="wang2";
    p2.age=32;

    p3.name="zhang3";
    p3.age=33;

    p4.name="zhang4";
    p4.age=34;

    p5.name="zhao5";
    p5.age=35;
    multimap<string,Person> map2;
    map2.insert(make_pair("sale",p1));
    map2.insert(make_pair("sale",p2));

    map2.insert(make_pair("development",p3));
    map2.insert(make_pair("development",p4));

    map2.insert(make_pair("Financial",p5));

    for(multimap<string,Person>::iterator it=map2.begin();it!=map2.end();it++)
    {
        cout<<it->first<<"\t"<<it->second.name<<endl;
    }
    int num=map2.count("development");
    cout<<"development size:"<<num<<endl;
    multimap<string,Person>::iterator it1=map2.find("development");
    int flag=0;
    while(it1!=map2.end()&&flag<num)
    {
        cout<<it1->first<<"\t"<<it1->second.name<<endl;
        it1++;
        flag++;
    }
}
```

