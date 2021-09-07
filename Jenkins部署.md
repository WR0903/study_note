# Jenkins部署



打开docker引擎,然后运行

```sh
pull jenkins/jenkins
```

```shell
docker run -d --name jenkins -p 8080:8080 jenkins/jenkins
```



 此时打开浏览器，127.0.0.1:8080,网站会让你输入密码，两个方式获得密码：

1、进入容器

```shell
docker ps
docker exec -it xxxx(容器id) /bin/bash
# 然后根据网站提示进入相应目录获得密码
```

2、根据log获取

```shell
docker logs jenkins
```



输入密码后，jenkins后面的配置就容易了，然后就可以愉快的玩耍了。