# ros常用命令

**注:我使用的系统是ubuntu16.04，ros为kinetic** 
* `rospack find (roscpp)`获取软件包的相关信息
* `roscd (roscpp)`切换到`(roscpp)`软件包目录
* `rosls` 列举目录文件
* `catkin_create_pkg <package_name> [depend1] [depend2] [depend3]`创建catkin包
* `rospack depends (bao)`查看包的依赖项
* `rosrun [pakage_name] [node_name]` 运行一个节点
* `rosrun turtlesim turtle_teleop_key`按键输入
* ros包有改动的时候:
  ```
 catkin_make 编译
 source devel/setup.bash
 rospack profile

 ```
