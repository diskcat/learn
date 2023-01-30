IO：是一切操作的基础
stdio: 标准IO
sysio：系统IO/文件IO

important： 
    学习内核中的宏定义

User
------  sysctl
Kernel

函数成对出现的情况下通常分配在堆上
静态区贯穿着程序的生命周期

EOF -1 通常情况下

是资源一定有上限
ulimit -a   

stdio:FILE类型贯穿始终，
    fopen();
    fclose();

    fgetc(); //读一个字节
    fputc(); //写一个字节
    fgets();  //size - 1 or '\n' 结束
    fputs();
    fread();
    fwrite();
    getline();

    printf();
    scanf();

    fseek(); //定位，偏移量 --fseeko
    ftell(); //文件大小 --ftello
    rewind(); // fseek(fd, 0L, SEEK_SET) 将fd移动到文件首

    fflush();

    ftruncate/trucate 截取文件长短

## 临时文件 
1. 如何不冲突的创建临时文件  
2. 及时的将临时文件销毁  

typenam:  
typefile：  

## 系统调用IO

文件描述符（fd）是文件IO中贯穿始终的类型  
文件描述符的概念  
系统调用IO操作：open, close, read,  write, lseek  
IO的效率问题  
将文件IO和系统IO区别  
文件共享  
原子操作  
程序中的重定向  
同步 sync, fsync, fdatasync  
fctl  
ioctl  

pwd : dev/fd，虚目录显示的是当前文件描述符的信息（谁看就是谁）

重定向文件描述符
dup：将文件描述符复制到下标最小的空描述符数组上， 无原子性改描述符可能被抢占。
dup2：替换dup操作，具有原子性。 
```
close(1);
int fd = open(); // this fd == 1 true, simple 重定向
puts("hello world");
-------------------------------------
int fd = open(); // this fd == 1 true, simple 重定向
close(1);
dup(fd); //非原子操作，当多线程程序并发时候描述符会被抢占。
close(fd);
```

-----------------------------------------------

strace 跟踪系统调用
文件IO与系统IO的区别

fcntl：文件描述符所变的魔术几乎都来源于该函数
ioctl：设备相关的内容

 

## 原子操作
原子：不可分割的最小单位  
原子操作的作用：解决竞争和冲突


