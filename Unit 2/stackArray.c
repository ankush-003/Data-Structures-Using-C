#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int *arr;
    int top;
    int capacity;
}Stack;

void createStack(Stack *s,int capacity)
{
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int *) malloc(capacity * sizeof(int));
}

int isStackOverFlow(Stack *s)
{
    return s->capacity == s->top + 1;
}

int isStackUnderFlow(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s,int ele)
{
    if(!isStackOverFlow(s))
    {
        s->arr[++(s->top)] = ele;
        printf("%d pushed to stack!\n",s->arr[(s->top)]);
    }
    else
    {
        printf("Stack Overflowed!\n");
    }
}

int pop(Stack *s)
{
    if(!isStackUnderFlow(s))
    {
        return s->arr[s->top--];
    }
    return -1;
}

int peek(Stack *s)
{
    if(!isStackUnderFlow(s))
    {
        // printf("current top element: %d\n",s->arr[s->top]);
        return s->arr[s->top];
    }
    else
    {
        printf("No elements to peep!\n");
        return -1;
    }
}

void displayStack(Stack *s)
{
    int i = s->top;
    printf("Elements of stack are:\n");
    while(i>=0)
    {
        printf("%d\n",s->arr[i--]);
    }
    // printf("--x--x--x--\n");
}

int main()
{
    Stack s;
    int size;
    printf("Enter Stack Capacity: ");
    scanf("%d",&size);
    createStack(&s,size);
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

