#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./models/book.h"

void display(Book bookList[], int capacity);
void addBook(char title[50], char genre[50], Book bookList[], int newBookIndex);
void deleteBook(Book bookList[], int capacity, int bookIndex);
void saveDataToFile(Book bookList[], int capacity, char mode[5]);
int main()
{
    char *endptr;         // for strtol
    int newBookIndex = 0; // assigned book Index for adding books
    int capacity = 0;     // capacity of books array
    Book *bookList;       // ptr for books array
    bookList = malloc(sizeof(Book) * capacity);
    // dynamically allocate mem for the array of books
    /**user inputs*/
    char option[10];
    char titleInput[50];
    char genreInput[50];
    char chosenIndexStr[5];
    // chosen index to long type
    long chosenIndex;
    char mode[5];

    do
    {
        printf("Welcome to J-Books\n");
        printf("Type dis to display collection\n");
        printf("Type add to add book to collection\n");
        printf("Type delete to remove book from collection\n");
        printf("Type quit to terminate program\n");
        printf("\n");
        printf("Enter Option: ");
        fgets(option, 10, stdin);
        if (strcmp(option, "quit\n") == 0)
        {
            exit(0);
        }
        else if (strcmp(option, "dis\n") == 0)
        {
            display(bookList, capacity);
        }
        else if (strcmp(option, "add\n") == 0)
        {
            printf("Enter title: ");
            fgets(titleInput, 50, stdin);
            printf("Enter genre: ");
            fgets(genreInput, 50, stdin);

            // increase capacity of array by 1 slot
            capacity += 1;
            // reallocate mem for new capacity
            bookList = (Book *)realloc(bookList, sizeof(Book) * capacity);
            addBook(titleInput, genreInput, bookList, newBookIndex);
            strcpy(mode, "w");
            saveDataToFile(bookList, capacity, mode);
            printf("\n");
            display(bookList, capacity);
            // for every append, book index should bubble to end of list
            newBookIndex += 1;
        }
        else if (strcmp(option, "delete\n") == 0)
        {
            printf("Enter book position (1 for first book, etc): ");
            fgets(chosenIndexStr, 5, stdin);
            // convert string type input to long type
            chosenIndex = strtol(chosenIndexStr, &endptr, 10);

            // cannot delete if collection is empty
            if (chosenIndex != 0)
            {

                if (capacity > 0)
                {
                    deleteBook(bookList, capacity, chosenIndex);
                    // capacity decreases by 1 slot
                    capacity -= 1;
                    // reallocate mem for books array
                    bookList = (Book *)realloc(bookList, sizeof(Book) * capacity);
                    strcpy(mode, "w");
                    saveDataToFile(bookList, capacity, mode);
                    printf("\n");
                    display(bookList, capacity);
                }
                else
                {
                    printf("Collection is empty\n\n");
                }
            }
            else
            {
                printf("Invalid input\n");
            }
        }
        else
        {
            printf("Invalid option!\n\n");
        }
    } while (strcmp(option, "quit\n") != 0);

    // deallocate mem
    free(bookList);
    return 0;
}

/*append a new book to the collection*/
void addBook(char newBookTitle[50], char newBookGenre[50], Book bookList[], int newBookIndex)
{

    Book newBook;
    strcpy(newBook.title, newBookTitle);
    strcpy(newBook.genre, newBookGenre);
    // append to list
    bookList[newBookIndex] = newBook;
}

/**remove a book at a specified index*/
void deleteBook(Book bookList[], int capacity, int bookPos)
{
    int bookListLength = sizeof(Book) * capacity / sizeof(Book);
    // cannot delete if book Position specified by user is out of bounds
    if (bookPos < 0 || bookPos > bookListLength)
    {
        printf("Invalid index\n");
    }
    else
    {
        // from chosen pos, shifts every element to left
        for (int i = bookPos - 1; i < bookListLength; i++)
        {
            bookList[i] = bookList[i + 1];
        }
    }
}

/**display list of books in the collection*/
void display(Book bookList[], int capacity)
{

    int bookListLength = sizeof(Book) * capacity / sizeof(Book);

    printf("you have %d book(s)\n", bookListLength);
    printf("===Your collection===\n\n");

    for (int i = 0; i < bookListLength; i++)
    {
        printf("Book #%d:\n- Title: %s- Genre: %s;", i + 1, bookList[i].title, bookList[i].genre);
        printf("\n");
    }
}

/**NOTES:
 * - SAVE DATA TO FILE
 * - LOAD DATA FROM FILE ON STARTUP
 * */

void saveDataToFile(Book bookList[], int capacity, char mode[5])
{
    FILE *fileOut = fopen("myLib.txt", mode);
    int bookListLength = sizeof(Book) * capacity / sizeof(Book);
    for (int i = 0; i < bookListLength; i++)
    {
        /* code */
        fprintf(fileOut, "Book #%d:\n- Title: %s- Genre: %s\n", i + 1, bookList[i].title, bookList[i].genre);
    }
    fclose(fileOut);
}