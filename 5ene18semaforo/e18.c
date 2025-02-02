#include <cabeceras.h>
main()
{
    int x, u;
    key_t y;
    struct sembuf z[2];
    z[0].sem_flg = 0;
    z[1].sem_flg = 0;
    y = ftok("deltap.txt", 'x');
    if (y == (key_t)-1)
    {
        printf("mensaje A");
        exit(3);
    }
    x = semget(y, 2, IPC_CREAT | 0600);
    u = semctl(x, 0, SETALL, 0);
    if (fork() == 0)
    {
        z[0].sem_num = 0;
        z[0].sem_op = 1;
        u = semop(x, z, 1);
        z[1].sem_num = 1;
        z[1].sem_op = -1;
        u = semop(x, z, 1);
        printf("\nmensaje B\n");
    }
    else
    {
        if (fork() == 0)
        {
            sleep(2);
            z[0].sem_num = 0;
            z[0].sem_op = -1;
            u = semop(x, z, 1);
            printf("\nmensaje C\n");
            z[1].sem_num = 1;
            z[1].sem_op = 1;
            u = semop(x, z, 1);
        }
    }
}