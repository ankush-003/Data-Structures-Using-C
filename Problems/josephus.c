#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

typedef struct circularq  {
    int *arr;
    int front;
    int rear;
    int size;
}cq;

void initq(cq *qptr,int size)
{
    qptr->size = size;
    qptr->front = -1;
    qptr->rear = -1;
    qptr->arr = (int *) malloc(size * sizeof(int));
}

int isEmpty(cq *qptr)
{
    return (qptr->front == qptr->rear) && (qptr->front == -1);
}

int isFull(cq *qptr)
{
    if ((qptr->front == 0 && qptr->rear == qptr->size - 1)||(qptr->rear = qptr->front - 1))
        return 1;
    return 0;    
}

void enqueue(cq *qptr,int ele)
{
    if(isFull(qptr)) 
    {
        printf("Queue is Full!\n");
    }
    else
    {
        if(isEmpty(qptr))
        {
            qptr->front++;
            qptr->rear++;
        }
        else if(qptr->front == 0)
        {
            qptr->rear++;
        }
        else
        {
            qptr->rear = (qptr->rear + 1) % qptr->size;
        }
        qptr->arr[qptr->rear] = ele;
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
        int del = qptr->arr[qptr->front];
        if(qptr->front == qptr->rear)
        {

            qptr->rear = qptr->front = -1;
        }
        else
        {
            qptr->front = (qptr->front + 1) % qptr->size;
        }
        return del;
    }
}

int survivor(int n,int k)
{
    cq aux;
    initq(&aux,n);
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
        return 1;
    }
    else
    {
        int s = -1;
        for(int i=0;aux.front != aux.rear;i = (i + k)%n)
        {
            
        }
    }
}

int main()
{
    
    return 0;
}