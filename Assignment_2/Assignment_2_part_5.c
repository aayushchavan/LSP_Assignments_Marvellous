#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    char dname[256];
    char path[512];
    char largest[256] = "";
    DIR *dp;
    struct dirent *entry;
    struct stat sb;
    off_t max = 0;

    printf("Enter directory name:");
    scanf("%255s",dname);

    dp = opendir(dname);
    if (dp == NULL)
    {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        snprintf(path, sizeof(path),  "%s/%s", dname, entry->d_name);

        if (lstat(path, &sb) == -1)
            continue;
        
        if (S_ISREG(sb.st_mode))
        {
            if (sb.st_size > max)
            {
                max = sb.st_size;
                strcpy(largest, entry->d_name);
            }
        }
    }

    closedir(dp);

    if (max > 0)
    {
        printf("Largest file: %s\n", largest);
        printf("Size: %ld bytes\n", max);
    }
    else
    {
        printf("No regular files found\n");
    }

    return 0;
}