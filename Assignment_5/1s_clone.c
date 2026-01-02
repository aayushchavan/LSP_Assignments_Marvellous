
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include<time.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;  
    struct stat sb;
    char path[1024];
    char timebuf[64];

    if (argc != 2)
    {
        printf("Give DirectoryPath\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        perror("opendir failed");
        return -1;
    }

    while ((ptr = readdir(dp)) != NULL)
    {
        if ((strcmp(ptr->d_name, ".") == 0) ||
            (strcmp(ptr->d_name, "..") == 0))
            continue;

        snprintf(path, sizeof(path), "%s/%s", argv[1], ptr->d_name); 

        if (lstat(path, &sb) == -1)   
        {
            perror("lstat failed");
            continue;
        }

        printf("%-20s ", ptr->d_name);

        if (S_ISREG(sb.st_mode))      printf("FILE ");
        else if (S_ISDIR(sb.st_mode)) printf("DIR  ");
        else if (S_ISLNK(sb.st_mode)) printf("LINK ");
        else                          printf("OTHER ");

        printf("%10ld ", sb.st_size);

        printf((S_ISDIR(sb.st_mode)) ? "d" : "-");
        printf((sb.st_mode & S_IRUSR) ? "r" : "-");
        printf((sb.st_mode & S_IWUSR) ? "w" : "-");
        printf((sb.st_mode & S_IXUSR) ? "x" : "-");
        printf((sb.st_mode & S_IRGRP) ? "r" : "-");
        printf((sb.st_mode & S_IWGRP) ? "w" : "-");
        printf((sb.st_mode & S_IXGRP) ? "x" : "-");
        printf((sb.st_mode & S_IROTH) ? "r" : "-");
        printf((sb.st_mode & S_IWOTH) ? "w" : "-");
        printf((sb.st_mode & S_IXOTH) ? "x" : "-");
        printf(" ");

        strftime(timebuf, sizeof(timebuf),"%d-%m-%Y %H:%M",localtime(&sb.st_mtime));
        printf("%s\n", timebuf);
    }

    closedir(dp);
    return 0;
}
