#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**this module aims to programmatically express logic gates using bitwise operators*/

int main()
{
    int first;
    int second;
    char firstInput[5];
    char secondInput[5];
    char logicGate[10];

    do
    {
        printf("Enter first input (ON/OFF): ");
        fgets(firstInput, 5, stdin);
        if (strcmp(firstInput, "ON\n") == 0)
        {
            first = 1;
        }
        else if (strcmp(firstInput, "OFF\n") == 0)
        {
            first = 0;
        }
        else
        {
            first = -1;
        }
        printf("Enter second input (ON/OFF): ");
        fgets(secondInput, 5, stdin);
        if (strcmp(secondInput, "ON\n") == 0)
        {
            second = 1;
        }
        else if (strcmp(secondInput, "OFF\n") == 0)
        {
            second = 0;
        }
        else
        {
            second = -1;
        }
        if ((first == -1) || (second == -1))
        {
            printf("first and second inputs must be either ON or OFF!\n");
        }
        else
        {
            break;
        }

    } while ((first == -1) || (second == -1));
    printf("\n");
    printf("Enter gate: ");
    fgets(logicGate, 10, stdin);
    if (strcmp(logicGate, "AND\n") == 0)
    {
        printf("Result: %d", first & second);
    }
    else if (strcmp(logicGate, "OR\n") == 0)
    {
        printf("Result: %d", first | second);
    }

    else if (strcmp(logicGate, "XOR\n") == 0)
    {
        printf("Result: %d", first ^ second);
    }
    else if (strcmp(logicGate, "NOR\n") == 0)
    {
        printf("Result: %d", !(first | second));
    }
    else if (strcmp(logicGate, "NAND\n") == 0)
    {
        printf("Result: %d", !(first & second));
    }
    else if (strcmp(logicGate, "NOT\n") == 0)
    {
        printf("Result:\n-First Input: %d\n-Second Input: %d\n", !first, !second);
    }
    else
    {
        printf("Invalid Input!");
    }
    return 0;
}