#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    void *handle = NULL;
    void *symbol = NULL;
    char *error = NULL;

    if (argc != 3)
    {
        printf("Usage: %s <Shared_Library_Path> <Symbol_Name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    handle = dlopen(argv[1], RTLD_LAZY);
    if (handle == NULL)
    {
        printf("Library Load Error: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    /* Clear old errors */
    dlerror();

    symbol = dlsym(handle, argv[2]);
    error = dlerror();

    if (error != NULL)
    {
        printf("Symbol '%s' NOT found\n", argv[2]);
        printf("Error: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    printf("Symbol '%s' FOUND\n", argv[2]);
    printf("Address: %p\n", symbol);

    dlclose(handle);
    return EXIT_SUCCESS;
}
