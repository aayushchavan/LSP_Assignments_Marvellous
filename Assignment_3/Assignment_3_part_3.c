#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    char srcDir[256];
    char destDir[256];
    char srcPath[512];
    char destPath[512];
    DIR *dp;
    struct dirent *entry;
    struct stat sb;
    int count = 0;

    printf("Enter source directory: ");
    scanf("%s", srcDir);

    printf("Enter destination directory: ");
    scanf("%s", destDir);

    dp = opendir(srcDir);
    if (dp == NULL)
    {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        if (stat(srcPath, &sb) == -1)
            continue;

        if (S_ISREG(sb.st_mode))
        {
            if (rename(srcPath, destPath) == 0)
                count++;
        }
    }

    closedir(dp);
    printf("Moved files count: %d\n", count);
    return 0;
}
