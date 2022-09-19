#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

typedef struct node {
    int info;
    struct node *next;
}node;

typedef struct linearQ
{
    node *front;
    node *rear;
}Q;

void initQ(Q *qptr)
{
    qptr->front = qptr->rear = NULL;
}

int isEmpty(Q *qptr)
{
    return (qptr->front == qptr->rear)&&(qptr->front == NULL);
}

void enqueue(Q *qptr,int ele)
{
    node *temp = (node *) malloc(sizeof(node));
    temp->info = ele;
    temp->next = NULL;
    if(isEmpty(qptr))
    {
        qptr->front = temp;
        qptr->rear = temp;
    }
    else
    {
        qptr->rear->next = temp;
        qptr->rear = temp; 
    }
}

int dequeue(Q *qptr)
{
    if(isEmpty(qptr))
        return -1;
    else
    {
        node *temp = qptr->front;
        int del = temp->info;
        if(qptr->front == qptr->rear)
        {
            qptr->front = qptr->rear = NULL;
        }
        else
        {
            qptr->front = qptr->front->next;
        }
        free(temp);
        temp = NULL;
        return del;
    }    
}

void display(Q *qptr)
{
    if(isEmpty(qptr))
        printf("Queue is Empty!\n");
    else
    {
        node *temp = qptr->front;
        printf("Elements of Queue are:\n");
        while(temp)
        {
            printf("%d ->",temp->info);
            temp = temp->next;
        }
        printf("\b\b\n");
    }    
}

int main()
{
    Q queue;
    initQ(&queue);
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