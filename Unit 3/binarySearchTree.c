#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

struct node {
    int key;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node Node;

struct bst {
    Node *troot;
};
typedef struct bst BST;

void init(BST *bstptr)
{
    bstptr->troot = NULL;
}

Node *createNode(int data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->key = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

Node *insert(Node *root,int data)
{
    if(root == NULL) {
        root = createNode(data);
    }
    if(data < root->key)
    {
        root->lchild = insert(root->lchild,data);
    }
    else if(data > root->key) 
    {
        root->rchild = insert(root->rchild,data);
    }
    else
    {
        printf("\nData is Duplicate!\n");
    }
    return root;
}

void preOrder(Node *root)
{
    if(root == NULL)
        return;
    printf("%d ",root->key);
    preOrder(root->lchild);
    preOrder(root->rchild);    
}

void inOrder(Node *root)
{
    if(root == NULL)
        return;
    preOrder(root->lchild);
    printf("%d ",root->key);
    preOrder(root->rchild);
}

int findMin(Node *root)
{
    if(root == NULL)
    {
        printf("Empty BST!\n");
        return -1;
    }
    Node *cur = root;
    while(cur->lchild != NULL)
    {
        cur = cur->lchild;
    }
    return cur->key;
}

int findMax(Node *root)
{
    if(root == NULL)
    {
        printf("Empty BST!\n");
        return -1;
    }
    Node *cur = root;
    while(cur->rchild != NULL)
    {
        cur = cur->rchild;
    }
    return cur->key;
}

void leafCount(Node *root,int *leaf)
{
    if(root == NULL)
        return;
        
}

int main()
{
    int data;
    BST bstree;
    int flag = 1;
    init(&bstree);
    while(flag) {
        printf("\nEnter the node key value (-1 to stop): ");
        scanf("%d",&data);
        if(data == -1)
            flag = 0;
        else
        {
            if(bstree.troot == NULL)
            {
                bstree.troot = insert(bstree.troot,data);
            }
            else
                insert(bstree.troot,data);
        }    
    }
    printf("\nPreorder Traversal: ");
    preOrder(bstree.troot);
    printf("\nInorder Traversal: ");
    inOrder(bstree.troot);

    printf("Minimum Value: %d\n",findMin(bstree.troot));
    printf("Maximum Value: %d\n",findMax(bstree.troot));

    int leaf =  0;
    leafCount(bstree.troot,&leaf); 
    return 0;
}