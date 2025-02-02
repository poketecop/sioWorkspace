#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

main()
{
    int a, b;
    if ((a = fork()) == 0)
    {
        while (1)
        {
            a = a ^ 2;
            b = raise(SIGCHLD);
            printf("\nMensaje 2[%d]: %d: %d\a\n", getpid(), b, a);
            sleep(3);
        }
    }
    sleep(8);
    kill(a, SIGUSR1);
    sleep(1);
    kill(getppid(), SIGUSR2);
}