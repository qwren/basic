#### 1.编译two-loops.c, gcc two-loops.c -pthread，运行两份

    $ gcc two-loops.c -pthread
    $ ./a.out &
    [1] 13682
    $ main pid:13682, tid:3075434240
    thread pid:13682, tid:3067038528
    thread pid:13682, tid:3075431232

    $ ./a.out &
    [2] 13685
    $ main pid:13685, tid:3075925760
    thread pid:13685, tid:3067530048
    thread pid:13685, tid:3075922752
# top命令观察CPU利用率：
        13682 qiaoweir	20   0   18684    616    552 S  98.4  0.0   1:12.09 a.out
        13685 qiaoweir	20   0   18684    644    580 S  98.1  0.0   1:07.32 a.out 
# renice其中之一，再观察CPU利用率
        sudo renice -n -5 -g 13682

          PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
        13682 qiaoweir	15  -5   18684    616    552 S 147.4  0.0   4:52.73 a.out
        13685 qiaoweir	20   0   18684    644    580 S  48.6  0.0   4:12.77 a.out

# killall a.out

#### 2.编译two-loops.c, gcc two-loops.c -pthread，运行一份
* top发现其CPU利用率接近200%
* 把它的所有线程设置为SCHED_FIFO

        chrt -f -a -p 50 进程PID
* 再观察它的CPU利用率

#### 3.cyclictest -p 99 -t1 -n
* 观察min, max, act, avg时间，分析hard realtime问题
* 加到系统负载，运行一些硬盘访问，狂收发包的程序，观察cyclictest的max变化

