#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

int main()
{
    void *h1=NULL, *h2=NULL;
    int option;
    
    h1 = dlopen("./libmystring.so", RTLD_LAZY);
    h2 = dlopen("./libmymath.so", RTLD_LAZY);
    
    if (!h1 || !h2)
    {
        printf("Error loading libraries: %s\n", dlerror());
        return -1;
    }

    printf("\n---- MENU ----\n");
    printf("1 : String Functions\n");
    printf("2 : Math Functions\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    
    switch (option)
    {
    case 1:  // STRING FUNCTIONS
    {
        int choice;
        printf("\n--- STRING MENU ---\n");
        printf("1. String Length\n");
        printf("2. String Copy\n");
        printf("3. String Concatenate\n");
        printf("4. String Compare\n");
        printf("5. Find Character Index\n");
        printf("6. Reverse String\n");
        printf("7. Count Character Occurrences\n");
        printf("8. Convert to Uppercase\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
            {
                int (*fp)(char *);
                char a[100];
                fp = (int(*)(char *))dlsym(h1, "MyStrlen");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter a string: ");
                scanf("%s", a);
                printf("The answer is: %d\n", fp(a));
                break;
            }

            case 2:
            {
                void (*fp)(char *, char *);
                char a[100], b[100];
                fp = (void(*)(char *, char *))dlsym(h1, "MyStrcpy");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter a string: ");
                scanf("%s", a);
                fp(b, a);
                printf("The answer is: %s\n", b);
                break;
            }

            case 3:
            {
                void (*fp)(char *, char *);
                char a[200], b[100];
                fp = (void(*)(char *, char *))dlsym(h1, "MyStrcat");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter first string: ");
                scanf("%s", a);
                printf("Enter second string: ");
                scanf("%s", b);
                fp(a, b);
                printf("The answer is: %s\n", a);
                break;
            }

            case 4:
            {
                int (*fp)(char *, char *);
                char a[100], b[100];
                fp = (int(*)(char *, char *))dlsym(h1, "MyStrcmp");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter first string: ");
                scanf("%s", a);
                printf("Enter second string: ");
                scanf("%s", b);
                int result = fp(a, b);
                if (result == 0)
                    printf("Strings are equal\n");
                else if (result < 0)
                    printf("First string is smaller\n");
                else
                    printf("First string is greater\n");
                break;
            }

            case 5:
            {
                int (*fp)(char *, char);
                char a[100], ch;
                fp = (int(*)(char *, char))dlsym(h1, "MyStrchr");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter a string: ");
                scanf("%s", a);
                printf("Enter character to find: ");
                scanf(" %c", &ch);
                int index = fp(a, ch);
                if (index == -1)
                    printf("Character not found\n");
                else
                    printf("Character found at index: %d\n", index);
                break;
            }

            case 6:
            {
                void (*fp)(char *);
                char a[100];
                fp = (void(*)(char *))dlsym(h1, "MyStrrev");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter a string: ");
                scanf("%s", a);
                fp(a);
                printf("The answer is: %s\n", a);
                break;
            }

            case 7:
            {
                int (*fp)(char *, char);
                char a[100], ch;
                fp = (int(*)(char *, char))dlsym(h1, "MyStrcount");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter a string: ");
                scanf("%s", a);
                printf("Enter character to count: ");
                scanf(" %c", &ch);
                printf("The answer is: %d\n", fp(a, ch));
                break;
            }

            case 8:
            {
                void (*fp)(char *);
                char a[100];
                fp = (void(*)(char *))dlsym(h1, "MyStrupper");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter a string: ");
                scanf("%s", a);
                fp(a);
                printf("The answer is: %s\n", a);
                break;
            }
        
            default:
                printf("Invalid Option Choice\n");
                break;
        }
        break;
    }

    case 2:  // MATH FUNCTIONS
    {
        int choice;
        printf("\n--- MATH MENU ---\n");
        printf("1. Power (a^b)\n");
        printf("2. Square (a^2)\n");
        printf("3. Absolute value\n");
        printf("4. Maximum of two numbers\n");
        printf("5. Minimum of two numbers\n");
        printf("6. Factorial\n");
        printf("7. GCD\n");
        printf("8. LCM\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
            {
                int a, b;
                int (*fp)(int, int);
                fp = (int(*)(int, int))dlsym(h2, "mypow");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter a number and its power: ");
                scanf("%d %d", &a, &b);
                printf("The answer is: %d\n", fp(a, b));
                break;
            }

            case 2:
            {
                int a;
                int (*fp)(int);
                fp = (int(*)(int))dlsym(h2, "mysquare");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter a number: ");
                scanf("%d", &a);
                printf("The answer is: %d\n", fp(a));
                break;
            }

            case 3:
            {
                int a;
                int (*fp)(int);
                fp = (int(*)(int))dlsym(h2, "myabs");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter a number: ");
                scanf("%d", &a);
                printf("The answer is: %d\n", fp(a));
                break;
            }

            case 4:
            {
                int a, b;
                int (*fp)(int, int);
                fp = (int(*)(int, int))dlsym(h2, "mymax");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter 2 numbers to compare: ");
                scanf("%d %d", &a, &b);
                printf("The answer is: %d\n", fp(a, b));
                break;
            }

            case 5:
            {
                int a, b;
                int (*fp)(int, int);
                fp = (int(*)(int, int))dlsym(h2, "mymin");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter 2 numbers to compare: ");
                scanf("%d %d", &a, &b);
                printf("The answer is: %d\n", fp(a, b));
                break;
            }

            case 6:
            {
                int a;
                int (*fp)(int);
                fp = (int(*)(int))dlsym(h2, "myfactorial");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter a number: ");
                scanf("%d", &a);
                printf("The answer is: %d\n", fp(a));
                break;
            }

            case 7:
            {
                int a, b;
                int (*fp)(int, int);
                fp = (int(*)(int, int))dlsym(h2, "mygcd");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter 2 numbers: ");
                scanf("%d %d", &a, &b);
                printf("The answer is: %d\n", fp(a, b));
                break;
            }

            case 8:
            {
                int a, b;
                int (*fp)(int, int);
                fp = (int(*)(int, int))dlsym(h2, "mylcm");
                if (!fp) {
                    printf("Error: %s\n", dlerror());
                    break;
                }
                printf("Enter 2 numbers: ");
                scanf("%d %d", &a, &b);
                printf("The answer is: %d\n", fp(a, b));
                break;
            }
            
            default:
                printf("Invalid Option Choice\n");
                break;
        }
        break;
    }
    
    default:
        printf("Invalid Option Choice\n");
        break;
    }

    dlclose(h1);
    dlclose(h2);

    return 0;
}