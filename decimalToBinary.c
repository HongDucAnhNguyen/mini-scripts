#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /**script to convert decimal to binary*/
    char input[100];
    char result[100];
    char remainderToStr[10];
    char *endptr;
    long number;
    int remainderDigit;

    do
    {
        printf("Enter Decimal:\n");
        scanf("%s", &input);
        number = strtol(input, &endptr, 10);

        if (number == 0)
        {
            printf("Input must be a decimal number!\n");
        }
        else
        {
            break;
        }
    } while (number == 0);

    while (number != 0)
    {
        remainderDigit = number % 2;
        number = number / 2;
        sprintf(remainderToStr, "%d", remainderDigit);
        strcat(result, remainderToStr);
    }
    printf("%s", strrev(result));
    return 0;
}
