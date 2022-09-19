#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct stack
{
    // we can't initialise top to -1 as memory is not allocated in declaration
    int *stackelements;
    int top;
    int capacity;
};
typedef struct stack Stack;

void initStack(Stack *S, int stackSize);
void push(Stack *S, int ele);
int pop(Stack *S);
void display(Stack *S);
void peep(Stack *S);
int isFullStack(Stack S);
int isEmptyStack(Stack *S);

int main()
{
    Stack S;
    int stackSize;
    printf("Enter the stack size: ");
    scanf("%d", &stackSize);
    initStack(&S, stackSize);
    int choice, ele;
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
            push(&S, ele);
            break;

        case 2:
            ele = pop(&S);
            if (ele = -1)
            {
                printf("Stack Underflowed\n");
            }
            else
            {
                printf("Popped element with %d\n", ele);
            }

            break;

        case 3:
            display(&S);
            break;

        case 4:
            peep(&S);
            break;

        default:
            exit(0);
        }
    } while (choice < 6);
    return 0;
}

void initStack(Stack *S, int stackSize)
{
    S->stackelements = (int *)malloc(stackSize * sizeof(int));
    S->top = -1;
    S->capacity = stackSize;
}

void push(Stack *S, int ele)
{
    if (isFullStack(*S))
    {
        printf("\n Stack overflow, Could not push %d", ele);
    }
    else
    {
        S->top++;
        S->stackelements[S->top] = ele;
        printf("Pushed Element %d\n", ele);
    }
}

int isFullStack(Stack S)
{
    if (S.top == MAX - 1)
    {
        return 1;
    }
    return 0;
}

int isEmptyStack(Stack *S)
{
    return S->top == -1;
}

int pop(Stack *S)
{
    int ele = -1;
    if (!isEmptyStack(S))
    {
        ele = S->stackelements[S->top];
        S->top--;
    }
    return ele;
}

void display(Stack *S)
{
    if (isEmptyStack(S))
        printf("Empty Stack!\n");
    else{
        printf("Enter no elements!\n");
        for(int i = S->top;i>=0;i--)
        {
            printf("|\t%d\t|\n",S->stackelements[i]);
        }
    }    
}