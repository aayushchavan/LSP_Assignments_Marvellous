#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    char str[100];
    void *handle = NULL;
    char *error = NULL;

    int (*upper)(char *) = NULL;
    int (*lower)(char *) = NULL;
    int (*digit)(char *) = NULL;

    printf("Enter string: ");
    scanf("%99s", str);   /* prevent buffer overflow */

    handle = dlopen("./Assignment8.so", RTLD_LAZY);
    if (handle == NULL)
    {
        printf("Error loading library: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    /* Clear old errors */
    dlerror();

    upper = (int (*)(char *))dlsym(handle, "CountUpper");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading CountUpper: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    lower = (int (*)(char *))dlsym(handle, "CountLower");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading CountLower: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    digit = (int (*)(char *))dlsym(handle, "CountDigit");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error loading CountDigit: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    printf("Uppercase letters: %d\n", upper(str));
    printf("Lowercase letters: %d\n", lower(str));
    printf("Digits: %d\n", digit(str));

    dlclose(handle);
    return EXIT_SUCCESS;
}
