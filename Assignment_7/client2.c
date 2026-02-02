#include<stdio.h>
#include<dlfcn.h>

int main()
{
    int a,b;
    void *handler=NULL;
    int (*fp)(int,int);
    int ans;
    printf("Enter numbers for addition and subtraction\n");
    scanf("%d",&a);
    scanf("%d",&b);

    handler=dlopen("./libaddition.so",RTLD_LAZY);
    if (handler == NULL)
    {
        printf("Error: %s\n", dlerror());
        return -1;
    }

    fp = (int (*)(int,int))dlsym(handler, "addition");
    if (fp == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handler);
        return -1;
    }
    ans=fp(a,b);

    printf("Addition of 2 numbers is: %d\n",ans);

    handler=dlopen("./libsubstraction.so",RTLD_LAZY);
    if (handler == NULL)
    {
        printf("Error: %s\n", dlerror());
        return -1;
    }

    fp = (int (*)(int))dlsym(handler, "substraction");
    if (fp == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(handler);
        return -1;
    }
    ans=fp(a,b);

    printf("Subtraction of 2 numbers is: %d\n",ans);

    dlclose(handler);
    return 0;

}