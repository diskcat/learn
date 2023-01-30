#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAXSIZE 1024
/**
 * ssize_t read(int fd, void *buf, size_t count);
 * ssize_t write(int fd, const void *buf, size_t count);
 * int open(const char *pathname, int flags);
 * int close(int fd);
 * 
*/

void err() {
    fprintf(stderr, "%s\n", strerror(errno));
    exit(1);
}

int main(int argc, char const *argv[])
{
    char buf[MAXSIZE];
    int n;
    if (argc < 2) {
        err();
    }

    int old_fd = open(argv[1], O_RDONLY);
    if (old_fd < 0){
       err();
    }
    int new_fd = open(argv[2], O_WRONLY | O_CREAT|O_TRUNC, 0600);

    if (new_fd < 0) {
        close(old_fd);
        err();
    }
    for(;(n = read(old_fd, buf, MAXSIZE)) > 0;) {
        write(new_fd, buf, n);
    }
    close(new_fd);
    close(old_fd);
    return 0;
}




