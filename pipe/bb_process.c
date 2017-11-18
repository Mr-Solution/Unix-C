/*************************************************************************
	> File Name: bb_process.c
	> Author: reeves
	> Mail: seereeves@163.com 
	> Created Time: 2017年11月18日 星期六 16时13分57秒
 ************************************************************************/

#include <unistd.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <fcntl.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <limits.h>  
#include <string.h>  

int main() {  
    const char *fifo_name = "aa2bb_fifo";  
    const char *bb_self_mark = "bb";
    int pipe_fd = -1;  
    int msg_fd = -1;  
    int res = 0;  
    int open_mode = O_RDONLY;  
    char buffer[PIPE_BUF + 1];  
    int bytes_read = 0;  
    int bytes_write = 0;  
    //清空缓冲数组  
    memset(buffer, '\0', sizeof(buffer));  

    printf("Process %d opening FIFO O_RDONLY\n", getpid());  
    //以只读阻塞方式打开管道文件，注意与fifowrite.c文件中的FIFO同名  
    pipe_fd = open(fifo_name, open_mode);  
    //以只写方式创建保存数据的文件  
    msg_fd = open("MsgFromFIFO.txt", O_WRONLY|O_CREAT, 0644);  
    printf("Process %d result %d\n",getpid(), pipe_fd);  

    if (pipe_fd != -1) {  
        do { 
            //读取FIFO中的数据，并把它保存在MsgFromFIFO.txt文件中  
            res = read(pipe_fd, buffer, PIPE_BUF);  
            strcat(buffer, "bb");
            printf("buffer content : %s, bb content:%s",buffer,bb_self_mark);
            bytes_write = write(msg_fd, buffer, res); 
            int mark = write(msg_fd, bb_self_mark, 2);
            bytes_read += res; 
        } while(res > 0);  
        close(pipe_fd);  
        close(msg_fd);  
    }  
    else  {
        exit(EXIT_FAILURE);
    }

    printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);  
    exit(EXIT_SUCCESS);  
}
