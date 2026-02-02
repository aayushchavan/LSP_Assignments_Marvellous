#include <stdio.h>

/* Global counter variable */
static int counter = 0;

void Increment(void)
{
    counter++;
}

void Display(void)
{
    printf("Counter value = %d\n", counter);
}

void Reset(void)
{
    counter = 0;
}
