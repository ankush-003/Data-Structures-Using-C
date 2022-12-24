#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

struct element {
    int data;
    int priority;    
};
typedef struct element element;

struct pq{
    int size;
    int capacity;
    element *array;
};
typedef struct pq pq;

void initPQ(pq *pq, int capacity)
{
    pq->size = 0;
    pq->capacity = capacity;
    pq->array = (element *)malloc(sizeof(element) * capacity);
}

void insert(pq *pq, int data, int priority) {
    if(pq->size == pq->capacity) {
        printf("Priority Queue is full\n");
        return;
    }
    element *newElement = (element *)malloc(sizeof(element));
    newElement->data = data;
    newElement->priority = priority;
    int i = pq->size-1;
    while(i >= 0 && pq->array[i].priority > priority) {
        pq->array[i+1] = pq->array[i];
        i--;
    }
    pq->array[i+1] = *newElement;
    pq->size++;
}

int delete(pq *pq) {
    if(pq->size == 0) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    int data = pq->array[0].data;
    for(int i = 0; i < pq->size-1; i++) {
        pq->array[i] = pq->array[i+1];
    }
    pq->size--;
    return data;
}

void display(pq *pq) {
    for(int i = 0; i < pq->size; i++) {
        printf("%d %d\n", pq->array[i].data, pq->array[i].priority);
    }
    printf("\n");
}

int main()
{
    pq *pq = (struct pq *)malloc(sizeof(struct pq));
    initPQ(pq, 5);
    insert(pq, 2, 2);
    insert(pq, 1, 1);
    insert(pq, 3, 3);
    insert(pq, 4, 4);
    insert(pq, 5, 5);
    display(pq);
    int deleted = delete(pq);
    printf("Deleted: %d \n", deleted);
    display(pq);
    return 0;
}