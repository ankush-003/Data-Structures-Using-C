#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

typedef struct node {
    int info;
    struct node *next;
}node;

typedef struct circularq  {
    node *front;
    node *rear;
}cq;

void initq(cq *qptr)
{
    qptr->front = NULL;
    qptr->rear = NULL;
}

int isEmpty(cq *qptr)
{
    return (qptr->front == qptr->rear) && (qptr->front == NULL);
}

void enqueue(cq *qptr,int ele)
{
    node *temp = (node *) malloc(sizeof(node));
    temp->info = ele;
    temp->next = temp;
    if(isEmpty(qptr))
    {
        qptr->front = temp;
        qptr->rear = temp;
    }
    else{
        temp->next = qptr->front;
        qptr->rear->next = temp;
        qptr->rear = temp;
    }
}

int dequeue(cq *qptr)
{
    if(isEmpty(qptr))
    {
        printf("Queue is Empty!\n");
        return -1;
    }
    else
    {
        node *temp = qptr->front;
        int del = temp->info;
        if(qptr->front == qptr->rear)
        {
            qptr->rear = qptr->front = NULL;
        }
        else
        {
            qptr->front = qptr->front->next;
            qptr->rear->next = qptr->front;
        }
        free(temp);
        return del;
    }
}

int survivor(int n,int k)
{
    cq aux;
    initq(&aux);
    for(int i = 1;i <= n;i++)
    {
        enqueue(&aux,i);
    }
    if(k > n)
    {
        return -1;
    }
    if(n == 1)
    {
        return dequeue(&aux);
    }
    else
    {
        while(aux.front != aux.rear)
        {
            for(int i = 1;i < k;i++)
            {
                enqueue(&aux,dequeue(&aux));
            }
            printf("killed position: %d\n",dequeue(&aux));
        }
        return dequeue(&aux);
    }
}

int main()
{
    int n,k;
    printf("Enter number of soldiers: ");
    scanf("%d",&n);
    printf("Enter k value: ");
    scanf("%d",&k);
    printf("Survivor is %d\n",survivor(n,k));
    return 0;
}