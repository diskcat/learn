#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFSIZE 1024

int main(int argc, char const *argv[])
{   
    char buf[BUFSIZE];
    time_t tamptime = time(NULL);
    struct tm *tm = localtime(&tamptime);
    strftime(buf, BUFSIZE, "NOW: %Y-%m-%d", tm);
    puts(buf);
    tm->tm_mday += 100;
    mktime(tm);
    strftime(buf, BUFSIZE, "100DAY TIME: %Y-%m-%d", tm);
    puts(buf);
    return 0;
}
