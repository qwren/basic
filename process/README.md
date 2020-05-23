
section 1. 进程生命周期

# 编译运行fork1.c 看打印几个hello，分析为什么；

# 编译运行fork2.c 看打印几个a, b, c，分析为什么；

# 编译运行life_period.c，
## 在if 1改为if 0的情况下，

     21 #if 1 /* define 1 to make child process always a zomie */
     22                 printf("ppid:%d\n", getpid());
     23                 while(1);
     24 #endif
杀死子进程，观察父进程能监控到子进程死亡原因。

## 在if 1不改为if 0的情况下，
杀死子进程，观察子进程的僵尸态。

# cpulimit的用法:
编译cpulimit.c这个死循环程序，gcc cpulimit.c，运行之./a.out，通过pidof a.out命令获得它的pid，然后开一个terminal观察top，发现a.out这个进程的CPU利用率接近100%，之后通过cpulimit控制它的CPU利用率，再看top
* cpulimit -l 10 -p  a.out的pid
* cpulimit -l 20 -p  a.out的pid
...

# job control
$ ping www.baidu.com > /dev/null &
$ ping www.sina.com.cn > /dev/null
$ ctrl + z
$ jobs
$ fg 1
$ ctrl + z
 
section 2. 进程间通信

https://github.com/clpsz/linux-itss

# 理解page cache对程序速度影响
    $ sudo sh -c 'echo 3 > /proc/sys/vm/drop_caches'
    $ time python hello.py 
    Hello World! Love, Python

    real	0m0.142s
    user	0m0.000s
    sys	0m0.020s
    
    $ time python hello.py
    ...
    real	0m0.018s
    ...
### 两次时间差很大！

# 理解mmap
    $ gcc mmap.c
    $ ./a.out 
    print "Hello World! Love, Python"




