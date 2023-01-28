#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * 缓冲区的作用: 大多数的情况是好事，合并系统调用
 * 行缓冲：换行的时候刷新，满了的时候刷新，强制刷新（标准输出）
 * 全缓冲：满了的时候刷新，强制刷新（默认，只要不是终端设备）
 * 无缓冲：如stderr需要立即输出的内容
 * 
 * 缓冲区可以用
 * setvbuf来修改
 * 
*/

int main() {

    printf("before while");
    fflush(stdout);
    for(;;);
    printf("end for");
    exit(0);
}