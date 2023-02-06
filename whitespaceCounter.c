#include <stdio.h>
#include <ctype.h>
int main()
{

    char input[60]; // buffer overflow 💀
    int whiteSpaceCounter = 0;
    printf("Enter something: \n");

    scanf("%[^\n]", input); // read entire line
    int inputCharactersLength = sizeof(input) / sizeof(input[0]);
    for (int i = 0; i < inputCharactersLength; i++)
    {

        if (isspace(input[i]) != 0)
        {
            whiteSpaceCounter++;
        }
    }
    printf("Your input has: %d white spaces!", whiteSpaceCounter);

    return 0;
}