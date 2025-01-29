#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void func(int x);

main() {
    // Imprimir pid
    printf("f22 PID Padre: %d\n", getpid());

    int u = 100;
    signal(SIGUSR1, func);
    u = u - 1;
    if (fork() == 0) {
        // Imprimir pid
        printf("f22 PID Hijo: %d\n", getpid());
        execv("apen", 0);
        u = u + 5;
        printf("\n%f\n", u);
    } else {
        exit(1);
    }
}

void func(int x) {
    printf("Mensaje 1");
}