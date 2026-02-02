#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *handle = NULL;
    char *error = NULL;

    void (*inc)(void) = NULL;
    void (*disp)(void) = NULL;
    void (*reset)(void) = NULL;

    handle = dlopen("./Assignment7.so", RTLD_LAZY);
    if (handle == NULL)
    {
        printf("Error loading library: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    /* Load Increment */
    dlerror();  
    inc = (void (*)(void))dlsym(handle, "Increment");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading Increment: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    /* Load Display */
    dlerror();
    disp = (void (*)(void))dlsym(handle, "Display");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading Display: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    /* Load Reset */
    dlerror();
    reset = (void (*)(void))dlsym(handle, "Reset");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading Reset: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    /* Function calls */
    inc();
    inc();
    disp();

    reset();
    disp();

    dlclose(handle);
    return EXIT_SUCCESS;
}
