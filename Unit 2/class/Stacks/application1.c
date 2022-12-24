#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char *stackElements;
    int top;
    int size;
}Stack;

void init(Stack *s,int size)
{
    s->size = size;
    s->stackElements = (char *) malloc(size * sizeof(char));
    s->top = -1;
}

void push(Stack *s,char ele)
{
    if(isStackOverFlow(s))
    {
        printf("Stack overflowed!\n");
    }
    else
    {
        s->stackElements[s->top] = ele;
        s->top++;
    }
}

void pop(Stack *s)
{
    if(isStackUnderFlow)
    {
        printf("Stack underflowed!\n");
    }
    else
    {
        printf("Deleted %c\n",s->stackElements[s->top]);
        free(s->stackElements[s->top]);
        s->top--;
    }
}

int isStackOverFlow(Stack *s)
{
    if(s->top > s->size)
        return 1;
    return 0;    
}

int isStackUnderFlow(Stack *s)
{
    if(s->top == -1)
        return 1;
    return 0;    
}

int match(char *expression, Stack *s)
{
    int len = strlen(expression);
    for(int i=0;i < len;i++)
    {
        
    }
}

int main()
{
    Stack s;
    int flag = 1;
    char expression[20];
    printf("Enter expression: ");
    scanf("%s",expression);
}

