# replace
```
#include <iostream>

using namespace std;
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <string>

void  printV(vector<int> &v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }
}
bool greater_equal_7(int &n)
{
    if(n>=7)
    {
        return true;
    }
    return false;
}

void main_replace()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    replace(v1.begin(),v1.end(),3,8);//把所有的３替换成８
    printV(v1);
    replace_if(v1.begin(),v1.end(),greater_equal_7,1);//所有＞＝７的改成１
    printV(v1);
}

int main(int argc, char *argv[])
{
    //main_merge();
    //main_sort();
    //main_random_shuffle();
    //main_reverse();
    //main_copy();
    main_replace();
    cout << "Hello World!" << endl;
    return 0;
}
```
