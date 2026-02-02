int mypow(int base, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}

int mysquare(int num)
{
    return num * num;
}

int myabs(int num)
{
    return (num < 0) ? -num : num;
}

int mymax(int a, int b)
{
    return (a > b) ? a : b;
}

int mymin(int a, int b)
{
    return (a < b) ? a : b;
}

int myfactorial(int num)
{
    if (num < 0) return -1;
    if (num == 0 || num == 1) return 1;
    int result = 1;
    for (int i = 2; i <= num; i++)
        result *= i;
    return result;
}

int mygcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mylcm(int a, int b)
{
    return (a * b) / mygcd(a, b);
}