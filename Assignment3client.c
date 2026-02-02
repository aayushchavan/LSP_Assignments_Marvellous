#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *handle = NULL;
    int (*fp)(int, int) = NULL;
    int iret = 0;
    int choice, a, b;
    char *error = NULL;

    handle = dlopen("./Assignment3.so", RTLD_LAZY);
    if (handle == NULL)
    {
        printf("Unable to load the library: %s\n", dlerror());
        return EXIT_FAILURE;
    }

    printf("Library gets loaded successfully\n");

    printf("Enter the number for action:\n");
    printf("1 : Addition\n");
    printf("2 : Subtraction\n");
    printf("3 : Multiplication\n");
    printf("4 : Division\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter 1 number: ");
    scanf("%d", &a);
    printf("Enter 2 number: ");
    scanf("%d", &b);

    /* Clear any old errors */
    dlerror();

    switch (choice)
    {
    case 1:
        fp = (int (*)(int, int))dlsym(handle, "Addition");
        break;
    case 2:
        fp = (int (*)(int, int))dlsym(handle, "subtraction");
        break;
    case 3:
        fp = (int (*)(int, int))dlsym(handle, "Multiplication");
        break;
    case 4:
        fp = (int (*)(int, int))dlsym(handle, "division");
        break;
    default:
        printf("Invalid Choice\n");
        dlclose(handle);
        return EXIT_FAILURE;
    }

    error = dlerror();
    if (error != NULL)
    {
        printf("Error: %s\n", error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    iret = fp(a, b);
    printf("Result is : %d\n", iret);

    dlclose(handle);
    return EXIT_SUCCESS;
}
