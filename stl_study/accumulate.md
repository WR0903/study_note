# accumulate
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
void main_accumlate()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    int tmp=accumulate(v1.begin(),v1.end(),100);//v1的所有成员累加，再加１００
    cout<<tmp<<endl;
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
    main_accumlate();
    cout << "Hello World!" << endl;
    return 0;
}
```
