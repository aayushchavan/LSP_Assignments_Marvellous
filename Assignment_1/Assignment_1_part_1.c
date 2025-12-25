#include <stdio.h>
#include <fcntl.h>
#include<unistd.h>

int main() 
{

    char fname[256];
    int fd = 0;

    printf("Enter file name:");
    scanf("%255s", fname);

    fd = open(fname, O_RDONLY);

    if (fd == -1)
    {
        perror("file error is");
        return -1;
    }
    else{
        printf("File opened successfully\n");
        printf("File Description: %d\n", fd);
        close(fd);
    }
    return 0;
}

