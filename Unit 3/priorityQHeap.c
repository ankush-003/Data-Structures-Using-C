#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#define MAX 100

typedef struct pq {
    int arr[MAX];
    int n;
} pq;

void initPQ(pq *q)
{
    q->n = 0;
}

void disp(pq *q)
{
    int i;
    for(i=0;i<q->n;i++)
        printf("%d ",q->arr[i]);
}

void enqueue(pq *q, int ele) {
    // shift up
    if(q->n == MAX) {
        printf("Queue is full");
        return;
    }
    q->arr[q->n] = ele;
    int child = (q->n);
    int parent = (child-1)/2;
    while(child > 0 && q->arr[parent] < q->arr[child]) {
        q->arr[child] = q->arr[parent];
        child = parent;
        parent = (child-1)/2;
    }
    q->arr[child] = ele;
    q->n++;
}

int dequeue(pq *q, int *ele) {
    if(q->n == 0) {
        return 0;
    }
    int parent = 0;
    *ele = q->arr[0];
    int temp = q->arr[q->n-1];
    if(q->n == 1) {
        q->n--;
        return 1;
    }
    int child = 1;
    while(child > 0 && temp < q->arr[child]) {
        q->arr[parent] = q->arr[child];
        parent = child;
        child = 2*parent + 1;
        if(child + 1 < q->n - 1 && q->arr[child+1] > q->arr[child]) {
            child++;
        }
        if(child >= q->n - 1) {
            child = -1;
        }
    }
    q->arr[parent] = temp;
}

int main()
{
    pq q;
    initPQ(&q);
    int k,choice,ele;

    do{
        printf("1. Enqueue 2 Dequeue 3 Display\n");
        printf("Enter the choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter the information");
                scanf("%d",&ele);
                enqueue(&q,ele);
                break;
            case 2: k=dequeue(&q,&ele);
                if(!k) printf("empty");
                else
                    printf("%d dequeued element",ele);
                break;
            case 3: disp(&q);
                break;
        }
    }while(choice<4);
    return 0;
}