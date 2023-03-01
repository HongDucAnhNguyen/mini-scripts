#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./models/book.h"
void display(Book bookList[], int capacity);
void addBook(char title[50], char genre[50], Book bookList[], int newBookIndex);
void deleteBook(Book bookList[], int capacity, int bookIndex);
int main()
{
    char *endptr;
    int newBookIndex = 0;
    int capacity = 0;
    Book *bookList;
    bookList = malloc(sizeof(Book) * capacity);
    char option[10];
    char titleInput[50];
    char genreInput[50];
    char chosenIndexStr[5];
    long chosenIndex;
    int ratingInput;

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
            capacity += 1;
            bookList = (Book *)realloc(bookList, sizeof(Book) * capacity);
            addBook(titleInput, genreInput, bookList, newBookIndex);
            printf("\n");
            display(bookList, capacity);
            newBookIndex += 1;
        }
        else if (strcmp(option, "delete\n") == 0)
        {
            printf("Enter book position (1 for first book, etc): ");
            fgets(chosenIndexStr, 5, stdin);
            chosenIndex = strtol(chosenIndexStr, &endptr, 10);
            if (chosenIndex != 0)
            {

                if (capacity > 0)
                {
                    deleteBook(bookList, capacity, chosenIndex);
                    capacity -= 1;
                    bookList = (Book *)realloc(bookList, sizeof(Book) * capacity);
                    printf("\n");
                    display(bookList, capacity);
                }
                else
                {
                    printf("Collection is empty\n");
                }
            }
            else
            {
                printf("Invalid input\n");
            }
        }
        else
        {
            printf("Invalid option!\n");
        }
    } while (strcmp(option, "quit\n") != 0);

    free(bookList);
    return 0;
}

void addBook(char newBookTitle[50], char newBookGenre[50], Book bookList[], int newBookIndex)
{

    Book newBook;
    strcpy(newBook.title, newBookTitle);
    strcpy(newBook.genre, newBookGenre);
    bookList[newBookIndex] = newBook;
}

void deleteBook(Book bookList[], int capacity, int bookPos)
{
    int bookListLength = sizeof(Book) * capacity / sizeof(Book);
    if (bookPos < 0 || bookPos > bookListLength)
    {
        printf("Invalid index\n");
    }
    else
    {
        for (int i = bookPos - 1; i < bookListLength; i++)
        {
            bookList[i] = bookList[i + 1];
        }
    }
}

void display(Book bookList[], int capacity)
{
    int bookListLength = sizeof(Book) * capacity / sizeof(Book);

    printf("you have %d book(s)\n", bookListLength);
    printf("===Your collection===\n");
    printf("\n");
    for (int i = 0; i < bookListLength; i++)
    {
        printf("Book #%d:\n- Title: %s- Genre: %s", i + 1, bookList[i].title, bookList[i].genre);
        printf("\n");
    }
}