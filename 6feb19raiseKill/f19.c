#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main()
{
    int a, b;
    if ((a = fork()) == 0)
    {
        while (1)
        {
            a = a + 3;
            b = raise(SIGCHLD);
            printf("\nOutput[%d]: %d: %d\a\n", getpid(), b, a);
            sleep(4);
        }
    }
    sleep(10);
    kill(a, SIGUSR1);
    sleep(2);
    kill(getppid(), SIGUSR2);
}