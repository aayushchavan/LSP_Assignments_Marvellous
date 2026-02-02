#include <stdio.h>

int MyStrlen(char *str)
{
    int len = 0;
    if (str == NULL) return 0;
    while (*str++)
        len++;
    return len;
}

void MyStrcpy(char *dest, char *src)
{
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
}

void MyStrcat(char *dest, char *src)
{
    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
}

int MyStrcmp(char *s1, char *s2)
{
    while (*s1 && *s2 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int MyStrchr(char *str, char ch)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == ch)
            return i;
        i++;
    }
    return -1;
}

void MyStrrev(char *str)
{
    int i = 0, j = MyStrlen(str) - 1;
    char temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int MyStrcount(char *str, char ch)
{
    int count = 0;
    while (*str)
    {
        if (*str == ch)
            count++;
        str++;
    }
    return count;
}

void MyStrupper(char *str)
{
    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
            *str = *str - 32;
        str++;
    }
}