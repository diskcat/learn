#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{   
    FILE *base, *copy;
    int ch;

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

    for(;;) {
        ch = fgetc(base);
        if (ch == EOF) {
            break;
        }
        fputc(ch, copy);
    }

    fclose(copy);
    fclose(base);
    return 0;
}
