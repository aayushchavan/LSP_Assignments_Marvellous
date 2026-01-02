#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include<time.h>
#include<stdio.h>

void traversal(char *dirname,int level )
{   
    DIR *dp = NULL;
    struct dirent *ptr = NULL;  
    struct stat sb;
    char path[1024];
    int i;
    

    dp=opendir(dirname);
    
    if (dp==NULL)
    {
        printf("Failed to open directory");
        return ;
    }

    while ((ptr= readdir(dp))!=NULL)
    {
        if (strcmp(ptr->d_name,".")==0||strcmp(ptr->d_name,"..")==0)
        continue;
        snprintf(path,sizeof(path),"%s/%s",dirname,ptr->d_name);
        if(lstat(path,&sb)==-1)
        {
            perror("Lstat");
            continue;
        }
        for (i=0;i<level;i++)
            printf(" ");
        
        if(S_ISDIR(sb.st_mode))
                printf("[D] %s/\n", ptr->d_name);
        else if (S_ISREG(sb.st_mode))
                printf("[F] %s\n", ptr->d_name);
        else if (S_ISLNK(sb.st_mode))
                printf("[L] %s\n", ptr->d_name);
        else
                printf("[?] %s\n", ptr->d_name);
            
        if (S_ISDIR(sb.st_mode))
            traversal(path,level+1)  ;
            
                
    }
    closedir(dp);

}
int main(int argc,char *argv[])
{
    
    if(argc != 2)
    {
        printf("Enter Directory Path");
        return -1;
    }

    printf("%s/\n", argv[1]);
    traversal(argv[1], 1);

    return 0;

}