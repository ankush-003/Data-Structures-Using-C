#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#define SIZE 7

typedef struct node {
    int rNo;
    char name[20];
    int mark; // 
}Node;

void initTable(Node *ht, int *n) {
    for(int i = 0; i < SIZE; i++) {
        ht[i].mark = -1;
    }
    *n = 0;
}

int insert(Node *ht, int rNo, char *name, int *n) {
    if(*n == SIZE) return 0;

    int index = rNo % SIZE;
    while(ht[index].mark != -1) {
        index = (index + 1) % SIZE;
    }
    ht[index].rNo = rNo;
    strcpy(ht[index].name,name);
    ht[index].mark = 1;
    (*n)++;
    return 1;
}

int delete(Node *ht, int rNo, int *n) {
    if(*n == 0) return 0;
    int index = rNo % SIZE;
    
    int count = 0;
    while(ht[index].rNo != rNo && count < (*n) && ht[index].mark != -1) {
        index = (index + 1) % SIZE;
        if(ht[index].mark == 1) {
            count++;
        }
    }
    if(ht[index].rNo == rNo && ht[index].mark == 1) {
        ht[index].mark = -1;
        (*n)--;
        return 1;
    }
    return 0;
}

int search(Node *ht, int rNo, char *name, int n) {
    if(n == 0) return 0;

    int index = rNo % SIZE;
    int count = 0;
    while(ht[index].rNo != rNo && count < n && ht[index].mark != -1) {
        index = (index + 1) % SIZE;
        if(ht[index].mark == 1) {
            count++;
        }
    }
    if(ht[index].rNo == rNo && ht[index].mark == 1) {
        strcpy(name, ht[index].name);
        return 1;
    }
    return 0;
}

void display(Node *ht) {
    for(int i = 0; i < SIZE; i++) {
        if(ht[i].mark == 1) {
            printf("index: %d name: %s mark: %d\n",i,ht[i].name,ht[i].mark);
        } else {
            printf("index: %d Not Filled!\n",i);
        }
    }
}

int main()
{
    Node ht[SIZE];
    int n;
    initTable(ht, &n);

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
                insert(ht, rNo, name, &n);
                break;
            case 2:
                printf("Enter the roll number:");
                scanf("%d", &rNo);
                if(delete(ht, rNo, &n)) {
                    printf("Deleted successfully!\n");
                }
                else {
                    printf("Not found!\n");
                }
                break;
            case 3:
                printf("Enter the roll number:");
                scanf("%d", &rNo);
                if(search(ht, rNo, name, n)) {
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
                exit(0);    
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}