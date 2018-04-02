#include <iostream>
#include <array.hpp>
#include <linear.hpp>
using namespace std;


void array()
{
    cout<<"array"<<endl;
    array_list ll;
    ll.InitList();
    ll.ListInsert(1,1);
    ll.ListInsert(2,2);
    ll.ListInsert(3,3);
    ll.ListInsert(4,4);
    ll.ListInsert(5,5);
   // l.ClearList(l.L);
    bool a=ll.ListEmpty();
    int b;
    ll.GetElem(2,b);
    cout<<b<<endl;
    ll.ListDelete(2,b);
    cout<<b<<endl;

    if(false==a)
    {
        for(int i=0;i<ll.L->length-1;i++)
        {
            cout<<ll.L->data[i]<<" ";
        }
    }
}
int main(int argc, char *argv[])
{
    //array();
    cout << "Hello World!" << endl;
    linear_list y;
    y.InitList();
    //y.ClearList();
    LinkList tmp;

    tmp=y.LL->next;
    for(int i=0;i<y.n;i++)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }

    return 0;
}
