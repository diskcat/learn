#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <string.h>

int main(int argc, char const *argv[])
{   
    glob_t globres;
    if (argc < 2) {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }
    int err = glob("/etc/*.config", 0, NULL, &globres);
    if (err) {
        printf("usage glob err\n");
        exit(1);
    }
    printf("%ld", globres.gl_pathc);
    for(int i = 0; i < globres.gl_pathc; i++)
        puts(globres.gl_pathv[i]);
    globfree(&globres);
    exit(0);
}
