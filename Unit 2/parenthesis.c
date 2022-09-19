#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

typedef struct stack{
    char *arr;
    int top;
    int capacity;
}Stack;

void createStack(Stack *s,int capacity)
{
    s->capacity = capacity;
    s->top = -1;
    s->arr = (char *) malloc(capacity * sizeof(char));
}

int isStackOverFlow(Stack *s)
{
    return s->capacity == s->top + 1;
}

int isStackUnderFlow(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s,char ele)
{
    if(!isStackOverFlow(s))
    {
        s->arr[++(s->top)] = ele;
        //printf("%d pushed to stack!\n",s->arr[(s->top)]);
    }
    else
    {
        printf("Stack Overflowed!\n");
    }
}

char pop(Stack *s)
{
    if(!isStackUnderFlow(s))
    {
        return s->arr[s->top--];
    }
    return -1;
}

char peek(Stack *s)
{
    if(!isStackUnderFlow(s))
    {
        // printf("current top element: %d\n",s->arr[s->top]);
        return s->arr[s->top];
    }
    else
    {
        printf("No elements to peep!\n");
        return '\0';
    }
}

int isBracket(char e)
{
    switch (e)
    {
    case '(':
    case ')':
        return 1;
    case '[':
    case ']':
        return 2;        
    case '{':
    case '}':
        return 3;    
    default:
        return 0;
    }
}

int isBalanced(char *exp)
{
    Stack brackets;
    if(strlen(exp)==0)
        return -1;
    createStack(&brackets,strlen(exp));
    for(int i = 0; exp[i];i++)
    {
        if(isBracket(exp[i]))
        {
            if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
                push(&brackets,exp[i]);
            else
            {
                if(!isStackUnderFlow(&brackets))
                {
                    if(isBracket(exp[i]) == isBracket(peek(&brackets)))
                        pop(&brackets);
                }
                else 
                {
                    return 0;
                }
                
            }    
        }
    }
    if(isStackUnderFlow(&brackets))
        return 1;
    return 0;    
}

int main()
{
    char exp[50];
    printf("Enter expression to be checked: ");
    scanf("%s",exp);
    if(isBalanced(exp))
    {
        printf("Expression is balanced!\n");
    }
    else
    {
        printf("Expression is Not balanced!\n");
    }
    return 0;
}