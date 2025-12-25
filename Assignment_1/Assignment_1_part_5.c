#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    char fname[256];
    char Buffer[1024];
    int fd;
    int N;
    int ReadBytes;

    printf("Enter file name: ");
    scanf("%s",fname);

    printf("Enter number of bytes to read: ");
    scanf("%d", &N);

    fd = open(fname, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    ReadBytes = read(fd,Buffer,N);
    if (ReadBytes == -1)
    {
        perror("read");
    }
    else
    {
        Buffer[ReadBytes] = '\0';
        printf("Data read:\n%s\n", Buffer);
    }

    close(fd);
    return 0;

}