#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle = NULL;
    int (*fp)(char *);
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    handle = dlopen("./libmystring.so", RTLD_LAZY);
    if (handle == NULL)
    {
        printf("Error: %s\n", dlerror());
        return -1;
    }

    fp = (int (*)(char *))dlsym(handle, "MyStrlen");
    if (fp == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    printf("Length of string is: %d\n", fp(str));

    dlclose(handle);
    return 0;
}
