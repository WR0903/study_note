#include <iostream>

using namespace std;
#include <myvector.h>


//template<typename T>
//ostream & operator << (ostream &out,const MyVector<int> &obj)
//{
//    for(int i=0;i<obj.m_len;i++)
//    {
//        out<<obj.m_space[i]<<" ";
//    }
//    out<<endl;
//  return out;
//}

template<typename T>
MyVector<T>::MyVector(int size)
{
    m_space=new T[size];
    m_len=size;
}

template<typename T>
T& MyVector<T>::operator[](int index)
{
    return m_space[index];
}

template<typename T>
MyVector<T>::MyVector(const MyVector &obj)
{
    m_len=obj.m_len;
    m_space=new T[m_len];
    for(int i=0;i<m_len;i++)
    {
        m_space[i]=obj.m_space[i];
    }
}

///home/wr/study/stl/untitled23/myvector.hpp:26: error: passing 'const MyVector<int>' as 'this' argument discards qualifiers [-fpermissive]
//         m_space[i]=obj[i];


template<typename T>
MyVector<T>::~MyVector()
{
    if(m_space!=NULL)
    {
        delete [] m_space;
        m_space=NULL;
        m_len=0;
    }
}

//public:


template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T> &obj)
{
    if(m_space!=NULL)
    {
        delete[] m_space;
        m_space=NULL;
        m_len=0;
    }
    m_len=obj.m_len;
    m_space=new T[m_len];
    for(int i=0;i<m_len;i++)
    {
        m_space[i]=obj.m_space[i];
    }
    return *this;
}
