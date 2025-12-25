#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main()
{
    char dname[256];
    char fname[256];
    DIR *dp;
    struct dirent *entry;

    printf("Enter directory name: ");
    scanf("%s", dname);

    printf("Enter file name: ");
    scanf("%s", fname);

    dp = opendir(dname);
    if (dp == NULL)
    {
        perror("opendir");
        return -1;        
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if (strcmp(entry->d_name, fname) == 0)
            {
                printf("File found: %s/%s\n", dname, fname);
                closedir(dp);
                return 0;
            }
    }

    closedir(dp);
    printf("File not found\n");
    return 0;
}