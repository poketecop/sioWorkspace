#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void fun1(int x);

main()
{
    // Imprimir pid:
    printf("PID padre: %d\n", getpid());
    signal(SIGUSR1, fun1);

    if (fork() == 0)
    {
        // Imprimir pid
        printf("PID hijo: %d\n", getpid());
        pause();
    }
    else
    {
        wait(NULL);
    }
}

void fun1(int x)
{
    printf("Mensaje A");
}