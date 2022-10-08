/*
Parent at index i:(root node at index 0)
    left child at index 2*i + 1 (2*i if root at index 1)
    Right child at index 2*i + 2 (2*i + 1 id root at index 1)

used field to determine whether the array element is a part of tree or not    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#define MAX 50

struct treeArrayNode {
    int info;
    int used;
};
typedef struct treeArrayNode Node;

void initBst(Node *bst) {
    for(int i = 0;i < MAX;i++) {
        bst[i].used = 0;
    }
}

void createBst(Node *bst,int data,int i) {
    if(i > MAX - 1) {
        printf("BST is FULL!\n");
        return;
    }
    if (!bst[i].used) {// Unused Array Element
        bst[i].info = data;
        bst[i].used++;
    }
    else {
        if(data < bst[i].info) {
            createBst(bst,data,2*i + 1);
        }
        else if (data > bst[i].info) {
            createBst(bst,data,2*i + 2);
        }
        else {
            printf("Duplicate Element!\n");
            return;
        }
    }
}

void inOrder(Node *bst,int i) {
    if(!bst[i].used || i > MAX - 1) {
        return;
    }
    inOrder(bst,2*i + 1);
    printf("%d ",bst[i].info);
    inOrder(bst,2*i + 2);
}

int main(void)
{
    Node bstArray[MAX];
    initBst(bstArray);
    int data;
    do {
        printf("Enter data: ");
        scanf("%d",&data);
        if(data != -1)
            createBst(bstArray,data,0);
    }while(data != -1);

    inOrder(bstArray,0);

    printf("\nbstArray: (till 10 elements):\n");
    for (int i = 0; i < 10; i++)
    {
        printf("info:%d, used:%d ",bstArray[i].info,bstArray[i].used);
    }
    printf("\n");
    return 0;
}