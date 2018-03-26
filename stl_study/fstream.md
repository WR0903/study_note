# fstream.md
```
#include <iostream>

using namespace std;
#include <fstream>

int main(int argc, char *argv[])
{
    char* fname="2.txt";
    ofstream fout(fname,ios::app);//输出流,和文件相关联，输出流就是文件
    fout<<"hello....."<<endl;
    fout<<"hello....."<<endl;
    fout<<"hello....."<<endl;
    fout.close();

    ifstream fin(fname);//建立一个输入流，和文件相关联
    char ch;
    while(fin.get(ch))
    {
        cout<<ch;
    }
    fin.close();
    cout << "Hello World!" << endl;
    return 0;
}
```
