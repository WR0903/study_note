# copy
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
void main_copy()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    vector<int> v2;
    v2.resize(v1.size());
    copy(v1.begin(),v1.end(),v2.begin());//拷贝
    printV(v2);
}

int main(int argc, char *argv[])
{
    //main_merge();
    //main_sort();
    //main_random_shuffle();
    //main_reverse();
    main_copy();
    cout << "Hello World!" << endl;
    return 0;
}
```
