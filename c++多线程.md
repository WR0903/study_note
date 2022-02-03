## 多线程

### 主线程退出，支线程会退出吗

在win系统中，主线程退出一般同进程的工作线程会退出。在linux系统中，主线程退出，同进程的工作线程不会有影响，但是这个进程会变成僵尸进程。

某个线程奔溃会导致整个进程退出。

### 线程创建方式

linux下使用```pthread_create```接口，创建好的线程需要在主线程调用```pthread_join```。

写好的程序编译的时候，如果用gcc需要带参数-lpthread，例如```gcc -g -o linuxtls linuxtls.cpp -lpthread```，因为pthread不是默认的库，需要指定一下。

win下不能用这个，是另外的接口。

c++11提供了thread类，不论win和linux都可以使用，直接定义```std::thread t1(thread_func1);```，然后```t1.join()```，在使用的时候一定注意定义thread 的时候最好不要在某个函数里面定义局部变量，因为该函数执行完了，作为局部变量也会销毁，会导致进程奔溃。

### 获取线程id的方式

linux下使用```pthread_self```接口，c11可以使用```std::this_thread::get_id()```,

### 定位进程cpu消耗过高的方式

首先用top看哪个进程高，例如：

```sh
Tasks: 130 total,   1 running, 129 sleeping,   0 stopped,   0 zombie
%Cpu(s):  2.3 us,  9.1 sy,  0.0 ni, 88.6 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
MiB Mem :   1987.1 total,    146.2 free,    284.0 used,   1556.9 buff/cache
MiB Swap:      0.0 total,      0.0 free,      0.0 used.   1511.5 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
 399481 root      20   0   87956   1576   1416 S   5.3   0.1   0:04.44 c11threadlocal
 395147 ubuntu    20   0   13956   6304   4712 S   2.7   0.3   0:02.38 sshd
 399039 root      20   0       0      0      0 I   2.7   0.0   0:01.33 kworker/u2:1-events_power_efficient
2516252 root      20   0  966200  60720  30368 S   0.7   3.0  54:42.63 YDService
   8759 root      20   0  493204  16860   4280 S   0.3   0.8 156:22.30 barad_agent
  16437 root      20   0 1197100  40884  27936 S   0.3   2.0  55:35.86 containerd
2516643 root      20   0 1157292   7748   4160 S   0.3   0.4   1:21.42 sh
      1 root      20   0  102996  12604   8324 S   0.0   0.6   0:39.58 systemd
      2 root      20   0       0      0      0 S   0.0   0.0   0:01.09 kthreadd
      3 root       0 -20       0      0      0 I   0.0   0.0   0:00.00 rcu_gp

```

上面的399481进程很高，是我运行的c11threadlocal，然后使用top -H

```sh
top - 16:27:43 up 42 days,  5:25,  3 users,  load average: 0.09, 0.08, 0.02
Threads: 204 total,   2 running, 202 sleeping,   0 stopped,   0 zombie
%Cpu(s):  6.7 us, 11.4 sy,  0.0 ni, 81.6 id,  0.0 wa,  0.0 hi,  0.3 si,  0.0 st
MiB Mem :   1987.1 total,    152.4 free,    277.8 used,   1557.0 buff/cache
MiB Swap:      0.0 total,      0.0 free,      0.0 used.   1517.8 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
 395147 ubuntu    20   0   13956   6304   4712 S   4.3   0.3   0:05.83 sshd
 396269 root      20   0       0      0      0 I   4.3   0.0   0:01.17 kworker/u2:2-events_power_efficient
 400124 root      20   0   87956   1576   1416 S   4.0   0.1   0:00.48 c11threadlocal
 400125 root      20   0   87956   1576   1416 S   4.0   0.1   0:00.49 c11threadlocal
    502 root      rt   0  280200  17992   8200 S   0.3   0.9   1:32.98 multipathd
  16452 root      20   0 1197100  40884  27936 S   0.3   2.0  18:30.78 containerd
      1 root      20   0  102996  12604   8324 S   0.0   0.6   0:39.56 systemd

```

可以看每个进程里面每个线程的消耗多少，例如c11threadlocal里面两个线程400124和400125和都很高，然后pstack 399481看调用堆栈，程序的每个线程都跑着哪里，例如：

