# for_each() pk transform()
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
void showV(int &n)
{
    cout<<n<<" ";
}

int showV2(int n)
{
    cout<<n<<" ";
    return n;
}
void main43()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    vector<int> v2=v1;
    //for_each()  对函数对象的要求，没有返回值，一般引用
    for_each(v1.begin(),v1.end(),showV);
    cout<<endl;
    transform(v2.begin(),v2.end(),v2.begin(),showV2);
    //transform对函数对象的要求,有返回值，不引用
}
int main(int argc, char *argv[])
{
    //main41();
    main43();
    cout << "Hello World!" << endl;
    return 0;
}
```

