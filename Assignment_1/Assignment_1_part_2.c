#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

int main()
{
    char fname[100];
    char mode[2];
    int fd = 0;
    int ret = 0;

    printf("Enter file name: ");
    scanf("%s",fname);

    printf("Enter mode (R / W / RW / A): ");
    scanf("%s",mode);

    /*Used if-else because switch case cannot use more than
    one character so hence RW was not possible to be read as a single 
    character. could use abbrievation of RW as D or any single 
    character for switch case
      
    */
    if (strcmp(mode, "R") == 0)
        ret = O_RDONLY;
    else if (strcmp(mode, "W") == 0)
        ret = O_WRONLY|O_CREAT;
    else if (strcmp(mode, "RW") == 0)
        ret = O_RDWR| O_CREAT;
    else if (strcmp(mode, "A") == 0)
        ret = O_APPEND | O_CREAT | O_WRONLY;
    else
    {
        printf("Invalid mode\n");
        return -1;
    }

    fd = open(fname,ret,0777);

    if (fd == -1)
        perror("open");
    else
    {
        printf("File opened successfully\n");
        printf("File Descriptor: %d\n",fd);
        close(fd);
    }
    return 0;
} 