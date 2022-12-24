#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

typedef struct qnode {
    int info;
    struct qnode *next;
}qnode;

typedef struct queue {
    qnode *front;
    qnode *rear;
}Q;

void initQ(Q *qptr) {
    qptr->front = NULL;
    qptr->rear = NULL;
}

int isEmpty(Q *qptr) {
    if((!qptr->front)&&(!qptr->rear))
        return 1;
    return 0;    
}

void enqueue(Q *qptr,int ele)
{
    qnode *newnode = (qnode *) malloc(sizeof(qnode));
    newnode->info=ele;
    newnode->next=NULL;

    if(isEmpty(qptr))
    {
        qptr->front = newnode;
        qptr->rear = newnode;
        newnode->next = qptr->front;
    }
    else
    {
        newnode->next = qptr->front;
        qptr->rear->next = newnode;
        qptr->rear = newnode;
    }
}

int dequeue(Q *qptr)
{
    int ele = -1;
    qnode *temp = NULL;
    if(isEmpty(qptr))
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        temp = qptr->front;
        if(qptr->front == qptr->rear)
        {
            ele = temp->info;
            free(temp);
            qptr->front = NULL;
            qptr->rear = NULL;
        }
        else
        {
            qptr->front = qptr->front->next;
            qptr->rear->next = qptr->front;
            ele = temp->info;
            free(temp);
        }
        temp = NULL;
    }
    return ele;
}

void displayQ(Q *qptr)
{
    if(isEmpty(qptr))
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        qnode *cur;
        cur = qptr->front;
        while(cur->next!=qptr->front)
        {
            printf("%d->",cur->info);
            cur = cur->next;
        }
        printf("%d\n",cur->info);
    }
}

int main()
{
    Q qu;
    int choice,ele;
    initQ(&qu);
    do
    {
        printf("Menu\n1.) Enqueue\n2.) Dequeue\n3.) Display\n4.) Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be Enqueued: ");
            scanf("%d",&ele);
            enqueue(&qu,ele);
            break;
        
        case 2:
            ele = dequeue(&qu);
            if(ele!=-1)
                printf("Node with %d dequeued\n",ele);
            break;

        case 3:
            displayQ(&qu);
            break;

        default:
            exit(0);
        }
    } while (choice < 5);
    return 0;
}