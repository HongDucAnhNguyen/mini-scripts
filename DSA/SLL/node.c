/**
 *defining a Node Structure
 *
 * Self Referential Struct
 *
 * -> struct which contains ptr to a struct of same type/ self
 *
 *
 * struct abc {
 * int a;
 * char b;
 *
 * struct abc *self;
 *
 *
 * }
 *
 *
 */

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node Node;
