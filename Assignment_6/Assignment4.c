#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *handle = NULL;
    int (*fp)(int, int) = NULL;
    int iret = 0;
    char *error = NULL;

    handle = dlopen("./Assignment1.so", RTLD_LAZY);
    if (handle == NULL)
    {
        printf("Unable to load library: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    printf("Library gets loaded successfully\n");

    /* Clear old errors */
    dlerror();

    fp = (int (*)(int, int))dlsym(handle, "Addition");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    iret = fp(11, 10);
    printf("Addition of the 2 numbers is : %d\n", iret);

    /* Clear old errors */
    dlerror();

    fp = (int (*)(int, int))dlsym(handle, "Multiplication");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    iret = fp(11, 13);
    printf("Multiplication of the 2 numbers is : %d\n", iret);

    dlclose(handle);
    return EXIT_SUCCESS;
}
