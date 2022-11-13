#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

node *createNode(int data) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertFront(node **head,int data) {
    node *newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertRear(node **head, int data) {
    node *newNode = createNode(data);
    if(head == NULL) {
        *head = newNode;
    } else {
        node *cur = *head;
        while(cur->next !=NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
        newNode->prev = cur;
    }
}

void insertAt(node **head, int data, int pos) {
    node *newNode = createNode(data);
    if(*head == NULL) {
        printf("List is empty!\n");
        *head = newNode;
    } else {
        
    }
}


int main()
{
    return 0;
}