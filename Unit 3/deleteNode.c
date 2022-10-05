/*
Deletion of a node in BST:
case1: Leaf Node
case2: Node with 1 child
case 3: Node with 2 children
(inorder successor / inorder predecessor)
*/

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

Node *inOrderSuccessor(Node *root) {
    if(root->lchild == NULL) {
        return root;
    }
    return inOrderSuccessor(root->lchild);
}

Node *deleteNode(Node *root,int data) {
    if(root == NULL) {
        printf("Element Not found!\n");
        return NULL;
    }
    if(data > root->info) {
        root->rchild = deleteNode(root->rchild,data);
    }
    else if(data < root->info) {
        root->lchild = deleteNode(root->lchild,data);
    }
    else {
        Node *temp = root;
        if(root->lchild == NULL && root->rchild == NULL) {
            free(temp);
            root = NULL;
        }
        else if(root->lchild == NULL) {
            root = root->rchild;
            free(temp);
        }
        else if(root->rchild == NULL) {
            root = root->lchild;
            free(temp);
        }
        else {
            root->info = (inOrderSuccessor(root->rchild))->info;
            root->rchild = deleteNode(root->rchild,root->info);
        }
        return root;
    }
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

    printf("Enter Node to be deleted: ");
    scanf("%d",&data);
    
    deleteNode(bstree.root,data);

    printf("\nInorder Traversal: ");
    inOrder(bstree.root);
    return 0;
}