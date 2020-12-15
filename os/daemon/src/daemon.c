#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

int flag = 1;

void signal_handle(int sigNum){
    if (sigNum == SIGQUIT){
        printf("quitting.....\n");
        flag = 0;
    }
}

/*关闭输入,输出和报错三个文件描述符*/
void close_fds(){
    for (int i = 0; i < 3; i++) {
        close(i);
    }
}

int main(){
    pid_t pid;
    int fd;
    time_t t;

    pid = fork();

    if (pid == -1) {
        printf("fork error\n");
        exit(1);
    } else if (pid) {
        /*父进程执行*/
        exit(0);
    }

    /*子进程执行,调用setsid使子进程独立,摆脱会话控制、摆脱原进程组控制、摆脱终端控制*/
    if (-1 == setsid()) {
        printf("setsid error\n");
        exit(1);
    }

    pid = fork();

    if (pid == -1) {
        printf("fork error");
        exit(1);
    } else if (pid) {
        exit(0);
    }

    /*注册监听SIGQUIT信号*/
    if (signal(SIGQUIT,&signal_handle)) {
        printf("register signal quit failed\n");
        exit(0);
    }

    close_fds();

    umask(0);

    while(flag) {
        /*每隔10s向daemon.log中追加写时间*/
        fd = open("./daemon.log",O_WRONLY|O_CREAT|O_APPEND,0644);
        if (fd == -1) {
            printf("open log file failed\n");
        }
        t = time(0);
        char *buf = asctime(localtime(&t));
        write(fd,buf,strlen(buf));
        close(fd);
        sleep(10);
    }
    return 0;
}