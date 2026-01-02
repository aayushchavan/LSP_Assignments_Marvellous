#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
    int fds,fdd;
    char buffer[1024];
    int bytes=0;;

    if (argc!=3){
    printf("Enter sourse file and destination file");
    return -1;
    }
    fds=open(argv[1],O_RDONLY);
    if (fds==-1)
    {
        perror("Unable to open Sourse File");
    }
    fdd=open(argv[2],O_CREAT|O_WRONLY,0777);
    if (fdd==-1)
    {
        perror("Unbale to Open Destination");
        close(fds);
        return -1;

    }
    while ((bytes=read(fds,buffer,sizeof(buffer))))
    {
        write(fdd,buffer,bytes);
    }
    close(fdd);
    close(fds);

       printf("File copied successfully\n");
    return 0;


}