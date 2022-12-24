#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

typedef struct node {
    int info;
    struct node *next;
}node;

typedef struct stack {
    node *top;
}stack;

void initStack(stack *sptr)
{
    sptr->top = NULL;
}

int isStackEmpty(stack *sptr)
{
    return sptr->top == NULL;
}

void push(stack *sptr,int ele)
{
    //No Overflow Condition as we are using linked list
    node *temp = (node *) malloc(sizeof(node));
    temp->info = ele;
    temp->next = NULL;
    if(isStackEmpty(sptr))
    {
        sptr->top = temp;
    }
    else
    {
        temp->next = sptr->top;
        sptr->top = temp;
    }
}

int pop(stack *sptr)
{
    if(isStackEmpty(sptr))
    {
        return -1;
    }
    else
    {
        int del = -1;
        if(sptr->top->next == NULL)
        {
            del = sptr->top->info;
            free(sptr->top);
            sptr->top = NULL;
        }   
        else
        {
            node *temp = sptr->top;
            sptr->top = sptr->top->next;
            del = temp->info;
            free(temp);
        }
        return del; 
    }
}

int peek(stack *sptr)
{
    if(isStackEmpty(sptr))
    {
        // printf("current top element: %d\n",s->arr[s->top]);
        return -1;
    }
    else
    {
        return sptr->top->info;
    }
}

// queueWithStack
void enqueue(stack *qptr,int ele)
{
    if(isStackEmpty(qptr))
    {
        push(qptr,ele);
    }
    else
    {
        stack aux;
        initStack(&aux);
        while(!isStackEmpty(qptr))
        {
            push(&aux,pop(qptr));
        }
        push(qptr,ele);
        while (!isStackEmpty(&aux))
        {
            push(qptr,pop(&aux));
        }
    }
}

int deque

int main()
{
    // Code
    return 0;
}