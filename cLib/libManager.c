#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./models/book.h"
void display(Book bookList[], int capacity);
void addBook(char title[50], char genre[50], Book bookList[], int newBookIndex);

int main()
{
    int newBookIndex = 0;
    int capacity = 1;
    Book *bookList;
    bookList = malloc(sizeof(Book) * capacity);
    char option[10];
    char titleInput[50];
    char genreInput[50];
    int ratingInput;

    do
    {
        printf("Type add to add books, quit to terminate program: ");
        fgets(option, 10, stdin);
        if (strcmp(option, "quit\n") == 0)
        {
            exit(0);
        }
        else if (strcmp(option, "add\n") == 0)
        {
            printf("Enter title: ");
            fgets(titleInput, 50, stdin);
            printf("Enter genre: ");
            fgets(genreInput, 50, stdin);

            addBook(titleInput, genreInput, bookList, newBookIndex);
            printf("\n");
            display(bookList, capacity);
            capacity += 1;
            newBookIndex += 1;
            bookList = (Book *)realloc(bookList, sizeof(Book) * capacity);
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
void display(Book bookList[], int capacity)
{
    int bookListLength = sizeof(Book) * capacity / sizeof(Book);
    printf("you have %d book(s)\n", bookListLength);
    printf("===Your collection===\n");
    for (int i = 0; i < bookListLength; i++)
    {
        printf("Book #%d:\n- Title: %s- Genre: %s", i + 1, bookList[i].title, bookList[i].genre);
        printf("\n");
    }
}