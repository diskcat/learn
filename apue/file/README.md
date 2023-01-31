## 文件系统

类似于ls的实现

### 一、目录和文件

1. 获取文件属性
    stat: sys, 通过路径获取文件属性。
    fstat: sys, 通过文件名获取文件属性。
    lstat: 面对符号链接文件获取的是符号链接文件的属性。
2. 文件的访问权限
    st_mode是一个16位的位图，用于表示文件类型，文件的访问权限，特殊权限位。
3. umask（sys）
    作用：防止产生权限过松的文件
4. 文件权限的管理
    chmod,fchnod (sys)
5. 粘住位
    t位，在内存中保留装载痕迹下次可以很快的装载。
6. 文件系统：FAT，UFS
    文件系统是文件或数据存储和管理。
7. 硬链接，符号链接
    link，unlink，rename （sys）  
    remove   
    硬链接：硬链接与目录项是同义词，且建立硬链接有限制：不能给分区建立，不能给目录建立。  
    符号链接：可以跨分区，可以给目录建立。  
8. utime （sys）
    可以记录文件最后读的时间和最后写的时间。  

9. 目录的创建和销毁
    mkdir，rmdir (sys)
    rmdir：只能删除空目录，想要删除进行递归删除。
10. 更改当前工作路径
    chdir (sys) : change work directory.
    getcwd: get current working directory.
11. 分析目录/读取目录内容
    glob:
    opendir(2): 
    closedir(2): 
    readdir(3):
    rewinddir(3):
    seekdir(3):
    telldir(3): 
### 二、系统数据文件和信息

1. etc/passwd
    getpwuid(2)
    getpwnam(2)
2. etc/group
    getgrnam(2)
    getgrgid(2)
3. etc/shadow
    getspnam
    crypt： 只能看到第3个$前面的数据信息
    getpass
4. 时间戳
5.
### 二、进程环境
