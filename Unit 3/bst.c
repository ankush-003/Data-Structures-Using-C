#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

typedef struct node {
    int info;
    struct node *lchild;
    struct node *rchild;
}Node;

typedef struct binarySearchTree {
    Node *root;
}BST;

void initTree(BST *tree) {
    tree->root = NULL;
}

Node *createNode(int data) {
    if(data == -1)
        return NULL;

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->info = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

Node *createBST(Node *root,int data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(data < root->info) {
        root->lchild = createBST(root->lchild,data);
    }
    else if(data > root->info) {
        root->rchild = createBST(root->rchild,data);
    }
    else {
        printf("Duplicate info!\n");
        return NULL;
    }
    // return the root after modification otherwise null is returned and causes error
    return root;
}

void inOrder(Node *root) {
    if(root == NULL) {
        return;
    }
    inOrder(root->lchild);
    printf("%d ",root->info);
    inOrder(root->rchild);
}

int main()
{
    BST bstree;
    initTree(&bstree);
    int data;
    do {
        printf("Enter data: ");
        scanf("%d",&data);
        if(bstree.root == NULL) {
            bstree.root = createBST(bstree.root,data);
        }
        else {
            createBST(bstree.root,data);
        }
    }while(data != -1);

    printf("\nInorder Traversal: ");
    inOrder(bstree.root);

    return 0;
}