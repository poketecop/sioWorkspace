#include <stdio.h>
#include <unistd.h>

main() {
    if (fork() == 0) {
        char *argv[1] = {0};
        execv("extractB", argv);
        printf("\n Code EF");
    }
    printf("\n Code 45");
}

