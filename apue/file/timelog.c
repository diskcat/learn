#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define PATH "./out"
#define MAXSIZE 1021
int main(int argc, char const *argv[])
{   struct tm *tm;

    char buf[1024];
    int count = 0;
    FILE *fp = fopen(PATH, "a+");
    for(;fgets(buf, MAXSIZE, fp) != NULL;) {
        count++;
    }

    for(;;) {
        time_t tmptime = time(NULL);
        tm = localtime(&tmptime);
        fprintf(fp, "-%4d-%d-%d-%d %d:%d:%d\n", ++count, tm->tm_year+1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
        fflush(fp);
        sleep(1);
    }

    fclose(fp);
    return 0;
}
