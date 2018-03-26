# merge
```
#include <iostream>

using namespace std;
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

void  printV(vector<int> &v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }
}

void main_merge()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    vector<int> v2;
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);
    vector<int> v3;
    v3.resize(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    printV(v3);
}


int main(int argc, char *argv[])
{
    main_merge();
    cout << "Hello World!" << endl;
    return 0;
}
```
