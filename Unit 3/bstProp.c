#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

/* Properties:
-> Height of the tree
-> Number of nodes in the tree
-> Leaf count
-> Count of non-leaf Nodes
-> Traversal
-> Search for a key Value */

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

int heightBST(Node *root)
{
    if(root == NULL)
        return 0;

    int lh = heightBST(root->lchild);
    int rh = heightBST(root->rchild);

    return (lh>rh)?lh+1:rh+1;    
}

void reverseBST(Node *root)
{
    if(root == NULL)
        return;

    Node *temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;    
}

int leafCountBST(Node *troot)
{
    if(troot != NULL)
    {
        if(troot->lchild == NULL && troot->rchild == NULL)
            return 1;
        int l,r;
        l = leafCountBST(troot->lchild);
        r = leafCountBST(troot->rchild);
        return l+r;
    }
    return 0;
}

int nonLeafNode(Node *troot)
{
    if((troot == NULL)||(troot->lchild == NULL && troot->rchild == NULL))
        return 0;
    return (nonLeafNode(troot->lchild) + 1 + nonLeafNode(troot->rchild));    
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
    int leaf = leafCountBST(bstree.troot);
    printf("Number of leaf nodes: %d\n",leaf);
    int nleaf = nonLeafNode(bstree.troot);
    printf("Number of NonLeaf nodes: %d\n",nleaf);
    return 0;
}