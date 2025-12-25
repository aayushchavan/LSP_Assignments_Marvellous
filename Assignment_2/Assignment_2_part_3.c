#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char Dname[256];
    struct dirent *entry;
    DIR *dp;//directory pointer provided in dirent library

    printf("Enter directory name: ");
    scanf("%255s", Dname);

    dp = opendir(Dname);

    if (dp == NULL)
    {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
    if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") !=0)
        {
            printf("%s\n",entry->d_name);
        }        
    }

    closedir(dp);
    return 0;

}