```sh
ubuntu@VM-0-3-ubuntu:~$ sudo pstack 400925
Thread 3 (Thread 0x7fde9dad2700 (LWP 400927)):
#0  0x00007fde9e5083bf in clock_nanosleep () from /lib/x86_64-linux-gnu/libc.so.6
#1  0x00007fde9dad1d48 in ?? ()
#2  0x00007fde00000000 in ?? ()
#3  0x00007fde9dad1d60 in ?? ()
#4  0x0000558cb634fca8 in std::chrono::duration<long, std::ratio<1l, 1000000000l> > std::chrono::__duration_cast_impl<std::chrono::duration<long, std::ratio<1l, 1000000000l> >, std::ratio<1000000000l, 1l>, long, false, true>::__cast<long, std::ratio<1l, 1l> >(std::chrono::duration<long, std::ratio<1l, 1l> > const&) ()
#5  0x00007fde9dad1da0 in ?? ()
#6  0x00007fde9dad1db0 in ?? ()
#7  0x0000000000000001 in ?? ()
#8  0x5a942470b5f95a00 in ?? ()
#9  0x0000000000000000 in ?? ()
Thread 2 (Thread 0x7fde9e2d3700 (LWP 400926)):
#0  0x00007fde9e5083bf in clock_nanosleep () from /lib/x86_64-linux-gnu/libc.so.6
#1  0x00007fde9e2d2d48 in ?? ()
#2  0x00007fde00000000 in ?? ()
#3  0x00007fde9e2d2d60 in ?? ()
#4  0x0000558cb634fca8 in std::chrono::duration<long, std::ratio<1l, 1000000000l> > std::chrono::__duration_cast_impl<std::chrono::duration<long, std::ratio<1l, 1000000000l> >, std::ratio<1000000000l, 1l>, long, false, true>::__cast<long, std::ratio<1l, 1l> >(std::chrono::duration<long, std::ratio<1l, 1l> > const&) ()
#5  0x00007fde9e2d2da0 in ?? ()
#6  0x00007fde9e2d2db0 in ?? ()
#7  0x0000000000000001 in ?? ()
#8  0x5a942470b5f95a00 in ?? ()
#9  0x0000000000000000 in ?? ()
Thread 1 (Thread 0x7fde9e2d4740 (LWP 400925)):
#0  0x00007fde9e821cd7 in __pthread_clockjoin_ex () from /lib/x86_64-linux-gnu/libpthread.so.0
#1  0x0000000000000000 in ?? ()

```

然后把源码打开这些位置，分析问题。

### 互斥体的使用

使用前先定义互斥体```pthread_mutex_t  mymutex;```，然后初始化```pthread_mutex_init(&mymutex, NULL);```，然后就可以加锁解锁了，接口为：```pthread_mutex_lock(&mymutex);```和```pthread_mutex_trylock(&mymutex);```和```pthread_mutex_unlock(&mymutex);```，

使用完要销毁```pthread_mutex_destroy(&mymutex);```

互斥体使用的过程中有三种锁，普通锁、检错锁和可重入锁，设置方法：

```c++
pthread_mutexattr_t mutex_attr;
pthread_mutexattr_init(&mutex_attr);
pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_NOMAL);
pthread_mutex_init(&mymutex, &mutex_attr);
```

```PTHREAD_MUTEX_NOMAL``` 是普通锁，当一个线程加锁后，其他线程加锁会阻塞线程；

```PTHREAD_MUTEX_ERRORCHECK```是检错锁，当一个线程加锁后，其他线程加锁不会阻塞，会返回一个EDEADLK；

```PTHREAD_MUTEX_RECURSIVE```是可重入锁，同一个线程可以多次加锁，每次加锁有一个引用计数加1，解锁引用计数减一，当引用计数为0会释放锁，加锁过程中，其他线程加锁会阻塞线程。

### 信号量的使用

```c++
#include <semaphore.h>
sem_t            mysemaphore; //定义信号量
sem_init(&mysemaphore, 0, 0);  //初始化信号量
sem_destroy(&mysemaphore);  //销毁一个信号量
sem_post(&mysemaphore); //信号量资源加1，并释放信号量，sem_wait线程会被唤醒
sem_wait(&mysemaphore);//信号量资源为0时会阻塞线程，当资源不为0的时候线程被唤醒，然后资源减1
sem_trywait(&mysemaphore);//信号量资源为0时不会阻塞线程，返回值为-1，错误码为EAGAIN
struct timespec ts;
		ts.tv_sec = 3;
		ts.tv_nsec = 0;
		
sem_timedwait(&mysemaphore, &ts)////信号量资源为0时会阻塞线程，超过ts时间后，返回值为-1，错误码为ETIMEDOUT
```

### 条件变量的使用

```c++
pthread_cond_t   mycv; //定义一个条件变量
pthread_cond_init(&mycv, NULL); //条件变量初始化
pthread_mutex_destroy(&mymutex); //条件变量使用完要销毁
pthread_cond_wait(&mycv, &mymutex); // 会让线程阻塞等待下去
struct timespec ts;
		ts.tv_sec = 3;
		ts.tv_nsec = 0;
pthread_cond_timedwait(&mycv, &mymutex, &ts);  // 会让线程阻塞ts时间并等待下去
pthread_cond_signal(&mycv); //释放条件变量，并让wait线程运行，只会让其中一个线程运行，具体哪个线程未知
pthread_cond_broadcast(&mycv); // 释放条件变量，并让所有wait线程运行
```

### 读写锁的使用







