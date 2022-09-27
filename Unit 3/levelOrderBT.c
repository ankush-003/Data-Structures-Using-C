#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#define SIZE 20

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node Node;

struct binaryTree {
    Node *root;
};
typedef struct binaryTree binTree;

struct queue{
    int front;
    int rear;
    Node *ptr[SIZE];
};
typedef struct queue Q;

void initTree(binTree *btptr) 
{
    btptr->root = NULL;
}

void initQ(Q *qptr)
{
    qptr->front=-1;
    qptr->rear=-1;
}

void enqueue(Q *qptr,Node *newNode)
{
    if(qptr->rear == SIZE - 1) {
        printf("Queue is Full!\n");
    }
    else {
        if(qptr->front == -1)
            qptr->front++;
        qptr->rear++;
        qptr->ptr[qptr->rear] = newNode;
    }
}

Node *dequeue(Q *qptr) 
{
    if(qptr->front==-1)
        return NULL;

    Node *temp;
    temp = qptr->ptr[qptr->front];
    if(qptr->front == qptr->rear) {
        qptr->front = -1;
        qptr->rear = -1;
    }
    else {
        qptr->front++;
    }
    return temp;
}

Node *createNode(int data){
    Node *newNode;
    if(data==-1)
        return NULL;
    newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
}

Node *createTree(binTree *btptr){
    int data;
    Node *newNode,*cur;
    Q auxq;
    initQ(&auxq);

    printf("Enter Node data(-1 to END)\n");
    scanf("%d",&data);
    newNode = createNode(data);
    enqueue(&auxq,newNode);
    btptr->root = newNode;

    while(auxq.front != -1){
        cur = dequeue(&auxq);
        printf("\n Enter the left child Node value for %d: ",cur->data);
        scanf("%d",&data);
        cur->lchild = createNode(data);
        if(cur->lchild != NULL)
            enqueue(&auxq,cur->lchild);

        printf("\n Enter the right child Node value for %d: ",cur->data);
        scanf("%d",&data);
        cur->rchild = createNode(data);
        if(cur->rchild != NULL)
            enqueue(&auxq,cur->rchild);
    } 
}

void preorder(Node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void findMin(Node *root,int *min)
{
    // Using Preorder Traversals
    if(root == NULL)
        return;
    if(*min > root->data)
        *min = root->data;
    findMin(root->lchild,min);
    findMin(root->rchild,min);        
}

int main()
{
    binTree bt;
    initTree(&bt);
    createTree(&bt);
    printf("Preorder traversal: ");
    preorder(bt.root);
    int min = 1000;
    findMin(bt.root,&min);
    if(min != 1000)
        printf("Mininmum value: %d\n",min);
    printf("\nEND\n");
}
