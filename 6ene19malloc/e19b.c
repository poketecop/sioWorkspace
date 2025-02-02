#include <sys/stat.h>
#include <fcntl.h>

main()
{
    int r;
    char b[] = "cadena2";
    r = open("tra10", 0666);
    write(r, b, 8);
    close(r);
}