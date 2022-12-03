#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
    int data;
    struct node *next;
}node;

node *createNode(int data) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFront(node **head, int ele) {
    node *newNode = createNode(ele);
    if(!(*head)) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

void insertRear(node **head, int ele) {
    node *newNode = createNode(ele);
    node *current = *head;
    if(!(*head)) {
        *head = newNode;
    } else {
        while(current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertAtPos(node **head, int ele, int pos) {
    if(pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    if(*head == NULL || pos == 1) {
        insertFront(head, ele);
    } else {
        node *newNode = createNode(ele);
        node *current = *head;
        for(int i = 1; i < pos-1;i++) {
            current = current->next;
            if(current == NULL) {
                printf("Invalid position!\n");
                return;
            }
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void display(node *head) {
    node *current = head;
    while(current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("Null\n");
}

void deleteFront(node **head) {
    if(!(*head)) {
        printf("List is empty!\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void deleteAtPos(node **head, int pos) {
    if(pos < 1) {
        printf("Invalid Position!\n");
        return;
    }
    if(*head == NULL) {
        printf("List is Empty!\n");
        return;
    }
    if(pos == 1) {
        deleteFront(head);
    } else {
        node *current = *head;
        for(int i = 1; i < pos-1; i++) {
            current = current->next;
            if(current == NULL) {
                printf("Invalid Position!\n");
                return;
            }
        }
        node *temp = current->next;
        current->next = temp->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

int isSorted(node *head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return -1;
    }
    if(head->next == NULL) {
        printf("List is sorted!\n");
        return 1;
    }
    node *current = head;
    if(head->data > head->next->data) {
        printf("List is not sorted!\n");
        return 0;
    }
    isSorted(head->next);
}

int main()
{
    node *head = NULL;
    // insertFront(&head, 1);
    // insertFront(&head, 2);
    // insertFront(&head, 3);
    // insertFront(&head, 4);
    // insertFront(&head, 5);
    // insertRear(&head, 6);
    // insertAtPos(&head, 7, 1);
    // display(head);
    // deleteFront(&head);
    // display(head);
    // deleteAtPos(&head, 3);
    // display(head);
    // deleteAtPos(&head, 1);
    // display(head);
    insertRear(&head, 1);
    insertRear(&head, 2);
    insertRear(&head, 3);
    insertRear(&head, 4);
    insertRear(&head, 5);
    display(head);
    isSorted(head);
    insertAtPos(&head, 2, 1);
    display(head);
    isSorted(head);
    return 0;
}