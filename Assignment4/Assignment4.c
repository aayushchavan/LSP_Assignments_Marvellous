#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int fdd,fds;
    char buffer[1024];
    int bytes=0;
    int i=0;

    if (argc<3)
    {
        printf("OutputFile InputFile1 InputFile2 ...\n ");
        return -1;

    }
    fdd=open(argv[1],O_CREAT|O_WRONLY|O_TRUNC,0777);
    if (fdd==-1)
    {
        perror("File open Error");
        return -1;
    }
    for(i=2;i<argc;i++)
    {
    fds=open(argv[i],O_RDONLY);
    if (fds==-1)
    {
        perror("File open Error");
        continue;
    }
    while ((bytes=read(fds,buffer,sizeof(buffer)))>0)
    {
        write(fdd,buffer,bytes);
        
    }
    close(fds);
}
    close(fdd);
    

    printf("All Files copied in one\n");
    

    return 0;
}
