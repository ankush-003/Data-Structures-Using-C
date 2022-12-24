// IMP: i = (i+1)%qsize
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct circularQueue
{
    int *qe;
    int qsize;
    int front, rear;
} CQ;

void init(CQ *qptr, int size)
{
    qptr->qsize = size;
    qptr->front = -1;
    qptr->rear = -1;
    qptr->qe = (int *)malloc(size * sizeof(int));
}

int isFull(CQ *qptr)
{
    if ((qptr->front == 0) && (qptr->rear == qptr->qsize - 1))
        return 1;
    else if (qptr->rear == qptr->front - 1)
        return 1;
    return 0;
}

int isEmpty(CQ *qptr)
{
    return (qptr->front == qptr->rear) && (qptr->rear == -1);
}

void enqueue(CQ *qptr, int ele)
{
    if (isFull(qptr))
    {
        printf("Circular Queue is full!\n");
    }
    else
    {
        if (isEmpty(qptr))
        {
            qptr->rear++;
            qptr->front++;
        }
        else if (qptr->front == 0)
        {
            qptr->rear++;
        }
        else
        {
            qptr->rear = (qptr->rear + 1) % qptr->qsize;
        }
        qptr->qe[qptr->rear] = ele;
    }
}

int dequeue(CQ *qptr)
{
    if (isEmpty(qptr))
    {
        printf("Queue is Empty!\n");
        return -1;
    }
    else
    {
        int de = qptr->qe[qptr->front];
        qptr->front = (qptr->front + 1) % qptr->qsize;
        return de;
    }
}

int display(CQ *qptr)
{
    if (isEmpty(qptr))
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Elements of the circular queue are:\n");
        for (int i = qptr->front; i != qptr->rear; i = (i + 1) % qptr->qsize)
        {
            printf("\t| %d |\n", qptr->qe[i]);
        }
        printf("\t| %d |\n", qptr->qe[qptr->rear]);
    }
}

int main()
{
    CQ queue;
    int size;
    printf("Enter queue size: ");
    scanf("%d", &size);
    init(&queue, size);
    int choice, ele;
    printf("Welcome to Circular Queue!!!\n");
    do
    {
        printf("Menu:\n1.) Enqueue\n2.) Dequeue\n3.) Display queue\n4.) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &ele);
            enqueue(&queue, ele);
            break;

        case 2:
            ele = dequeue(&queue);
            if (ele != -1)
                printf("Dequeued element %d\n", ele);
            break;

        case 3:
            display(&queue);
            break;

        default:
            exit(0);
        }
    } while (choice < 5);
    return 0;
}