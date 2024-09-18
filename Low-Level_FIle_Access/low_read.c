#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#define BUF_SIZE 100
void error_handling(char* message);

/* 
    O_CREAT必要时创建文件
    O_TRUNC删除全部现有数据
    O_APPEND维持现有数据，保存到其后面
    O_RDONLY只读打开
    O_WRONLY只写打开
    O_RDWR读写打开
 */

int main(void){
    int fd;
    char buf[BUF_SIZE];
    fd=open("data.txt",O_RDONLY);
    if(fd==-1) error_handling("open() error!");
    printf("file descriptor:%d \n",fd);
    if(read(fd,buf,sizeof(buf))==-1)
        error_handling("read() error!");
    printf("file data:%s",buf);
    close(fd);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}