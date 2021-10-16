# 使用c/c++扩展Python

使用python做开发的时候，如果有些业务对性能有要求，可以考虑使用c/c++来实现Python的模块，例如游戏开发中，可以使用Python完成一些玩法逻辑，但是技能结算等这些高密度计算部分如果放在python实现，那么性能不是很理想，这个时候可以把这部分弄到c/c++中来实现。

使用c/c++来写扩展模块，可以实现Python无法直接完成的功能，比如：

1、实现一个新的内建对象类型；

2、调用c/c++库函数和系统调用。

## 实现方案

### CMakeLists.txt编写

因为我们开发的是Python的扩展，所以必需include Python的头文件 <Python.h>。

在CMakeLists.txt中，可以使用 find_package 来自动寻找python的头文件路径。

```cmake
cmake_minimum_required(VERSION 3.10)
project(demo)
set(CMAKE_CXX_STANDARD 11)
find_package(PythonLibs 2.7 REQUIRED)
message(STATUS "Python Include = ${PYTHON_INCLUDE_DIRS}")
include_directories(${PYTHON_INCLUDE_DIRS})
add_library(${PROJECT_NAME} SHARED library.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
```

###  c++代码编写

我们接下来开发一个最简单的add函数。

首先，需要在代码中包含**Python头文件**：

```c++
#include <Python.h>
```

Python头文件中包含了Python的C API，注意：由于Python可能会定义一些预处理，并影响某些系统的标准头文件，因为必需将 #include <Python.h> 放在最前面。

接着来实现我们的**add函数**；

```c++
static PyObject* add(PyObject* self, PyObject* args){
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b)){
        return nullptr;
    }
    int sum = a + b;
    PyObject* ret = PyLong_FromLong(sum);
    return ret;
}
```

函数add的参数和返回值都是 PyObject*类型，参数 args 表示从Python中传进来的参数列表，可以用 PyArg_ParseTuple 转换为 C/C++的数据类型，最后再用 PyLong_FromLong 将计算结果转为PyObject*类型返回。

**方法列表**定义了我们这个模块中可以给外部调用的接口，比如：

```c++
static PyMethodDef MyDemoMethods[] = {
        {"addx", add, METH_VARARGS, "add two integers"},
        {nullptr, nullptr, 0, nullptr},
};
```

定义了一个 addx, 之后使用这个模块的时候就可以用 demo.addx(123, 456) 来进行调用了。

每一个方法定义由四个元素组成 {函数名称，函数实体，flag，函数描述}，其中flag一般是：METH_VARARGS 或者 METH_VARARGS|METH_KEYWORDS。

- METH_VARARGS: 表示函数期望python传进来的参数是一个可以被 PyArg_ParseTuple解析的元组；

- METH_KEYWORDS: 设置这个标志位表示传经来的参数支持keyword，这时候函数实现需要支持第三个参数 PyObject *，并用PyArg_ParseTupleAndKeywords 来解析参数，比如：

  ```c++
  static PyObject *hello3(PyObject *self, PyObject *args, PyObject *kwdict){
      int voltage;
      char *state = "a stiff";
      char *action = "voom";
      char *type = "Norwegian Blue";
      static char *kwlist[] = {"voltage", "state", "action", "type", nullptr};
      if (!PyArg_ParseTupleAndKeywords(args, kwdict, "i|sss", kwlist, &voltage, &state, &action, &type)){
          return nullptr;
      }
      printf("-- This parrot wouldn't %s if you put %i Volts throught it.\n", action, voltage);
      printf("-- Lovely plumage, the %s -- It's %s\n", type, state);
      Py_RETURN_NONE;
  }
  ```

  


在模块的初始化函数中，我们需要将方法列表传递给python解释器。**初始化函数**必须以 init*name*() 命名，*name*是模块名称，并且不需要定义为 static。

  ```
  PyMODINIT_FUNC initdemo(void){
      (void) Py_InitModule("demo", MyDemoMethods);
  }
  ```

  接着cmake常规编译。

## 模块调用

最后，就可以在Python脚本中调用我们写的扩展模块了。

```c++
# -*- coding: utf-8 -*-
import sys
sys.path.append("/home/wangran01/learncpp/pymodule/demo/cmake-build-debug-remote")
import demo

def main():
    print demo.addx(123, 456)

if __name__ == "__main__":
    main()
```

## 参考：

**[ChenJiehua](https://chenjiehua.me/)**的[《使用C/C++扩展Python》](https://chenjiehua.me/python/extending-python-with-cpp.html)

