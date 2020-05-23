#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
/*
 siginfo_t {
               int      si_signo;    // Signal number
               int      si_errno;    // An errno value
               int      si_code;     // Signal code
               int      si_trapno;   // Trap number that caused
                                        hardware-generated signal
                                        (unused on most architectures)
               pid_t    si_pid;      // Sending process ID
               uid_t    si_uid;      // Real user ID of sending process
               int      si_status;   // Exit value or signal
               clock_t  si_utime;    // User time consumed
               clock_t  si_stime;    // System time consumed
               sigval_t si_value;    // Signal value
               int      si_int;      // POSIX.1b signal
               void    *si_ptr;      // POSIX.1b signal
               int      si_overrun;  // Timer overrun count; POSIX.1b timers
               int      si_timerid;  // Timer ID; POSIX.1b timers
               void    *si_addr;     // Memory location which caused fault
               int      si_band;     // Band event
               int      si_fd;       // File descriptor
           }

           */

void catch_signal(int signo,siginfo_t *resdata,void *unkonwp)
{
    printf("signo=%d\n",signo);
    printf("return data :%d\n",resdata->si_value.sival_int);
    printf("second return data:%d\n",resdata->si_int);
    return ;
}

int main(int arg, char *args[])
{
    pid_t pid=0;
    pid=fork();
    if(pid==-1)
    {
        printf("fork() failed! error message:%s\n",strerror(errno));
        return -1;
    }
    if(pid==0)
    {
        printf("i am child!\n");
        //等待父进程执行完信号安装
        sleep(5);
        //向父进程发送带数据的信号
        union sigval sigvalue;
        sigvalue.sival_int=222;
        //发送信号
        if(sigqueue(getppid(),SIGINT,sigvalue)==-1)
        {
            printf("sigqueue() failed ! error message:%s\n",strerror(errno));
            exit(0);
        }
        printf("子进程信号发送成功！\n");
        exit(0);
    }
    if(pid>0)
    {
        printf("i am father!\n");
        //安装信号
        struct sigaction act;
        //初始化sa_mask
        sigemptyset(&act.sa_mask);
        act.sa_sigaction=catch_signal;
        //一旦使用了sa_sigaction属性，那么必须设置sa_flags属性的值为SA_SIGINFO
        act.sa_flags=SA_SIGINFO;
        //安装信号
        if(sigaction(SIGINT,&act,NULL)!=0)
        {
            printf("sigaction() failed! \n");
            return -1;
        }
        //等待子进程返回
        int status=0;
        wait(&status);
        printf("game over!\n");
    }
    return 0;
}
