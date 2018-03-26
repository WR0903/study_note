# binary_search
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
void binary_find()
{
    vector<int> v1;
    v1.push_back(1);

    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    bool b = binary_search(v1.begin(),v1.end(),3);
    if(b==true)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
}
int main(int argc, char *argv[])
{
    //adj_find();
    binary_find();
    cout << "Hello World!" << endl;
    return 0;
}
```
