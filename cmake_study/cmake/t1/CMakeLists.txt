PROJECT (HELLO)#工程名字
SET(SRC_LIST main.c)#源文件列表
MESSAGE(STATUS /home/wr/WHR/cmake_study/cmake/t1/build ${HELLO_BINARY_DIR})#在该目录下生成二进制文件
MESSAGE(STATUS /home/wr/WHR/cmake_study/cmake/t1 ${HELLO_SOURCE_DIR})#在该目录下找到源文件
ADD_EXECUTABLE(hello ${SRC_LIST})#把原件加到工程里
