// New node always goes in as a leaf node
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

typedef struct threadedNode {
    int key;
    struct threadedNode *lchild;
    struct threadedNode *rchild;
    int rthread;
}Node;

typedef struct tree {
    Node *root;
}Tree;

void initTree(Tree *pt) {
    pt->root = NULL;
}

Node *createNode() {
    Node *temp = (Node *) malloc(sizeof(Node));
    int data;
    printf("Enter the info: ");
    scanf("%d",&data);
    temp->key = data;
    temp->lchild = NULL;
    temp->rchild = NULL;
    temp->rthread = 1;

}

void setLeft(Node *p, Node *temp) {
    if(p == NULL) {
        return;
    }
    if(p->lchild != NULL) {
        return;
    }

    p->lchild = temp;
    temp->rchild = p;// Inorder successor
}

void setRight(Node *p,Node *temp) {
    if(p == NULL) {
        return;
    }
    if(!p->rthread) return;
    temp->rchild = p->rchild;
    p->rchild = temp;
    p->rthread = 0;
}

void createTree(Tree *pt) {
    Node *temp,*p,*q;
    int choice;
    pt->root = createNode();
    do {
        temp = createNode();
        q = NULL;
        p = pt->root;
        while(p != NULL) {
            q = p;
            if(temp->key == p->key) {
                printf("Duplicate Node!\n");
                break;
            }
            if(temp->key < p->key) {
                p = p->lchild;
            }
            else {
                if(!p->rthread) {
                    p = p->rchild;
                }
                else {
                    break;
                }
            }
        }
        if(p == NULL) {
            // we have to insert at left
            setLeft(q,temp);
        }
        else {
            setRight(p,temp);
        }
        printf("Do you want to add another: ");
        scanf("%d",&choice);
    }while(choice) ;
}

void inorder(Tree *pt) {
    Node *p,*q;
    p = pt->root;
    q = NULL;
    do
    {
        q = NULL;
        while(p) {
            q = p;
            p = p->lchild;
        }
        if(q != NULL) {
            printf("%d ",q->key);
            p = q->rchild;
        
            while(q->rthread && p != NULL) {
                printf("%d ",p->key);
                q = p;
                p = p->rchild;
            }
        }
    } while (q != NULL);
}

int main()
{
    Tree bt;
    initTree(&bt);
    createTree(&bt);
    printf("Inorder Traversal: ");
    inorder(&bt);
    return 0;
}