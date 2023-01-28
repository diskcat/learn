#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
    int count = 0;
    for (;;) {
        FILE *fp = fopen("tmp", "r");
        if (fp == NULL) {
            fprintf(stderr, "%s\n", strerror(errno));
            break;
        }
        count++;
    }
    

    printf("fd = %d\n", count);
    exit(0);
}