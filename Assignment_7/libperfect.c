#include <stdio.h>
#include <dlfcn.h>

int isperfect(int no)
{
    void *handler = NULL;
    int (*fp)(int) = NULL;
    int sum = 0;
    char *error;

    handler = dlopen("./libhelper.so", RTLD_LAZY);
    if (handler == NULL)
    {
        printf("dlopen error: %s\n", dlerror());
        return 0;
    }

    dlerror();   // clear old errors
    fp = (int (*)(int))dlsym(handler, "sumoffactors");

    error = dlerror();
    if (error != NULL)
    {
        printf("dlsym error: %s\n", error);
        dlclose(handler);
        return 0;
    }

    sum = fp(no);
    dlclose(handler);

    return (sum == no);
}
