#include<stdio.h>
#include<dlfcn.h>

int main()
{

    void *handle=NULL;
    void (*fp)(char *);
    char s[100];


    printf("Enter a string :");
    scanf("%s",s);

    handle=dlopen("./libdisplay.so",RTLD_LAZY);
    if (handle == NULL)
    {
        printf("Error: %s\n", dlerror());
        return -1;
    }

    fp = (void(*)(char))dlsym(handle,"display");

    if (fp == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    fp(s);



    return 0;
}