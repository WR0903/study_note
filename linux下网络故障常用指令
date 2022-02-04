## linux下网络故障常用的几个命令

### ifconfig

```sh
ubuntu@VM-0-3-ubuntu:~$ ifconfig
docker0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        inet 172.17.0.1  netmask 255.255.0.0  broadcast 172.17.255.255
        ether 02:42:49:13:91:23  txqueuelen 0  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

eth0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 172.16.0.3  netmask 255.255.240.0  broadcast 172.16.15.255
        inet6 fe80::5054:ff:fe9b:8405  prefixlen 64  scopeid 0x20<link>
        ether 52:54:00:9b:84:05  txqueuelen 1000  (Ethernet)
        RX packets 48359052  bytes 4512423724 (4.5 GB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 47191232  bytes 4195297257 (4.1 GB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 1352984  bytes 110930762 (110.9 MB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 1352984  bytes 110930762 (110.9 MB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

```

可以方便的查看本机的几个网卡

### ping

```sh
ubuntu@VM-0-3-ubuntu:~$ ping www.baidu.com
PING www.a.shifen.com (14.215.177.39) 56(84) bytes of data.
64 bytes from 14.215.177.39 (14.215.177.39): icmp_seq=1 ttl=54 time=2.88 ms
64 bytes from 14.215.177.39 (14.215.177.39): icmp_seq=2 ttl=54 time=2.79 ms
64 bytes from 14.215.177.39 (14.215.177.39): icmp_seq=3 ttl=54 time=2.78 ms
64 bytes from 14.215.177.39 (14.215.177.39): icmp_seq=4 ttl=54 time=2.84 ms
64 bytes from 14.215.177.39 (14.215.177.39): icmp_seq=5 ttl=54 time=2.90 ms
^C
--- www.a.shifen.com ping statistics ---
5 packets transmitted, 5 received, 0% packet loss, time 4006ms
rtt min/avg/max/mdev = 2.781/2.837/2.898/0.047 ms

```

可以查看目标机器是否ping通

### telnet

```sh
ubuntu@VM-0-3-ubuntu:~$ telnet 127.0.0.1 3000
Trying 127.0.0.1...
Connected to 127.0.0.1.
Escape character is '^]'.
sfsdf
```

### netstat

```sh
ubuntu@VM-0-3-ubuntu:~$ netstat -atn
Active Internet connections (servers and established)
Proto Recv-Q Send-Q Local Address           Foreign Address         State
tcp        0      0 0.0.0.0:111             0.0.0.0:*               LISTEN
tcp        0      0 172.17.0.1:53           0.0.0.0:*               LISTEN
tcp        0      0 172.16.0.3:53           0.0.0.0:*               LISTEN
tcp        0      0 127.0.0.1:53            0.0.0.0:*               LISTEN
tcp        0      0 127.0.0.53:53           0.0.0.0:*               LISTEN
tcp        0      0 0.0.0.0:22              0.0.0.0:*               LISTEN
tcp        0      0 0.0.0.0:3000            0.0.0.0:*               LISTEN
tcp        0      0 0.0.0.0:3000            0.0.0.0:*               LISTEN
tcp        0      0 127.0.0.1:953           0.0.0.0:*               LISTEN
tcp        0      0 127.0.0.1:6010          0.0.0.0:*               LISTEN
tcp        0      0 127.0.0.1:6011          0.0.0.0:*               LISTEN
tcp        0      0 127.0.0.1:6012          0.0.0.0:*               LISTEN
tcp        0      0 127.0.0.1:6013          0.0.0.0:*               LISTEN
tcp        0      0 172.16.0.3:111          206.81.10.86:58812      ESTABLISHED
tcp        0      0 172.16.0.3:22           183.198.11.196:21580    ESTABLISHED
tcp        0      0 127.0.0.1:3000          127.0.0.1:58318         TIME_WAIT
tcp        0      0 172.16.0.3:22           183.198.11.196:21602    ESTABLISHED
tcp        0      0 172.16.0.3:22           183.198.11.196:22039    ESTABLISHED
tcp        0      0 172.16.0.3:39816        169.254.0.55:5574       ESTABLISHED
tcp        0      0 172.16.0.3:111          192.3.116.182:46844     ESTABLISHED
tcp        0      0 172.16.0.3:22           183.198.11.196:22025    ESTABLISHED
tcp        0      0 172.16.0.3:111          170.130.187.34:51001    ESTABLISHED
tcp        0      0 172.16.0.3:22           183.198.11.196:22506    ESTABLISHED
tcp        0      0 172.16.0.3:50948        169.254.0.138:8086      ESTABLISHED
tcp        0      0 172.16.0.3:22           183.198.11.196:22495    ESTABLISHED
tcp        0      0 172.16.0.3:111          164.90.208.105:46554    ESTABLISHED
tcp        0      0 172.16.0.3:22           183.198.11.196:22453    ESTABLISHED
tcp        0   3360 172.16.0.3:22           183.198.11.196:22438    ESTABLISHED
tcp6       0      0 :::111                  :::*                    LISTEN
tcp6       0      0 ::1:53                  :::*                    LISTEN

```

```sh
ubuntu@VM-0-3-ubuntu:~$ netstat -aun
Active Internet connections (servers and established)
Proto Recv-Q Send-Q Local Address           Foreign Address         State
udp        0      0 172.17.0.1:53           0.0.0.0:*
udp        0      0 172.16.0.3:53           0.0.0.0:*
udp        0      0 127.0.0.1:53            0.0.0.0:*
udp        0      0 127.0.0.53:53           0.0.0.0:*
udp        0      0 172.16.0.3:68           0.0.0.0:*
udp        0      0 0.0.0.0:111             0.0.0.0:*
udp        0      0 127.0.0.1:123           0.0.0.0:*
udp        0      0 172.16.0.3:123          0.0.0.0:*
udp6       0      0 fe80::5054:ff:fe9b:8:53 :::*
udp6       0      0 ::1:53                  :::*
udp6       0      0 :::111                  :::*
udp6       0      0 ::1:123                 :::*
udp6       0      0 fe80::5054:ff:fe9b::123 :::*

```

