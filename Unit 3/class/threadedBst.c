#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

struct node {
    int key;
    struct node *lchild;
    struct node *rchild;
    int lthread;
    int rthread;
};
typedef struct node Node;

Node *insertBst(Node *root,int data) {
    Node *ptr = root;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->key = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->lthread = newNode->rthread = 1;
    if(root == NULL) {
        return newNode;
    }
    Node *parent = NULL;
    while(ptr!=NULL) {
        if(data == ptr->key) {
            printf("Duplicate value!\n");
            return root;
        }
        parent = ptr;
        if(data < ptr->key) {
            if(ptr->lthread == 0) {// only then there is a child to move
                ptr = ptr->lchild;
            }
            else {
                break;
            }
        }
        else {
            if(ptr->rthread == 0) {
                ptr = ptr->rchild;
            }
            else {
                break;
            }
        }
    }
    // After loop we know where to insert
    if(data < parent->key) {// as we dont know whether data was to be inserted in left or right
        newNode->lchild = parent->lchild;
        newNode->rchild = parent;
        parent->lchild = newNode;
        parent->lthread = 0;
    }
    else {
        newNode->rchild = parent->rchild;
        newNode->lchild = parent;
        parent->rchild = newNode;
        parent->rthread = 0;
    }
    return root;
}

Node *inorderSuccessor(Node *ptr) {
    if(ptr->rthread) {
        return ptr->rchild;
    }
    ptr = ptr->rchild;
    while(ptr->lthread == 0) {
        ptr = ptr->lchild;
    }
    return ptr;
}

Node *inorderPredecessor(Node *ptr) {
    if(ptr->lthread) {
        return ptr->lchild;
    }
    ptr = ptr->lchild;
    while(ptr->rthread == 0) {
        ptr = ptr->rchild;
    }
    return ptr;
}

void inorder(Node *root) {
    Node *ptr = root;
    if(root == NULL) {
        printf("Tree is Empty!\n");
        return;
    }
    while(ptr->lthread == 0) {
        ptr = ptr->lchild;
    }
    while (ptr != NULL)
    {
        printf("%d ",ptr->key);
        ptr = inorderSuccessor(ptr);// as right child might have subtree
    }
    printf("\n");
}

int main()
{
    // Code
    Node *root = NULL;
    root = insertBst(root,50);
    root = insertBst(root,69);
    root = insertBst(root,70);
    root = insertBst(root,49);
    return 0;
}