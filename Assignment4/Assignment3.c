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

    if (argc!=3)
    {
        printf("Enter Sourse Destination  \n");
        return -1;

    }
    fds=open(argv[1],O_RDONLY);
    fdd=open(argv[2],O_CREAT|O_WRONLY,0777);
    if (fdd==-1 || fds==-1)
    {
        perror("File open Error");
        return -1;
    }
    while ((bytes=pread(fds,buffer,sizeof(buffer),offset))>0)
    {
        pwrite(fdd,buffer,bytes,offset);
        offset+=bytes;
    }
    close(fdd);
    close(fds);

    printf("File copied using pread & pwrite\n");
    

    return 0;
}
