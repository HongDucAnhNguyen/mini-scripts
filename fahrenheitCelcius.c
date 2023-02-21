#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main()
{

    /**prints a table of fahrenheit temperature values and their corresponding Celcius conversion
     *
     * starting value for fahrenheit temperature is based off of user input
     *
     */

    int initialValue;
    bool isInputInteger;
    int celcius;
    long fahrenheit;
    char *endptr;
    int step = 20;   // distance between values in the table
    int limit = 200; // max value in the table
    do
    {
        char *input = (char *)malloc(100); // type casted as char
        printf("Enter starting value:\n");
        fgets(input, 100, stdin);
        for (initialValue = 0; initialValue < strlen(input) - 1; ++initialValue) 
        {
            if (!isdigit(input[initialValue]))
            {
                printf("Input must be of type number!\n ");
                isInputInteger = false;
            }
            else
            {
                isInputInteger = true;
            }
        }
        fahrenheit = strtol(input, &endptr, 10);
        free(input); // deallocate
    } while (isInputInteger == false);

    printf("---------------\n");
    printf("| Fahr\t| Cel |\n");
    printf("---------------\n");
    while (fahrenheit <= limit)
    {
        celcius = 5 * (fahrenheit - 32) / 9;

        printf("| %d\t| %d |\n", fahrenheit, celcius);
        printf("---------------\n");
        fahrenheit += step;
    }
    return 0;
}