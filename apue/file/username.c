#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        printf("usage.....\n");
        exit(1);
    }

    struct passwd *user = getpwuid(atoi(argv[1]));
    puts(user->pw_name);    
    return 0;
}
