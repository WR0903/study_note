# list
双向列表
* 基本用法
```
list<int> l;
cout<<"size:"<<l.size()<<endl;
for(int i;i<10;i++)
{
    l.push_back(i);//尾部插入
}
cout<<"size:"<<l.size()<<endl;
list<int>::iterator it=l.begin();
while(it!=l.end())
{
    cout<<*it<<" ";
    it++;
}
it=l.begin();
it++;//不支持it+5,成员不能随机访问
it++;
it++;
it++;
l.insert(it,100);
for(list<int>::iterator it1=l.begin();it1!=l.end();it1++)
{
    cout<<*it1<<" ";
}
```
* list删除成员
```
list<int> l;
cout<<"size:"<<l.size()<<endl;
for(int i;i<10;i++)
{
    l.push_back(i);//尾部插入
}
cout<<"size:"<<l.size()<<endl;
for(list<int>::iterator it1=l.begin();it1!=l.end();it1++)
{
    cout<<*it1<<" ";
}
cout<<endl;
list<int>::iterator it1=l.begin();
list<int>::iterator it2=l.begin();
it2++;
it2++;
it2++;
l.erase(it1,it2);//[it1,it2)删除区间
for(list<int>::iterator it1=l.begin();it1!=l.end();it1++)
{
    cout<<*it1<<" ";
}
cout<<endl;
l.remove(5);//删除所有＝５的数
for(list<int>::iterator it1=l.begin();it1!=l.end();it1++)
{
    cout<<*it1<<" ";
}
```
