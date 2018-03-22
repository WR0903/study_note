#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

using namespace std;


template <typename T>
class MyVector
{

public:
    MyVector(int size=0);
    MyVector(const MyVector &obj);
    ~MyVector();

public:
    T& operator[](int index);
    MyVector& operator=(const MyVector &obj);
    int getLen()
    {
        return m_len;
    }

//    ostream & operator << (ostream &out,const MyVector<int> &obj)
//    {

//            for(int i=0;i<obj.m_len;i++)
//            {
//                out<<obj.m_space[i]<<" ";
//            }
//            out<<endl;
//          return out;

//    }
private:
protected:
    T *m_space;
    int m_len;
};


#endif // MYVECTOR_H
