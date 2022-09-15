#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int *qe;
    int qsize;
    int front,rear;
}Q;

void init(Q *qu,int size)
{
    qu->qsize = size;
    qu->front = -1;
    qu->rear = -1;
    qu->qe = (int *) malloc(size * sizeof(int));
}

int isFull(Q *qptr)
{
    return qptr->rear == qptr->qsize - 1;
}

int isEmpty(Q *qptr)
{
    return (qptr->rear == qptr->front )&&(qptr->rear == -1);
}

void enqueue(Q *qptr,int ele)
{
    if(isFull(qptr))
    {
        printf("Queue is full!\n");
    }
    else
    {
        if(isEmpty(qptr))
            qptr->front++;
        qptr->rear++;
        qptr->qe[qptr->rear] = ele; 
    }   
}

int dequeue(Q *qptr)
{
    int ele = -1;
    if(isEmpty(qptr))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        ele = qptr->qe[qptr->front];
        if(qptr->front == qptr->rear)
        {
            qptr->front = -1;
            qptr->rear = -1;
        }
        else
        {
            qptr->front++;
        }
    }
    return ele;
}

void display(Q *qptr)
{
    if(isEmpty(qptr))
    {
        printf("Queue is Empty!\n");
    }
    else{
        printf("Elements of queue are:\n");
        for (int i = qptr->front; i <= qptr->rear; i++)
        {
            printf("\t| %d |\n",qptr->qe[i]);
        } 
    }
}

int main()
{
    Q queue;
    int size;
    printf("Enter queue size: ");
    scanf("%d",&size);
    init(&queue,size);
    int choice,ele;
    do
    {
        printf("Menu:\n1.) Enqueue\n2.) Dequeue\n3.) Display queue\n4.) Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d",&ele);
            enqueue(&queue,ele);
            break;
        
        case 2:
            ele = dequeue(&queue);
            if (ele != -1)
                printf("Dequeued element %d\n",ele);
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