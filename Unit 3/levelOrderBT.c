#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

typedef struct node {
    int key;
    struct node *lchild;
    struct node *rchild;
}Node;

typedef struct bintree {
    Node *troot;
}BinTree;

typedef struct queue{
    int front;
    int rear;
    Node *ptr[20];
}Q;

int main()
{
    // Code
    return 0;
}