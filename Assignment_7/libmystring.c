#include <stdio.h>

int MyStrlen(char *str)
{
    int count = 0;

    if (str == NULL)
    {
        return 0;   
    }

    while (*str != '\0')
    {
        count++;
        str++;
    }

    return count;
}
