# transform
```
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <functional>
#include <iterator>
void main42()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    printD(v1);
    cout<<endl;
    transform(v1.begin(),v1.end(),v1.begin(),increase);//回调函数
    printD(v1);
    cout<<endl;
    transform(v1.begin(),v1.end(),v1.begin(),negate<int>());//回调函数
    // 预定义函数，取负值
    printD(v1);
    cout<<endl;

    list<int>mylist;
    mylist.resize(v1.size());
    transform(v1.begin(),v1.end(),mylist.begin(),bind2nd(multiplies<int>(),10));
    // 函数适配器
    printL(mylist);
    //printD(v1);
    cout<<endl;
    transform(v1.begin(),v1.end(),ostream_iterator<int>(cout," "),negate<int>());
    cout<<endl;
}
int main(int argc, char *argv[])
{
    //main41();
    main42();
    cout << "Hello World!" << endl;
    return 0;
}
```
