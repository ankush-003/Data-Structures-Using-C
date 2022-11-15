#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#define MAX 100

struct treeNode {
    int data;
    int used;
};
typedef struct treeNode node;

void initTree(node *tree) {
    int i;
    for (i = 0; i < MAX; i++) {
        tree[i].data = 0;
        tree[i].used = 0;
    }
}

// iterative approach
void createBST1(node *tree, int data) {
    int i = 0;
    while (tree[i].used && i < MAX) {
        if (data < tree[i].data) {
            i = 2 * i + 1;
        } else {
            i = 2 * i + 2;
        }
    }
    if( i > MAX) {
        printf("Tree is full!\n");
        return;
    }
    tree[i].data = data;
    tree[i].used = 1;
}

// recursive approach
void createBST2(node *tree, int data, int i) {
    if( i > MAX) {
        printf("Tree is full!\n");
        return;
    }
    else {
        if (tree[i].used) {
            if (data < tree[i].data) {
                createBST2(tree, data, 2 * i + 1);
            } else if (data > tree[i].data) {
                createBST2(tree, data, 2 * i + 2);
            } else {
                printf("Duplicate data not allowed\n");
            }
        } else {
            tree[i].data = data;
            tree[i].used = 1;
        }
    }
}

void inorder(node *tree, int i) {
    if (tree[i].used && i < MAX) {
        inorder(tree, 2 * i + 1);
        printf("%d ", tree[i].data);
        inorder(tree, 2 * i + 2);
    }
}

void preorder(node *tree, int i) {
    if (tree[i].used && i < MAX) {
        printf("%d ", tree[i].data);
        preorder(tree, 2 * i + 1);
        preorder(tree, 2 * i + 2);
    }
}

void postorder(node *tree, int i) {
    if (tree[i].used && i < MAX) {
        postorder(tree, 2 * i + 1);
        postorder(tree, 2 * i + 2);
        printf("%d ", tree[i].data);
    }
}

int main()
{
    node tree[MAX];
    initTree(tree);
    printf("Enter size of tree: ");
    int size;
    scanf("%d", &size);
    int i;
    for (i = 0; i < size; i++) {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        // createBST1(tree, data);
        createBST2(tree, data, 0);
    }
    printf("Inorder: ");
    inorder(tree, 0);
    printf("Postorder: ");
    postorder(tree, 0);
    printf("Preorder: ");
    preorder(tree, 0);
    return 0;
}