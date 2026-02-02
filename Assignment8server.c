#include <ctype.h>

int CountUpper(const char *str)
{
    int count = 0;
    while (*str)
    {
        if (isupper((unsigned char)*str))
            count++;
        str++;
    }
    return count;
}

int CountLower(const char *str)
{
    int count = 0;
    while (*str)
    {
        if (islower((unsigned char)*str))
            count++;
        str++;
    }
    return count;
}

int CountDigit(const char *str)
{
    int count = 0;
    while (*str)
    {
        if (isdigit((unsigned char)*str))
            count++;
        str++;
    }
    return count;
}
