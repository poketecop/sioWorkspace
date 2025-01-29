#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
        char *argv[1] = {0};
        execv("apen", argv);
        u = u + 5;
        printf("\n%d\n", u);
    } else {
        exit(1);
    }
}

void func(int x) {
    printf("Mensaje 1");
}