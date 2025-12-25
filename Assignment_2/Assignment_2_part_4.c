#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    char Dname[256];
    char path[512];
    DIR *dp;
    struct dirent *entry;
    struct stat sb;

    printf("Enter directory name:");
    scanf("%255s",Dname);

    dp = opendir(Dname);
    if (dp == NULL)
    {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if (strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,".") == 0)
        continue;

        snprintf(path, sizeof(path), "%s/%s", Dname, entry ->d_name);
     
        if (lstat(path, &sb) == -1)
            continue;

        printf("%s : ", entry->d_name);

        if(S_ISREG(sb.st_mode))
            printf("Regular File\n");
        else if (S_ISDIR(sb.st_mode))
            printf("Directory\n");
        else if (S_ISLNK(sb.st_mode))
            printf("Symbolic Link\n");
        else if (S_ISFIFO(sb.st_mode))
            printf("FIFO\n");
        else if (S_ISSOCK(sb.st_mode))
            printf("Socket\n");
        else if (S_ISCHR(sb.st_mode))
            printf("Character Device\n");
        else if (S_ISBLK(sb.st_mode))
            printf("Block Device\n");
        else
            printf("Unknown\n");
    }

    closedir(dp);
    return 0;
}