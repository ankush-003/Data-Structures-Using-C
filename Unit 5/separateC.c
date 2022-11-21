#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#define SIZE 7

typedef struct element {
    int rNo;
    char name[30];
    struct element *next;
}Node;

void initTable(Node **ht);
void insert(Node **ht, int rNo, char *name);
int delete(Node **ht, int rNo);
int search(Node **ht, int rNo, char *name);
void display(Node **ht);
void destroy(Node **ht);

int main()
{
    Node *ht[SIZE];
    initTable(ht);

    int choice, rNo;
    char name[30];
    while(1) {
        printf(" 1. Insert 2. Delete 3. Search 4. Display 5. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the roll number:");
                scanf("%d", &rNo);
                printf("Enter the name:");
                scanf("%s", name);
                insert(ht, rNo, name);
                break;
            case 2:
                printf("Enter the roll number:");
                scanf("%d", &rNo);
                if(delete(ht, rNo)) {
                    printf("Deleted successfully!\n");
                }
                else {
                    printf("Not found!\n");
                }
                break;
            case 3:
                printf("Enter the roll number:");
                scanf("%d", &rNo);
                if(search(ht, rNo, name)) {
                    printf("Found %s\n", name);
                }
                else {
                    printf("Not found!\n");
                }
                break;
            case 4:
                display(ht);
                break;
            case 5:
                destroy(ht);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void initTable(Node **ht) {
    for(int i=0; i < SIZE; i++) {
        ht[i] = NULL;
    }
}

void insert(Node **ht, int rNo, char *name) {
    // insert front operation
    int index = rNo % SIZE;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->rNo = rNo;
    strcpy(newNode->name,name);
    newNode->next = ht[index];
    ht[index] = newNode;
}

int delete(Node **ht, int rNo) {
    int index = rNo % SIZE;
    Node *cur = ht[index];
    Node *prev = NULL;

    while(cur && cur->rNo != rNo) {
        prev = cur;
        cur = cur->next;
    }

    if(!cur) {
        printf("Element to be deleted not found!\n");
        return 0;
    }

    if(prev == NULL) { // first element
        ht[index] = cur->next;
    } else {
        prev = cur->next;
    }
    // int delrNo = cur->rNo;
    free(cur);
    return 1;
}

int search(Node **ht, int rNo, char *name) {
    int index = rNo % SIZE;
    Node *cur = ht[index];
    while(cur) {
        if(cur->rNo == rNo) {
            strcpy(name,cur->name);
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

void display(Node **ht) {
    Node *cur;
    for(int i = 0; i < SIZE; i++) {
        cur = ht[i];
        printf("h[%d]->",i);
        while(cur) {
            printf("%d %s->",cur->rNo,cur->name);
            cur = cur->next;
        }
        printf("NULL\n");
    }
}

void destroy(Node **ht) {
    Node *cur, *q= NULL;
    for(int i = 0; i < SIZE; i++) {
        cur = ht[i];
        while(cur) {
            q = cur;
            cur = cur->next;
            free(q);
        }
        ht[i] = NULL;
    }
}