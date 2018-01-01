# cmake study
**以下是cmake的简单实例，从helloslam开始**

* CMakeLists.txt文件编写

```
cmake_minimum_required(VERSION 2.8)     #声明要求的camke最低版本
project(HelloSlam)                      #声明一cmake工程
add_executable(helloSlam helloSlam.cpp) #添加一个可执行文件

add_library(hello libHelloSlam.cpp)      #生成静态库
add_library(hello_shared SHARED libHelloSlam.cpp)#生成动态库

add_executable(useHello useHelloSlam.cpp)      #添加可执行文件
target_link_libraries(useHello hello_shared)   #动态库的链接
```

* helloSlam.cpp文件编写
```
#include<iostream>  
using namespace std;
int main()
{
	cout<<"hello Slam"<<endl;
	return 0;
}

```

* 库文件的编写，不包含main()函数
```
#include<iostream>  //libHelloSlam.cpp
using namespace std;
void helloPrintf()
{
	cout<<"hello Slam1"<<endl;
}
```
```
#ifndef LIBHELLOSLAM_H_   ////libHelloSlam.h
#define LIBHELLOSLAM_H_
void helloPrintf();
#endif
```
* 调用库函数的cpp编写
```
#include "libHelloSlam.h"
int main()
{
	helloPrintf();
	return 0;
}
```
