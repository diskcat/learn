#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <getopt.h>
/***
 * 
 * -y: year
 * -m: month
 * -d: day
 * -H: hour
 * -M: minute
 * -S: second
 * 
 * 
*/
#define BUFSIZE 1024

int main(int argc, char const *argv[])
{   
    char buf[BUFSIZE];
    char fmtbuf[BUFSIZE];
    time_t tamptime = time(NULL);
    struct tm *tm = localtime(&tamptime);
    char c;
    FILE *fp = stdout;
    fmtbuf[0] = 0;
    for(;;) {
        c = getopt(argc,argv, "-H:MSymd");
        if (c < 0) {
            break;
        }
        switch (c)
        {
        case 1: 
            if (fp == stdout) {
                fp = fopen(argv[optind - 1], "w");
                if (fp == NULL) {
                    perror("fopen()");
                    fp = stdout;
                }
            }
            break;
        case 'H':
            if (strcmp(optarg, "12") == 0) {
                strncat(fmtbuf, " %I(%P) ", BUFSIZE);
            } else if (strcmp(optarg, "24") == 0) {
                strncat(fmtbuf, " %H ", BUFSIZE);
            } else {
                printf("Invalid argument\n");
            }
            break;
        case 'm':
            strncat(fmtbuf," %m ", BUFSIZE);
            break;
        case 'S':
            strncat(fmtbuf," %S ", BUFSIZE);
            break;
        case 'y':
            strncat(fmtbuf," %Y ", BUFSIZE);
            break;
        case 'M':
            strncat(fmtbuf," %M ", BUFSIZE);
            break;
        case 'd':
            strncat(fmtbuf," %d ", BUFSIZE);
            break;
        default:
            break;
        }
    }
    strncat(fmtbuf, "\n", BUFSIZE);
    strftime(buf, BUFSIZE, fmtbuf, tm);

    fputs(buf, fp);
    return 0;
}
