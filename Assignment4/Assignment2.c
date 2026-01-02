#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int fdd,fds;
    char buffer[1024];
    int bytes=0;
    int offset=0;

    if (argc!=4)
    {
        printf("Enter Sourse Destination And offset \n");
        return -1;

    }
    offset=(int)strtol(argv[3],NULL,10);
    fds=open(argv[1],O_RDONLY);
    fdd=open(argv[2],O_CREAT|O_WRONLY,0777);
    if (fdd==-1 || fds==-1)
    {
        perror("File open Error");
        return -1;
    }
    lseek(fds,offset,SEEK_SET);
    while ((bytes=read(fds,buffer,sizeof(buffer)))>0)
    {
        write(fdd,buffer,bytes);
    }
    close(fdd);
    close(fds);

    printf("File copied from offset %d\n", offset);
    return 0;
    
    
}