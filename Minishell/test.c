#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    printf("main\n");

    int fd = open("test.txt", O_RDONLY);
    printf("fd : [%d]\n", fd);
    close(fd);
    return (0);
}
