#include <stdio.h>
#include <time.h>
#include <sys/stat.h>

int main()
{
    char fname[200];
    struct stat sobj;

    printf("Enter file name: ");
    scanf("%s", fname);

    if (stat(fname, &sobj) == -1)
    {
        perror("stat");
        return -1;
    }

    printf("File Size: %ld bytes\n", sobj.st_size);
    printf("Inode Number: %ld\n", sobj.st_ino);
    printf("Hard Links: %ld\n",sobj.st_nlink);
    printf("Owner UID: %d\n",sobj.st_uid);
    printf("Owner GID: %d\n",sobj.st_gid);

    printf("File Type: ");
    if (S_ISREG(sobj.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(sobj.st_mode))
        printf("Directory\n");
    else    
        printf("Other\n");

    printf("Last Access Time: %s", ctime(&sobj.st_atime));
    printf("Last Modify Time: %s", ctime(&sobj.st_atime));
    
    return 0;
}

