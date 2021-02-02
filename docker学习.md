## 常用得命令
* ```docker run -i -t ubuntu:15.10 /bin/bash```  
在docker容器里面运行ubuntu得镜像，然后运行/bin/bash程序.  
-t :在新容器内指定一个伪终端或终端。
-i: 允许你对容器内的标准输入 (STDIN) 进行交互。
-d:后台运行
* ```docker ps```
查看哪容器在运行，docker stop可以将对应得id得容器给停掉。停止的容器可以通过 docker restart 重启。docker attach可以进入某个容器
