#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handler = NULL;
    int (*fp)(int);
    int no, ans;

    printf("Enter a number to be checked: ");
    scanf("%d", &no);

    handler = dlopen("./libperfect.so", RTLD_LAZY);
    if (handler == NULL)
    {
        printf("Error: %s\n", dlerror());
        return -1;
    }

    fp = (int (*)(int))dlsym(handler, "isperfect");
    if (fp == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handler);
        return -1;
    }

    ans = fp(no);

    if (ans == 1)
        printf("Number %d is a PERFECT number\n", no);
    else
        printf("Number %d is NOT a perfect number\n", no);

    dlclose(handler);
    return 0;
}
