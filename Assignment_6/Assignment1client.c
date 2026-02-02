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

    /* Clear any existing errors */
    dlerror();

    fp = (int (*)(int, int))dlsym(handle, "Addition");
    error = dlerror();
    if (error != NULL)
    {
        printf("Unable to get the address of the function Addition: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    iret = fp(11, 10);
    printf("Addition of the 2 numbers is : %d\n", iret);

    /* Clear any existing errors */
    dlerror();

    fp = (int (*)(int, int))dlsym(handle, "subtraction");
    error = dlerror();
    if (error != NULL)
    {
        printf("Unable to get the address of the function subtraction: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    iret = fp(11, 13);
    printf("Subtraction of the 2 numbers is : %d\n", iret);

    dlclose(handle);
    return EXIT_SUCCESS;
}
