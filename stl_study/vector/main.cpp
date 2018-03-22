#include <iostream>

using namespace std;
#include <myvector.hpp>


int main(int argc, char *argv[])
{
    MyVector<int> myv1(10);
    for(int i=0;i<myv1.getLen();i++)
    {
        myv1[i]=i+1;
        cout<<myv1[i]<<" ";
    }
    cout<<endl;
    MyVector<int> myv2=myv1;
    for(int i=0;i<myv2.getLen();i++)
    {
        //myv2[i]=i+1;
        cout<<myv2[i]<<" ";
    }

    cout<<endl;
 //   cout<<myv2;
    cout << "Hello World!" << endl;
    return 0;
}
