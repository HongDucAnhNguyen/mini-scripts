#include <stdio.h>
#include <ctype.h>
int main()
{
    /**this script counts the number of whitespace present in your input*/
    char input[60];
    int whiteSpaceCounter = 0;
    printf("Enter something: \n");

    fgets(input, 60, stdin); // no overflows
    int inputCharactersLength = sizeof(input) / sizeof(input[0]);
    for (int i = 0; i < inputCharactersLength; i++)
    {

        if (isspace(input[i]) != 0)
        {
            whiteSpaceCounter++;
        }
    }
    printf("Your input has: %d white spaces!", whiteSpaceCounter - 1); // exclude \0

    return 0;
}