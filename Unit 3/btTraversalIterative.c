#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#define MAX 50

typedef struct binaryTreeNode {
    int info;
    struct binaryTreeNode *lchild,*rchild;
}Node;

typedef struct stack {
    Node *aux[MAX];
    int top;
}Stack;

void initStack(Stack *sptr) {
    sptr->top = -1;
}

int isEmpty(Stack *sptr) {
    return sptr->top == -1;
}

void push(Stack *sptr,Node *root) {
    if(sptr->top > MAX -1) {
        printf("Stack is full!\n");
    }
    else {
        sptr->aux[++(sptr->top)] = root;
        // sptr->top++;
    }
}

Node *pop(Stack *sptr) {
    if(sptr->top == -1) {
        return NULL;
    }
    else {
        return sptr->aux[sptr->top--];
    }
}

void createNode(Node **root,int data) {
    *root = (Node *) malloc(sizeof(Node));
    (*root)->info = data;
    (*root)->lchild = NULL;
    (*root)->rchild = NULL;
}

void createTree(Node **root) {
    int info;
    printf("Enter Node info(-1 to End): ");
    scanf("%d",&info);
    if(info == -1) {
        *root = NULL;
        return;
    }
    createNode(root,info);
    printf("Creating lchild for node %d:\n",info);
    createTree(&((*root)->lchild));
    printf("Creating rchild for node %d:\n",info);
    createTree(&((*root)->rchild));
}

void iterativeInorder(Node *root) {
    Stack s;
    initStack(&s);
    Node *current = root;
    Node *poppedNode = NULL;
    do
    {
        while(current != NULL) {
            // Travel down left branches as far as possible
            push(&s,current);
            current = current->lchild;
        }// left subtree is empty
        poppedNode = pop(&s);
        printf("%d ",poppedNode->info);
        current = poppedNode->rchild;
    } while (!isEmpty(&s) || current != NULL);
}

void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->lchild);
    printf("%d ",root->info);
    inorder(root->rchild);
}

void preorder(Node *root) {
    if(root == NULL) {
        return;
    }
    printf("%d ",root->info);
    preorder(root->lchild);
    preorder(root->rchild);
}

void iterativePreorder(Node *root) {
    if(root == NULL) {
        printf("Tree is Empty!\n");
        return;
    }
    Node *current = root;
    Stack s;
    initStack(&s);
    push(&s,current);
    while (!isEmpty(&s))
    {
        current = pop(&s);
        printf("%d ",current->info);
        // right child is pushed first so left child is processed first (LIFO)
        if(current->rchild) {
            push(&s,current->rchild);
        }
        if(current->lchild) {
            push(&s,current->lchild);
        }
    }
}

void postorder(Node *root) {
    if(root == NULL) {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->info);
}

void iterativePostorder(Node *root) {
    Stack s1,s2;
    initStack(&s1),initStack(&s2);
    if(root == NULL) {
        return;
    }
    Node *current = root;
    push(&s1,current);
    while(!isEmpty(&s1)) {
        current = pop(&s1);
        push(&s2,current);
        if(current->lchild) {
            push(&s1,current->lchild);
        }
        // left child is pushed to s1 so right child is pushed to s2 first (LIFO)
        if(current->rchild) {
            push(&s1,current->rchild);
        }
    }
    while(!isEmpty(&s2)) {
        printf("%d ",pop(&s2)->info);
    }
}

int main(void)
{
    Node *root = NULL;
    printf("Creating Binary tree!\n");
    createTree(&root);

    printf("Inorder Traversal(recursive): ");
    inorder(root);
    printf("\nInorder Traversal(iterative): ");
    iterativeInorder(root);

    printf("\nPreorder Traversal(recursive): ");
    preorder(root);
    printf("\nPreorder Traversal(iterative): ");
    iterativePreorder(root);

    printf("\nPostorder Traversal(recursive): ");
    postorder(root);
    printf("\nPostorder Traversal(iterative): ");
    iterativePostorder(root);
    return 0;
}