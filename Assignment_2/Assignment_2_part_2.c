#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char fname[256];
    char data[1024];
    int fd;
    int bytes;

    printf("Enter file name: ");
    scanf("%255s", fname);

    getchar();
    printf("Enter string: ");
    fgets(data, sizeof(data), stdin);
    
    
    fd = open(fname, O_WRONLY| O_CREAT | O_APPEND, 0777);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    bytes = write(fd, data, strlen(data));
    printf("\nTotal bytes read: %d\n", bytes);

    close(fd);
    return 0;
}