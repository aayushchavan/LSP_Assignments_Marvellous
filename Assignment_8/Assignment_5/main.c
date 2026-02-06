#include <stdio.h>

int Add(int, int);
int Sub(int, int);
int Mul(int, int);
int Div(int, int);

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Add = %d\n", Add(a, b));
    printf("Sub = %d\n", Sub(a, b));
    printf("Mul = %d\n", Mul(a, b));
    printf("Div = %d\n", Div(a, b));

    return 0;
}
