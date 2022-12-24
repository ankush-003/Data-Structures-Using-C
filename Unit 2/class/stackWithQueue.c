#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

struct queue {
    int *qe;
    int front;
    int rear;
    int qsize;
};
typedef struct queue stack;

void initQueue(stack *qptr,int size)
{
    qptr->front = qptr->rear = -1;
    qptr->qsize = size;
    qptr->qe = (int *) malloc(sizeof(int));
}

void initStack(stack *sptr,int size)
{
    initQueue(sptr,size);
}

int isFull(stack *sptr)
{
    if((sptr->front==0 && sptr->rear==sptr->qsize-1) || (sptr->rear == sptr->front - 1))
        return 1;
    return 0; 
}

int isEmpty(stack *sptr)
{
    return (sptr->rear == sptr->front) && (sptr->rear == -1);
}

void enqueue(stack *sptr,int ele)
{
    printf("Entered enqueue\n");
    if(sptr->front == -1)
        sptr->front++;
    sptr->rear = (sptr->rear + 1)%(sptr->qsize);
    sptr->qe[sptr->rear] = ele;
    printf("stack -> %d %d\n",sptr->front,sptr->rear);
}

int dequeue(stack *sptr)
{
    int ele = sptr->qe[(sptr->front)];
    //printf("front is %d\n",ele);
    if(sptr->front == sptr->rear)
    {
        sptr->front = -1;
        sptr->rear = -1;
    }
    else
    {
        sptr->front = (sptr->front + 1) % sptr->qsize;
    }
    return ele;
}

void display(stack *sptr)
{
    if (isEmpty(sptr))
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        printf("Elements of the stack are:\n");
        for (int i = sptr->front; i != sptr->rear; i = (i + 1) % sptr->qsize)
        {
            printf("\t| %d |\n", sptr->qe[i]);
        }
        printf("\t| %d |\n", sptr->qe[sptr->rear]);
    }
}

stack push(stack s,int ele)
{
    // copied s is also deleted after exitting function
    stack auxQ;
    initQueue(&auxQ,s.qsize);
    if(isFull(&s))
    {
        printf("Stack Overflowed!\n");
        return s;
    }
    enqueue(&auxQ,ele);
    if(isEmpty(&s))
    {
        return auxQ;
    }
    else
    {
        // printf("Entered loop\n");
        while(!isEmpty(&s))
        {
            //int ele = dequeue(&s);
            enqueue(&s,dequeue(&s));
            display(&s);
        }
        return auxQ;
    }
}

int pop(stack *sptr)
{
    int ele = -1;
    if(isEmpty(sptr))
    {
        printf("No elements to pop!\n");
    }
    else
    {
        ele = dequeue(sptr);
    }
    return ele;
}

int peek(stack *sptr)
{
    int ele = -1;
    if(isEmpty(sptr))
        printf("Stack is Empty!\n");
    else
    {
        ele = sptr->qe[sptr->front];
    }    
    return ele;
}


int main()
{
    int choice,ele;
    stack s;
    printf("Enter size of the stack: ");
    int size;
    scanf("%d",&size);
    initStack(&s,size);
    do
    {
        printf("Menu:\n1.) Push\n2.) Pop\n3.) Display\n4.) Peep\n5.) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &ele);
            s = push(s, ele);
            break;

        case 2:
            ele = pop(&s);
            if (ele == -1)
            {
                printf("Stack Underflowed\n");
            }
            else
            {
                printf("Popped element with %d\n", ele);
            }
            break;

        case 3:
            display(&s);
            break;

        case 4:
            ele = peek(&s);
            if(ele != -1)
                printf("Element %d is at top\n",ele);
            break;

        default:
            exit(0);
        }
    } while (choice < 6);
    return 0;
}