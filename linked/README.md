## 链接库

静态库有点像私家车放在哪都可以，动态库相当于公交车，只能放在车站。
当静态库和动态库重名的时候优先链接动态库。

### 动态链接库
动态库在声明的时候只是引用当前的库，执行期间需要用到的时候才会去相应位置寻找相应的函数。
占用的是运行时间而不是编译时间。从习惯角度来说还是用动态库多一些。

libxx.so
gcc -shared  -fpic -o libxx.so yyy.c    

发布到  
/usr/local/include --.so 
/usr/local/lib     --当前二进制文件的形式  

在 /etc/ld.so.conf  中添加路径
/sbin/ldconfig 重读/etc/ld.so.conf  
gcc -I/usr/local/include -L/usr/local/lib -o ... -lxxx
ldd ./xxx

非root用户
cp xx.so ~/lib
export LD_LIBRARY_PATH=~/lib //声明一个环境变量，限当前终端

### 静态链接库
静态库在比编译的时候把库直接装载进来，在调用的时候不占用调用时间。 
静态库会使代码膨胀，但是不会占用调用时间。

libxx.a
xx 带指库名
ar -cr libxx.a yyy.o

发布到
/usr/local/include --.h
/usr/local/lib     --当前二进制文件的形式

gcc -L/usr/local/lib -o main.o -lxx
-l 链接选项，放在最后



