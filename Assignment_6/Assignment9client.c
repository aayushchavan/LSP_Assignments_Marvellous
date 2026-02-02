#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *handle = NULL;
    char *error = NULL;
    int (*fp[3])(int, int) = {NULL, NULL, NULL};

    handle = dlopen("./Assignment9.so", RTLD_LAZY);
    if (handle == NULL)
    {
        printf("Error loading library: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    /* Load Addition */
    dlerror();   // clear old errors
    fp[0] = (int (*)(int, int))dlsym(handle, "Addition");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading Addition: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    /* Load Subtraction */
    dlerror();
    fp[1] = (int (*)(int, int))dlsym(handle, "Subtraction");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading Subtraction: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    /* Load Multiplication */
    dlerror();
    fp[2] = (int (*)(int, int))dlsym(handle, "Multiplication");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading Multiplication: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    printf("Addition: %d\n", fp[0](10, 5));
    printf("Subtraction: %d\n", fp[1](10, 5));
    printf("Multiplication: %d\n", fp[2](10, 5));

    dlclose(handle);
    return EXIT_SUCCESS;
}
