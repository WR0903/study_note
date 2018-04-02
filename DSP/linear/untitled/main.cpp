#include <iostream>
#include <array.hpp>
using namespace std;

int main(int argc, char *argv[])
{
    array_list ll;
    ll.InitList(ll.L);
    ll.ListInsert(ll.L,1,1);
    ll.ListInsert(ll.L,2,2);
    ll.ListInsert(ll.L,3,3);
    ll.ListInsert(ll.L,4,4);
    ll.ListInsert(ll.L,5,5);
   // l.ClearList(l.L);
    bool a=ll.ListEmpty(ll.L);
    int b;
    ll.GetElem(ll.L,2,b);
    cout<<b<<endl;
    ll.ListDelete(ll.L,2,b);
    cout<<b<<endl;

    if(false==a)
    {
        for(int i=0;i<ll.L->length-1;i++)
        {
            cout<<ll.L->data[i]<<" ";
        }
    }
    cout << "Hello World!" << endl;
    return 0;
}
