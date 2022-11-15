#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
};
typedef struct treeNode treeNode;

void createNode(treeNode **node, int data) {
    if(*node == NULL) {
        *node = (treeNode *) malloc(sizeof(node));
        (*node)->data = data;
        (*node)->left = NULL;
        (*node)->right = NULL;
    }
    printf("Enter left child of %d(-1 to end): ", data);
    scanf("%d", &data);
    if(data != -1) {
        createNode(&(*node)->left, data);
    }
    printf("Enter right child of %d(-1 to end): ", data);
    scanf("%d", &data);
    if(data != -1) {
        createNode(&(*node)->right, data);
    }
}

void inorder(node *root) {
    if(root == NULL) {
        retun;
    }
}

int main()
{
    // Code
    return 0;
}