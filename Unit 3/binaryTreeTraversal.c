#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

typedef struct node {
    int info;
    struct node *lchild;
    struct node *rchild;
}Node;

typedef struct binarytree {
    Node *root;
}BinaryTree;

void initBT(BinaryTree *btptr)
{
    btptr->root = NULL;
}

Node *createNode(BinaryTree *btptr);
void inorder(Node *cur);
void preorder(Node *cur);
void postorder(Node *cur);

int main(void)
{
    BinaryTree binTree;
    initBT(&binTree);
    binTree.root = createNode(&binTree);
    printf("Inorder traversal of Binary Tree: ");
    inorder(binTree.root);

    printf("\nPreorder traversal of Binary Tree: ");
    preorder(binTree.root);

    printf("\nPostorder traversal of Binary Tree: ");
    postorder(binTree.root);
    return 0;
}

Node *createNode(BinaryTree *btptr)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    int info;
    printf("Enter Node info(-1 to end): ");
    scanf("%d",&info);
    
    if(info == -1)
        return NULL;

    newNode->info = info;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    if (btptr->root == NULL) {
        printf("Creating root Node\n");
        btptr->root = newNode;
    }

    printf("Creating left child for Node %d\n",info);
    newNode->lchild = createNode(btptr);
    printf("Creating right child for Node %d\n",info);
    newNode->rchild = createNode(btptr);

    return newNode;    
}

void inorder(Node *cur)
{
    // Left Node Right
    if(cur == NULL) {
        return;
    }
    else {
        inorder(cur->lchild);
        printf("%d ",cur->info);
        inorder(cur->rchild);
    }    
}

void preorder(Node *cur)
{
    // Node Left Right
    if(cur == NULL)
        return;
    printf("%d ",cur->info);
    preorder(cur->lchild);
    preorder(cur->rchild);    
}

void postorder(Node *cur)
{
    // Left Right Node
    if(cur == NULL)
        return;
    postorder(cur->lchild);
    postorder(cur->rchild);
    printf("%d ",cur->info);    
}