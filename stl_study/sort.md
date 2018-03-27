# sort
```
#include <iostream>

using namespace std;
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <string>
class Student
{
public:
    string m_name;
    int m_id;
public:
    Student(string name,int id)
    {
        m_name=name;
        m_id=id;
    }

};
bool comperes(Student &s1,Student &s2)
{
    return(s1.m_id<s2.m_id);
}
void main_sort()
{
    Student s1("老大",1);
    Student s2("老二",2);
    Student s3("老三",3);
    Student s4("老四",4);
    vector<Student> v1;
    v1.push_back(s4);
    v1.push_back(s2);
    v1.push_back(s3);
    v1.push_back(s1);
    for(vector<Student>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<it->m_name<<" "<<it->m_id<<endl;
    }
    sort(v1.begin(),v1.end(),comperes);
    for(vector<Student>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<it->m_name<<" "<<it->m_id<<endl;
    }
}


int main(int argc, char *argv[])
{
    //main_merge();
    main_sort();
    cout << "Hello World!" << endl;
    return 0;
}
```
