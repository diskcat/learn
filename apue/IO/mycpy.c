#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAXSIZE 1024

/**
 * use fget and fputs to make copy function 
 * 
*/
int main(int argc, char const *argv[])
{   
    FILE *base, *copy;
    char buf[MAXSIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source file> <dest_file>\n", argv[0]);
        exit(1);
    }

    base = fopen(argv[1], "r");
    if (base == NULL) {
        fprintf(stderr, "%s", strerror(errno));
        exit(1);
    }
    copy = fopen(argv[2], "w");
    if (copy == NULL) {
        fprintf(stderr, "%s", strerror(errno));
        exit(1);
    }

    for(;fgets(buf, MAXSIZE - 1, base) != NULL;) {
        fputs(buf, copy);
    }

    fclose(copy);
    fclose(base);
    return 0;
}
