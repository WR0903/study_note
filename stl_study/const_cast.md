# const_cast
```
#include <iostream>

using namespace std;


void printBuf(const char *p)
{
    char *p1=NULL;
    p1=const_cast<char *>(p);

    p1[0]='f';
    cout<<p1<<endl;
}

int main()
{

    char buf[]="sadfdadfasdf";
    printBuf(buf);
    return 0;

}
```
