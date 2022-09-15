// lower the value higher the priority
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

typedef struct node {
    int info;
    int priority;
}node;

typedef struct queue {
    node *qe;
    int qsize;
    int front,rear;
}Q;

void init(Q *qu,int size)
{
    qu->qsize = size;
    qu->front = -1;
    qu->rear = -1;
    qu->qe = (node *) malloc(size * sizeof(node));
}

int isFull(Q *qptr)
{
    return qptr->rear == qptr->qsize - 1;
}

int isEmpty(Q *qptr)
{
    return (qptr->rear == qptr->front )&&(qptr->rear == -1);
}

int peek(Q *qptr,int prio)
{
    int pos = -1;
    for(pos=qptr->front;((qptr->qe[pos]).priority <= prio)&&(pos<=qptr->rear);pos++);
    return pos;
}

void enqueue(Q *qptr,int info,int priority)
{
    node ele;
    ele.info = info;
    ele.priority = priority;
    if(isFull(qptr))
    {
        printf("Queue is full!\n");
    }
    else if (qptr->front ==-1)
    {
        qptr->front++;
        qptr->rear++;
        qptr->qe[qptr->rear] = ele;
    }
    else
    {
        int i;
        int pos = peek(qptr,priority);
        for(i = pos;(i<=(qptr->rear));i++)
        {
            qptr->qe[i+1] = qptr->qe[i];
        }
        qptr->qe[pos] = ele;
        qptr->rear++;
    }  
}

node dequeue(Q *qptr)
{
    node temp;
    temp.info = -1;
    temp.priority = -1;
    if(isEmpty(qptr))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        temp = qptr->qe[qptr->front];
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
    return temp;
}

void display(Q *qptr)
{
    if(isEmpty(qptr))
    {
        printf("Queue is Empty!\n");
    }
    else{
        printf("Elements of queue are:\n\t|info priority|\n");
        for (int i = qptr->front; i <= qptr->rear; i++)
        {
            printf("\t| %d %d|\n",qptr->qe[i].info,qptr->qe[i].priority);
        } 
    }
}

int main()
{
    Q pq;
    printf("Enter size: ");
    int size;
    scanf("%d",&size);
    init(&pq,size);
    int choice,info,priority;
    node ele;
    do
    {
        printf("Menu:\n1.) Enqueue\n2.) Dequeue\n3.) Display queue\n4.) Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter element info and priority: ");
            scanf("%d%d",&info,&priority);
            enqueue(&pq,info,priority);
            break;
        
        case 2:
            ele = dequeue(&pq);
            printf("Dequeued element with info:%d priority:%d\n",ele.info,ele.priority);
            break;

        case 3:
            display(&pq);
            break;        
            
        default:
            exit(0);
        }
    } while (choice < 5);
    return 0;
}