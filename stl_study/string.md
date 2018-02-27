# string
* 几种初始化   
```
string s1="aaa";
string s2("bbbb");//构造函数
string s3=s2;//拷贝初始化对象
string s4(10,'a');//１０个ａ
```
* string的遍历   
```
for(int i;i<s1.length();i++)//数组的方式
{
    cout<<s1[i]<<" ";
}

for(string::iterator it=s1.begin();it!=s1.end();it++)//迭代器的方式
{
    cout<<*it<<" ";
}
try
{
    for(int i;i<s1.length()+3;i++)//ａｔ方式
    {
        cout<<s1.at(i)<<" ";//可以抛出异常
    }
}
catch(...)//捕捉所有的异常
{
    cout<<"发生异常\n";
}
```
* string的拷贝
```
char buf1[128]={0 };
s1.copy(buf1,2,0);//拷贝
cout<<buf1<<endl;
````
* string to char  
```
string s1="aaabbbb";
printf("s1:%s\n",s1.c_str());
```
* string的连接
```
string s1="aaa";
string s2="bbb";
s1=s1+s2;//直接相加
cout<<s1<<endl;
string s3="333";
string s4="444";
s3.append(s4);
cout<<s3<<endl;
```

* string的查找替换
```
string s1="wbm 00 wbm 111 wbm 222 hello";
int index=s1.find("wbm",3);//位置坐标从０开始,3表示从第三位开始查找
cout<<"index:"<<index<<endl;
//求wbm出现的次数　和下标
int offindex=s1.find("wbm",0);
while (offindex!=string::npos)
{
    cout<<offindex<<endl;
    offindex=offindex+1;
    offindex=s1.find("wbm",offindex);
}

offindex=s1.find("wbm",0);
while (offindex!=string::npos)
{
    cout<<offindex<<endl;
    s1.replace(offindex,3,"WBM");//替换
    offindex=offindex+1;
    offindex=s1.find("wbm",offindex);
}
cout<<s1<<endl;
```

* string的删除和插入
```
string s1="hello hello1 hello2 ";
string::iterator it=find(s1.begin(),s1.end(),'l');
if(it!=s1.end())
{
    s1.erase(it);//删除
}
cout<<s1<<endl;
s1.erase(s1.begin(),s1.end());
cout<<s1.length()<<endl;
string s2="sssss";
s2.insert(3,"AAA");//在哪个位置插入
cout<<s2<<endl;
```









