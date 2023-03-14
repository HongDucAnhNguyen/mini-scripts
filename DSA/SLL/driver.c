#include <stdio.h>
#include <stdlib.h>
#include "./node.c"
/**this model is the driver for the implementation of the data structure called Singly Linked List*/
int main()
{
    Node *head = NULL; // ptr to head
    /**setting the node*/
    head = (Node *)malloc(sizeof(Node));
    head->data = 90;
    head->link = NULL;
    // printing Head Node's data
    printf("%d", head->data); // prints 90
    return 0;
}
