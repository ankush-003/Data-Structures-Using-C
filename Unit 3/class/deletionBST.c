/* Deletion of a Node in BST
-> Leaf node
-> Node has 1 child
-> Node has 2 child

example:
            60
            / \
         40    80
        / \      \
      30   50     100
       \          /
       35        90
                 / \
                85 95
*/


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
        return root;
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
        return NULL;
    }
    return root;
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

void inOrder(Node *root)
{
    if(root == NULL)
        return;
    inOrder(root->lchild);
    printf("%d ",root->key);
    inOrder(root->rchild);
}

// Node *inorderSuccessor(Node *troot) {
//     if(troot == NULL) {
//         return 
//     }
// }

Node *deleteNode(Node *troot,int ele)
{
    Node *temp = NULL;
    if(troot == NULL)
    {
        // Takes care of data not found also
        return NULL;
    }
    if(ele < troot->key) {
        troot->lchild = deleteNode(troot->lchild,ele);
    }
    else if(ele > troot->key) {
        troot->rchild = deleteNode(troot->rchild,ele);
    }
    else {
        if(troot->lchild == NULL) {
            temp = troot->rchild;
            free(troot);
            return temp;
        }
        else if(troot->rchild == NULL) {
            temp = troot->lchild;
            free(troot);
            return temp;
        }
        else {
            // Using inorderSuccessor method:
            troot->key = findMin(troot->rchild);
            troot->rchild = deleteNode(troot->rchild,troot->key);
        }
    }
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
    printf("\nInorder Traversal: ");
    inOrder(bstree.troot);
    int delNode = -1;
    printf("\nEnter Node value to delete: ");
    scanf("%d",&delNode);
    deleteNode(bstree.troot,delNode);
    printf("\nInorder Traversal: ");
    inOrder(bstree.troot);
    return 0;
}