### lsof

```
root@VM-0-3-ubuntu:/home/ubuntu# lsof -i -Pn | grep "3000"
epoll_ser  637850            root    3u  IPv4 48974473      0t0  TCP *:3000 (LISTEN)
epoll_ser  640784            root    3u  IPv4 48991331      0t0  TCP *:3000 (LISTEN)

```

### nc

```sh
ubuntu@VM-0-3-ubuntu:~$ nc -v 127.0.0.1 3000 # tcp 连接上去
Connection to 127.0.0.1 3000 port [tcp/*] succeeded!

root@VM-0-3-ubuntu:/home/ubuntu/mybooksources-master/Chapter04/code# nc -v -l 127.0.0.1 3001  # 监听一个端口
Listening on localhost 3001
Connection received on localhost 39630

root@VM-0-3-ubuntu:/home/ubuntu/mybooksources-master/Chapter04/code# nc -v -l -u 127.0.0.1 3001  # 监听一个udp端口
Bound on localhost 3001
Connection received on localhost 50632
XXXXXdfdf
sdfsdf

ubuntu@VM-0-3-ubuntu:~$ nc -v -u 127.0.0.1 3001  # 连接udp
dfdf
Connection to 127.0.0.1 3001 port [udp/*] succeeded!
sdfsdf

```

### curl

```
ubuntu@VM-0-3-ubuntu:~$ curl  www.baidu.com
<!DOCTYPE html>
<!--STATUS OK--><html> <head><meta http-equiv=content-type content=text/html;charset=utf-8><meta http-equiv=X-UA-Compatible content=IE=Edge><meta content=always name=referrer><link rel=stylesheet type=text/css href=http://s1.bdstatic.com/r/www/cache/bdorz/baidu.min.css><title>百度一下，你就知道</title></head> <body link=#0000cc> <div id=wrapper> <div id=head> <div class=head_wrapper> <div class=s_form> <div class=s_form_wrapper> <div id=lg> <img hidefocus=true src=//www.baidu.com/img/bd_logo1.png width=270 height=129> </div> <form id=form name=f action=//www.baidu.com/s class=fm> <input type=hidden name=bdorz_come value=1> <input type=hidden name=ie value=utf-8> <input type=hidden name=f value=8> <input type=hidden name=rsv_bp value=1> <input type=hidden name=rsv_idx value=1> <input type=hidden name=tn value=baidu><span class="bg s_ipt_wr"><input id=kw name=wd class=s_ipt value maxlength=255 autocomplete=off autofocus></span><span class="bg s_btn_wr"><input type=submit id=su value=百度一下 class="bg s_btn"></span> </form> </div> </div> <div id=u1> <a href=http://news.baidu.com name=tj_trnews class=mnav>新闻</a> <a href=http://www.hao123.com name=tj_trhao123 class=mnav>hao123</a> <a href=http://map.baidu.com name=tj_trmap class=mnav>地图</a> <a href=http://v.baidu.com name=tj_trvideo class=mnav>视频</a> <a href=http://tieba.baidu.com name=tj_trtieba class=mnav>贴吧</a> <noscript> <a href=http://www.baidu.com/bdorz/login.gif?login&amp;tpl=mn&amp;u=http%3A%2F%2Fwww.baidu.com%2f%3fbdorz_come%3d1 name=tj_login class=lb>登录</a> </noscript> <script>document.write('<a href="http://www.baidu.com/bdorz/login.gif?login&tpl=mn&u='+ encodeURIComponent(window.location.href+ (window.location.search === "" ? "?" : "&")+ "bdorz_come=1")+ '" name="tj_login" class="lb">登录</a>');</script> <a href=//www.baidu.com/more/ name=tj_briicon class=bri style="display: block;">更多产品</a> </div> </div> </div> <div id=ftCon> <div id=ftConw> <p id=lh> <a href=http://home.baidu.com>关于百度</a> <a href=http://ir.baidu.com>About Baidu</a> </p> <p id=cp>&copy;2017&nbsp;Baidu&nbsp;<a href=http://www.baidu.com/duty/>使用百度前必读</a>&nbsp; <a href=http://jianyi.baidu.com/ class=cp-feedback>意见反馈</a>&nbsp;京ICP证030173号&nbsp; <img src=//www.baidu.com/img/gs.gif> </p> </div> </div> </div> </body> </html>

```

### tcpdump

```sh
root@VM-0-3-ubuntu:/home/ubuntu# tcpdump -i any "tcp port 3001"
tcpdump: verbose output suppressed, use -v or -vv for full protocol decode
listening on any, link-type LINUX_SLL (Linux cooked v1), capture size 262144 bytes
19:56:12.928329 IP localhost.39946 > localhost.3001: Flags [S], seq 2726208034, win 65495, options [mss 65495,sackOK,TS val 2359419880 ecr 0,nop,wscale 7], length 0
19:56:12.928341 IP localhost.3001 > localhost.39946: Flags [S.], seq 3476933863, ack 2726208035, win 65483, options [mss 65495,sackOK,TS val 2359419880 ecr 2359419880,nop,wscale 7], length 0
19:56:12.928350 IP localhost.39946 > localhost.3001: Flags [.], ack 1, win 512, options [nop,nop,TS val 2359419880 ecr 2359419880], length 0

# 以上是抓包三次握手
```

