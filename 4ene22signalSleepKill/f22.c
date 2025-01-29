#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

 void fun(int sig);

 main() {
    int x=0, y=0;
    signal(SIGUSR2,fun);
    if (fork() == 0) {
        sleep(2);
        printf("\n Mensaje XZ");
        kill(getppid(), SIGUSR2);
    } else {
        x = sleep(6);
        y = sleep(1);
        printf("\n x=%d y=%d\n", x, y);
    }
 }
 
 void fun(int sig) {
    sleep(1);
    printf("\n Mensaje XX");
 }