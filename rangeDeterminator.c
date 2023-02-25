#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int main()
{

    char *endptr; // pointer of char after numerical value
    char input[10];
    long option;
    printf("Select option:\n");
    printf("1. Integer signed\n");
    printf("2. Integer unsigned\n");
    printf("3. long\n");
    fgets(input, 10, stdin);
    option = strtol(input, &endptr, 10); // base = 10, base 10 numbers
    if (option <= 0)
    {
        printf("Invalid option, you killed the system, its crashing\n");
        exit(0);
    }
    printf("The range for this type is: ");
    switch (option)
    {
    case 1:
        printf("%d to %d", INT_MIN, INT_MAX);
        break;
    case 2:
        printf("%u to %u", 0, UINT_MAX);
        break;
    case 3:
        printf("%ld to %ld", LONG_MIN, LONG_MAX);
        break;
    default:
        break;
    }
    return 0;
}