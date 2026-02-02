#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *handle = dlopen("./Assignment1.so", RTLD_LAZY);
    if (handle == NULL)
    {
        printf("Error: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    printf("Library loaded successfully\n");

    dlclose(handle);
    return EXIT_SUCCESS;
}
