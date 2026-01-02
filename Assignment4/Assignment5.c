#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    char ch;
    off_t size;

    if (argc != 2)
    {
        printf("enter FileName\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("File open error");
        return -1;
    }

    size = lseek(fd, 0, SEEK_END);

    while (size > 0)
    {
        size--;
        lseek(fd, size, SEEK_SET);
        read(fd, &ch, 1);
        write(1, &ch, 1);   
    }

    close(fd);
    return 0;
}
