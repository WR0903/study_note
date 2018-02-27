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










