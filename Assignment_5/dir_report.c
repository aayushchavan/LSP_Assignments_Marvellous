#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int filecount = 0;
int dircount = 0;
long totalsize = 0;

long maxsize = 0;
char maxfile[1024];

void Traversal(char *dirname)
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;  
    struct stat sb;
    char path[1024];
    
    

    dp=opendir(dirname);
    
    if (dp==NULL)
    {
        printf("Failed to open directory");
        return ;
    }
    dircount++;
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
        if(S_ISDIR(sb.st_mode))
            Traversal(path);
        else if (S_ISREG(sb.st_mode))
            {
                filecount++;
                totalsize+=sb.st_size;
                if (sb.st_size>maxsize)
                {
                    maxsize=sb.st_size;
                    strcpy(maxfile,ptr->d_name);

                }
            }

    }
    closedir(dp);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Enter Directory Path");
        return -1;
    }

    Traversal(argv[1]);
    printf("\nFiles :%d\n", filecount);
    printf("Dirs :%d\n", dircount);
    printf("Total Size :%ld bytes\n", totalsize);

    if(filecount > 0)
        printf("Largest : %s (%ld bytes)\n", maxfile, maxsize);

    return 0;
}

