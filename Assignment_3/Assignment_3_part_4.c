#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char dname[256];
    char path[512];
    DIR *dp;
    struct dirent *entry;
    struct stat sb;
    int count = 0;

    printf("Enter directory name: ");
    scanf("%s", dname);

    dp = opendir(dname);
    if (dp == NULL)
    {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        snprintf(path, sizeof(path), "%s/%s", dname, entry->d_name);

        if (stat(path, &sb) == -1)
            continue;

        if (S_ISREG(sb.st_mode) && sb.st_size == 0)
        {
            if (unlink(path) == 0)
            {
                printf("Deleted: %s\n", entry->d_name);
                count++;
            }
        }
    }

    closedir(dp);
    printf("Total deleted files: %d\n", count);
    return 0;
}
