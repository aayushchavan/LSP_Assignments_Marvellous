#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char fname[100]; 
    char ch;
    int ret;
    
    printf("Enter file name: ");
    scanf("%s", fname);

    printf("Check permission (r / w / x): ");
    scanf(" %c", &ch);

    switch(ch)
    {

    case 'r':
        ret = access(fname, R_OK);
        break;
    case 'w':
        ret = access(fname, W_OK);
        break;

    case 'x':
        ret = access(fname, X_OK);
        break;
    
    default:
        printf("Invalid option\n");
        return -1;
    }

    if (ret == 0)
        printf("Accessible\n");
    else
        perror("Not accessible");

    return 0;
}