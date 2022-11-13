#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
    int data;
    struct node *next;
} node;
typedef struct node node;

node *createNode(int data) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(node **head, int data) {
    node *newNode = createNode(data);
    node *current = *head;
    node *previous = NULL;

    if(*head == NULL) {
        *head = newNode;
        return; 
    }

    while(current != NULL && current->data < data) {
        previous = current;
        current = current->next;
    }

    if(previous == NULL) {
        *head = newNode;
        newNode->next = current;
    } else {
        previous->next = newNode;
        newNode->next = current;
    }
}

void delete(node **head,int data) {
    if(*head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    node *current = *head;
    node * previous = NULL;
    while(current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if(current == NULL) {
        printf("Data not found!\n");
        return;
    }

    if(previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    printf("deleted node with data = %d\n",current->data);
    free(current);
}

void createOrderedList(node **head) {
    int data,n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(head, data);
    }
}

void reverseList(node **head) {
    node *current = *head;
    node *previous = NULL;
    node *next = NULL;

    if(*head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    while(current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
}

void displayList(node **head) {
    if(*head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    node *current = *head;
    while(current) {
        printf("%d-> ", current->data);
        current = current->next;
    }
    printf("NUll\n");
}

int main()
{
    node *head = NULL;
    createOrderedList(&head);
    displayList(&head);
    reverseList(&head);
    displayList(&head);
    return 0;
}