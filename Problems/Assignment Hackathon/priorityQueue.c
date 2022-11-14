#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

struct node {
    int data;
    int priority;
};
typedef struct node node;

struct priorityQueue {
    int front;
    int rear;
    int size;
    node *arr;
};
typedef struct priorityQueue pQ;

void initQ(pQ *q, int size) {
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->arr = (node *)malloc(sizeof(node) * size);
}

bool isEmpty(pQ *q) {
    return q->front == -1;
}

bool isFull(pQ *q) {
    return q->rear == q->size - 1;
}

int findPos(pQ *q, int priority) {
    int i;
    // lower the priority value higher the priority
    // there are two types of priority queues
    // 1. max priority queue
    // 2. min priority queue
    // here we are implementing min priority queue (or ascending order)
    for(i = q->front; i <= q->rear && q->arr[i].priority <= priority; i++);
    return i;
}

void enqueue(pQ *q, int data, int priority) {
    node ele;
    ele.data = data;
    ele.priority = priority;
    if(isFull(q)) {
        printf("Queue Overflowed\n");
        return;
    }
    if(isEmpty(q)) {
        q->front = q->rear = 0;
        q->arr[q->rear] = ele;
        return;
    }
    int pos = findPos(q, priority);
    for(int i = pos;i <= q->rear; i++) {
        q->arr[i+1] = q->arr[i];
    }    
    q->arr[pos] = ele;
    q->rear++;
}

node dequeue(pQ *q) {
    node temp;
    temp.data = -1;
    temp.priority = -1;
    if(isEmpty(q)) {
        printf("Queue Underflowed\n");
        return temp;
    }
    // delete the element at the front because it has the highest priority
    temp = q->arr[q->front];
    if(q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return temp;
}

int main()
{
    pQ q;
    initQ(&q, 5);
    do {
        int choice;
        printf("1. Enqueue 2. Dequeue 3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                int data, priority;
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                enqueue(&q, data, priority);
                break;
            }
            case 2: {
                node ele = dequeue(&q);
                printf("Dequeued element: %d\n", ele.data);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    } while(true);
    return 0;
}