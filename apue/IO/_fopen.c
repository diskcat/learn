#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {

    FILE *fp = fopen("tmp", "r");
    if (fp == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(1);
    }

    puts("Ok");
    exit(0);
}