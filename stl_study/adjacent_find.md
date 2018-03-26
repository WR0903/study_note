# adjacent_find
```
#include <iostream>

using namespace std;
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <functional>

void adj_find()
{
    vector<int> v1;
    v1.push_back(1);

    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(5);
   // vector<int> v2=v1;
    vector<int>::iterator it= adjacent_find(v1.begin(),v1.end());
    if(it==v1.end())//返回第一个重复的迭代器
    {
        cout<<"没有找到"<<endl;
    }
    else
    {
        cout<<*it<<endl;
    }
    int index=distance (v1.begin(),it);
    cout<<index<<endl;
}
int main(int argc, char *argv[])
{
    adj_find();
    cout << "Hello World!" << endl;
    return 0;
}
```
