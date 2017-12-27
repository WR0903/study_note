# ubuntu16.04+Qt5.6配置opencv

## 首先确定自己安装ubuntu16.04,Qt5.6
* 更新源：`sudo apt-get update`
* 添加依赖项
```
sudo apt-get install build-essential
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
```
* 下载源码：
```
cd ~/<my_working_directory>  //比如工作目录为opencv即，`cd ~/opencv`
git clone https://github.com/Itseez/opencv.git
git clone https://github.com/Itseez/opencv_contrib.git
```
* CMake Opencv源码：建立一个编译目录（例如：/build）把cmake后的文件都放在这里边。
```
cd ~/opencv
mkdir build  //建立一个build目录，把cmake的文件都放着里边
cd build　　　//进入build目录
```
然后开始cmake，这里需要注意几个cmake的参数，比较重要。
```
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=<path to opencv_contrib/modules/> ..
```
**注：命令中最后的"  .. "（空格+两个点）千万不要忘记**  
其中 `CMAKE_BUILD_TYPE=Release / Debug`  
OPENCV_EXTRA_MODULES_PATH 就是用来指定要编译的扩展模块，后边加上刚下载的opencv_contrib模块的路径即可。
* 把代码编译成可执行文件，这里官方推荐使用多进程编译，推荐七个进程：
`make -j7 `# 并行运行七个jobs，这一步也在build目录中进行
* 安装。
`sudo make install`
到这里没有结束哦！！！  
* 上面的过程基本上完成了opencv的安装。但是并不能够马上用它，opencv还包含很多动态链接库。你可以在文件`/etc/ld.so.conf`中添加 `/usr/local/lib`（这个跟安装目录有关， `{CMAKE_INSTALL_PREFIX}/lib`），也可以在`/etc/ld.so.conf.d` 目录下增加一个conf文件（可以命名为 `opencv.conf`），同样添加 `/usr/local/lib`
`sudo gedit /etc/ld.so.conf.d/opencv.conf` 复制`/usr/local/lib`保存  
使用下面的动态库管理命令ldconfig，让opencv的相关链接库被系统共享
`sudo ldconfig -v #会列出各种库`
* 完成了动态库的共享，还不能使用opencv来编程，还需要为程序指定openvc的头文件位置。这里使用pkg-config命令来完成。
* 打开文件bash.bashrc `sudo gedit /etc/bash.bashrc`中添加如下代码  
`export  PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig ` 
## 测试
```
cd ~/opencv-3.1.0/sample
sudo camke
make
cd cpp
```
运行编译的文件
