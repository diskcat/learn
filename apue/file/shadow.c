#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <shadow.h>
#include <crypt.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }
    char *passwd = getpass("passowd: \n");
    struct spwd * shadowline = getspnam(argv[1]);
    char *crypt_passwd = crypt(passwd, shadowline->sp_pwdp); 
    if (strcmp(crypt_passwd, shadowline->sp_pwdp) == 0) {
        printf("OK\n");
    } else {
        printf("Fail\n");
    }
    return 0;
}
