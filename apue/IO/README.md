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


