// Using separate chaining to resolve collisions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#define MAX 10

struct record {
    int key;
    float info;
    struct record *next;
};
typedef struct record Record;

int hashFunc(int dataKey) {
    return dataKey % MAX;
}

void insert(Record **hashTable) {
    int dataKey;
    float dataInfo;
    printf("\n Enter key and Info: ");
    scanf("%d %f",&dataKey,&dataInfo);
    int index = hashFunc(dataKey);
    Record *newNode;
    newNode = (Record *) malloc(sizeof(Record));
    newNode->key = dataKey;
    newNode->info = dataInfo;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void search(Record **hashTable,int key) {
    int index = hashFunc(key);
    Record *current = hashTable[index];
    if(!current) {
        printf("\n Record Not Found!\n");
        return;
    }
    while(current) {
        if(current->key == key) {
            printf("\n Record Found: %d %f\n",current->key,current->info);
            return;
        }
        current = current->next;
    }
    printf("\n Record Not Found!\n");
}

void display(Record **hashTable) {
    Record *current = NULL;
    for(int i = 0;i < MAX;i++) {
        current = hashTable[i];
        printf("\n");
        while(current) {
            printf("%d %f->",current->key,current->info);
            current = current->next;
        }
        printf("Null\n");
    }
}

void delete(Record **hashTable,int key) {
    int index = hashFunc(key);
    Record *current = hashTable[index];
    if(!current) {
        printf("\n Record Not Found!\n");
        return;
    }
    Record *prev = current;
    while(current) {
        if(current->key == key) {
            printf("\n Record Found: %d %f\n",current->key,current->info);
            if(current == hashTable[index]) {
                hashTable[index] = current->next;
                free(current);
                return;
            }
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("\n Record Not Found!\n");
}

int main()
{
    Record *hashTable[MAX];
    int choice, key, i;
    for(i = 0;i < MAX;i++) {
        hashTable[i] = NULL;
    }

    while(1) {
        printf("Hash Table Operations\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                insert(hashTable);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                search(hashTable, key);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                delete(hashTable, key);
                break;
            case 4:
                display(hashTable);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}