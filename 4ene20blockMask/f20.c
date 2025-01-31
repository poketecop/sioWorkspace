#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void f1(int sig);

main(int a, char *b[]) {

    // Imprimir pid
    printf("f20 PID Padre: %d\n", getpid());

    long c, d;
    signal(SIGUSR1, f1);
    signal(SIGUSR2, SIG_DFL);
    d = atoi(b[1]);
    if (a == 2 && d == 1) {
        c = sigsetmask(sigmask(SIGUSR1));
        sigblock(sigmask(SIGUSR2));
        pause();
        sigsetmask(c);
    } else {
        pause();
        exit(1);
    }
}

void f1(int sig)
{
    printf("\n\n Texto 1\n%d", strsignal(sig));
}