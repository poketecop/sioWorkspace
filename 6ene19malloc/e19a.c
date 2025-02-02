/* Código del programa e19a */
#include <sys/stat.h>
#include <fcntl.h>
main()
{
    int r, h;
    int N = 9;
    char *b;
    b = (char *)malloc(N * sizeof(char));
    for (h = 0; h < N; h++)
    {
        *(b + h) = '\0';
    }
    mknod("tra10", S_IFIFO | 0666, 0);
    r = open("tra10", 0666);
    read(r, b, 7);
    printf("\n%s\n", b);
    close(r);
    unlink("tra10");
}