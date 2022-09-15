// Double Ended queue with Linked List
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

typedef struct dequeue{
    node *front;
    node *rear;
}deQ;

void initdeQ(deQ *qptr);
int isEmpty(deQ *qptr);
void insertFront(deQ *qptr,int ele);
void insertRear(deQ *qptr,int ele);
int removeFront(deQ *qptr);
int removeRear(deQ *qptr);
int peekFront(deQ *qptr);
int peekRear(deQ *qptr);
void display(deQ *qptr);

int main()
{
    deQ q;
    initdeQ(&q);
    int choice,ele;
    do
    {
        printf("Menu:\n1) Insert Front\t2) Insert Rear\n3) Remove Front\t4) Remove Rear\n5) Peak Front\t6) Peak Rear\n7) Display\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d",&ele);
            insertFront(&q,ele);
            break;
        
        case 2:
            printf("Enter element to insert: ");
            scanf("%d",&ele);
            insertRear(&q,ele);
            break;

        case 3:
            ele = removeFront(&q);
            if(ele == -1)
                printf("Queue is Empty!\n");
            else
            {
                printf("Deleted node with info %d\n",ele);
            }
            break;

        case 4:
            ele = removeRear(&q);
            if(ele == -1)
                printf("Queue is Empty!\n");
            else
            {
                printf("Deleted node with info %d\n",ele);
            }
            break;
        
        case 5:
            ele = peekFront(&q);
            if(ele == -1)
                printf("Queue is Empty!\n");
            else
            {
                printf("Peeked at %d!\n",ele);
            }    
            break;

        case 6:
            ele = peekRear(&q);
            if(ele == -1)
                printf("Queue is Empty!\n");
            else
            {
                printf("Peeked at %d!\n",ele);
            }    
            break;

        case 7:
            display(&q);
            break;

        default:
            exit(0);
        }
    } while (choice < 9);
    
}

void initdeQ(deQ *qptr)
{
    qptr->front = NULL;
    qptr->rear = NULL;
}

int isEmpty(deQ *qptr)
{
    return (qptr->front == NULL) && (qptr->rear == NULL);
}

void insertFront(deQ *qptr,int ele)
{
    node *temp = (node *) malloc(sizeof(node));
    temp->info = ele;
    temp->next = NULL;
    if(isEmpty(qptr))
    {
        qptr->rear = qptr->front = temp;
    }
    else
    {
        temp->next = qptr->front;
        qptr->front = temp;
    }
}

void insertRear(deQ *qptr,int ele)
{
    node *temp = (node *) malloc(sizeof(node));
    temp->info = ele;
    temp->next = NULL;
    if(isEmpty(qptr))
    {
        qptr->rear = qptr->front = temp;
    }
    else
    {
        qptr->rear->next = temp;
        qptr->rear = temp;
    }
}

int removeFront(deQ *qptr)
{
    if(isEmpty(qptr))
    {
        printf("Queue is Empty!\n");
        return -1;
    }
    else
    {
        int ele = qptr->front->info;
        node *temp = qptr->front;
        if(qptr->front == qptr->rear)
        {
            qptr->front = qptr->rear = NULL;
        }
        else
        {
            qptr->front = temp->next;
        }
        free(temp);
        return ele;
    }
}

int removeRear(deQ *qptr)
{
    if(isEmpty(qptr))
    {
        printf("Queue is Empty!\n");
        return -1;
    }
    else
    {
        int ele = qptr->rear->info;
        node *temp = qptr->rear;
        if(qptr->front == qptr->rear)
        {
            qptr->front = qptr->rear = NULL;
        }
        else
        {
            node *prev = qptr->front;
            while(prev->next != qptr->rear)
                prev = prev->next;
            qptr->rear = prev;    
        }
        free(temp);
        return ele;
    }
}

int peekFront(deQ *qptr)
{
    if(isEmpty(qptr))
        return -1;
    return qptr->front->info;    
}

int peekRear(deQ *qptr)
{
    if(isEmpty(qptr))
        return -1;
    return qptr->rear->info;    
}

void display(deQ *qptr)
{
    if(isEmpty(qptr))
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        node *temp = qptr->front;
        printf("Elements of Queue are:\n");
        while(temp != qptr->rear)// or temp != NULL
        {
            printf("%d -> ",temp->info);
            temp = temp->next;
        }
        printf("%d\n",qptr->rear->info);
    }
}