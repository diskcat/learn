#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage...");
        exit(1);
    }
    int count = 0;
    FILE* fd = fopen(argv[1], "r");
    if (fd == NULL) {
        fprintf(stderr, "err = %s", strerror(errno));
        exit(1);
    }

    for (;fgetc(fd) != EOF;) {
        count++;
    }
    fprintf(stdout, "bytes = %d\n", count);
    return 0;
}
