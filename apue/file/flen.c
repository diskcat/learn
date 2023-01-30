#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    struct stat buf;
    if (argc < 2) {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }

    int fd = open(argv[1], "r");
    if (fd < 0) {
        fprintf(stderr, "%s", strerror(errno));
        exit(1);
    }
    fstat(fd, &buf);
    fprintf(stdout, "file size is %ld bytes\n", buf.st_size);
    return 0;
}