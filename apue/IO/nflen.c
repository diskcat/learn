#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage...err\n");
        exit(1);
    }
    long count = 0;
    FILE* fd = fopen(argv[1], "r");
    if (fd == NULL) {
        fprintf(stderr, "err = %s", strerror(errno));
        exit(1);
    }

    fseek(fd, 0, SEEK_END);
    count = ftell(fd);
    
    fprintf(stdout, "this file have = %ld bytes \n", count);
    return 0;
}
