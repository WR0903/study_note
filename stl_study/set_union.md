# set_union
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
void main_union()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(3);
    v2.push_back(7);
    vector<int> v3;
    v3.resize(v1.size()+v2.size());
    set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    printV(v3);
}

int main(int argc, char *argv[])
{
    //main_merge();
    //main_sort();
    //main_random_shuffle();
    //main_reverse();
    //main_copy();
    //main_replace();
    //main_swap();
    //main_accumlate();
    main_union();
    cout << "Hello World!" << endl;
    return 0;
}
```
