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
