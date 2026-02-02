#include <stdio.h>
#include <string.h>
#include <ctype.h>

void display(char *s)
{
    printf("%s\n", s);

    int count = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            count++;
        }
    }

    printf("Alphabet count: %d\n", count);
}
