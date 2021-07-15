#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <assert.h>

int main(){
    int fd = open("test.txt",O_RDONLY);
    assert(fd != 0);

    char buf[1024];

    int len = 0;
    while((len = read(fd,buf,1024)) > 0){
        for(int i = 0; i < len; i++){
            printf("%hx\n",buf[i]);
        }
    }

    close(fd);
    return 0;
}