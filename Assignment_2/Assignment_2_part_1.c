#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char fname[256];
    char buffer[1024];
    int fd;
    int bytes;
    int total = 0;

    printf("Enter file name: ");
    scanf("%s", fname);

    fd = open(fname, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    while ((bytes = read(fd, buffer, sizeof(buffer))) > 0)
    {
        write(1, buffer, bytes);
        total += bytes;
    }

    printf("\nTotal bytes read: %d\n", total);
    close(fd);

    return 0;
}