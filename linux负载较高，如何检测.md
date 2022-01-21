## linux负载较高，如何检测

```bash
$ uptime
 16:17:31 up 187 days,  2:06,  5 users,  load average: 2.41, 3.00, 3.28
```

```bash
 w
 16:18:23 up 187 days,  2:07,  5 users,  load average: 2.06, 2.81, 3.20
USER     TTY      FROM             LOGIN@   IDLE   JCPU   PCPU WHAT
root     tty1     -                15Nov21 67days  0.97s  0.06s -bash

```

Load 就是对计算机干活多少的度量（WikiPedia：the system Load is a measure of the amount of work that a compute system is doing）简单的说是进程队列的长度。Load Average 就是一段时间（1分钟、5分钟、15分钟）内平均Load.



以上只是大概的反映负载，可以用top查看每个进程使用cpu和内存等。

iostat可以看io的开销

```
iostat -x 1 10命令，表示开始监控输入输出状态，-x表示显示所有参数信息，1表示每隔1秒监控一次，10表示共监控10次
```



