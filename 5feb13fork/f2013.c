#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

main(int argc, char *argv[])
{
    int a, b = 0, c, d;
    if (argc != 2)
        exit(2);

    a = atoi(argv[1]);
    while (b != a && fork() == 0)
    {
        printf("\n[1][%d]\n", getpid());
        b = b + 1;
    }
    c = wait(&d);
    printf("\n[2][%d %d %d]\n", c, getpid(), getppid());
}