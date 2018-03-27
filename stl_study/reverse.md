# reverse
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
void main_reverse()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    reverse(v1.begin(),v1.end());//逆序排序
    printV(v1);
}

int main(int argc, char *argv[])
{
    //main_merge();
    //main_sort();
    //main_random_shuffle();
    main_reverse();
    cout << "Hello World!" << endl;
    return 0;
}
```
