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

void createNode(treeNode **node) {
    treeNode *newNode = (treeNode *) malloc(sizeof(treeNode));
    int info;
    printf("Enter Node info(-1 to end): ");
    scanf("%d",&info);
    
    if(info == -1)
        *node = NULL;
    else {
        *node = newNode;
        (*node)->data = info;
        printf("Creating left child of %d\n",info);
        createNode(&(*node)->left);
        printf("Creating right child of %d\n",info);
        createNode(&(*node)->right);
    }    
}

void inorder(treeNode*root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

//counting height of tree
int height(treeNode *root) {
    if(root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight) ? leftHeight +1 : rightHeight+1;
}

int numberOfNodes(treeNode *root) {
    if(root == NULL) {
        return 0;
    }
    return numberOfNodes(root->left) + numberOfNodes(root->right) + 1;
}

int main()
{
    treeNode *root = NULL;
    int data;
    printf("Creating root\n");
    createNode(&root);
    inorder(root);
    printf("\nHeight of tree: %d\n",height(root) - 1);// if root is taken as 0
    printf("Number of nodes: %d\n",numberOfNodes(root));
    return 0;
}