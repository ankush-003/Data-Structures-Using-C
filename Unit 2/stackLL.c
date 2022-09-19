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
    node *head;
    node *top;
}stack;

void initStack(stack *sptr)
{
    sptr->top = NULL;
    sptr->head = NULL;
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
        sptr->head = temp;
        sptr->top = temp;
    }
    else
    {
        sptr->top->next = temp;
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
        node *temp = sptr->head;
        while(temp->next != sptr->top)
            temp = temp->next;
        del = sptr->top->info;
        free(sptr->top);
        sptr->top = temp;   
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

void displayStack(stack *sptr)
{
    node *temp = sptr->head;
    printf("Elements of stack are:\n");
    while(temp != sptr->top)
    {
        printf("%d ->",temp->info);
        temp = temp->next;
    }
    printf("%d\n",temp->info);
}

int main()
{
    stack s;
    initStack(&s);
    int choice,ele;
    do
    {
        printf("Menu:\n1.) Push\n2.) Pop\n3.) Peek\n4.) Display\n5.) Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element to be pushed\n");
            scanf("%d",&ele);
            push(&s,ele);
            break;
        
        case 2:
            ele = pop(&s);
            if(ele != -1)
            {
                printf("Popped element %d\n",ele);
            }
            else
            {
                printf("Stack underflowed!\n");
            }
            break;

        case 3: 
            ele = peek(&s);
            if(ele != -1)
            {
                printf("element at top %d\n",ele);
            }
            else
            {
                printf("Stack is empty!\n");
            }
            break;

        case 4:
            displayStack(&s);
            break;

        default:
            exit(0);
        }
    } while (choice < 6);
    return 0;
}