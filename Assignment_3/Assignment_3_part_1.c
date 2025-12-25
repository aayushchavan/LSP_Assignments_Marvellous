#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char src[256], dest[256];
    char buffer[1024];
    int fdSrc, fdDest, bytes;

    printf("Enter source file: ");
    scanf("%s",src);

    printf("Enter destination file: ");
    scanf("%s", dest);

    fdSrc = open(src, O_RDONLY);
    if (fdSrc == -1)
    {
        perror("open source");
        return -1;
    }

    fdDest =open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if ( fdDest == -1)
    {
        perror("open destination");
        close(fdSrc);
        return -1;
    }

    while ((bytes = read(fdSrc, buffer, sizeof(buffer))) > 0)
    {
        write(fdDest, buffer, bytes);
    }

    close(fdSrc);
    close(fdDest);

    printf("File copies successfully\n");
    return 0;
}

