#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

node *createNode(int data) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(node **head, int data) {
    // creating circular linked list
    node *newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        node *cur = *head;
        while(cur->next != *head) {
            cur = cur->next;
        }
        cur->next = newNode;
        newNode->next = *head;
    }
}

void display(node *head) {
    node *cur = head;
    while(cur->next != head) {
        printf("%d ->",cur->data);
        cur = cur->next;
    }
    printf("%d ->\n",cur->data);
}

node *search(node *head, int data) {
    node *cur = head;
    if(cur == NULL) {
        printf("List is Empty!\n");
        return NULL;
    }

    while(cur->next != head) {
        if(cur->data == data) {
            return cur;
        }
        cur = cur->next;
    }
    if(cur->data == data) {
        return cur;
    }
    return NULL;
}

int survivor(node **head, int start, int k) {
    // node *cur = *head;
    // while(cur->data != start) {
    //     cur = cur->next;
    // }
    node *cur = search(*head,start);
    if(cur == NULL) {
        printf("Start node not found!\n");
        return -1;
    }
    node *prev = NULL;
    while(cur->next != cur) {
        for(int i = 1; i < k; i++) {
            prev = cur;
            cur = cur->next;
        }
        if(prev == NULL) {
            prev = cur->next;
            while(prev->next != cur) {
                prev = prev->next;
            }
        }
        prev->next = cur->next;
        printf("Killed %d\n",cur->data);
        free(cur);
        cur = prev->next;
    }
    return cur->data;
}

int main()
{
    node *head = NULL;
    printf("Enter the number of people: ");
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        insert(&head,i);
    }
    display(head);
    printf("Enter the value of k: ");
    int k;
    scanf("%d",&k);
    printf("The survivor is: %d\n",survivor(&head,1,k));
    return 0;
}