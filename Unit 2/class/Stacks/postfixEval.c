#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct stack {
    int *stackElements;
    int capacity;
    int top;
}Stack;

void createStack(Stack *s,int capacity)
{
    s->capacity = capacity;
    s->top = -1;
    s->stackElements = (int *) malloc(capacity * sizeof(int));
}

int isFull(Stack *s)
{
    return s->top == s->capacity - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *sptr,int ele)
{
    if(!isFull(sptr))
    {
        sptr->stackElements[++(sptr->top)] = ele; 
    }
    else
    {
        printf("Stack overflowed");
        exit(0);
    }
}

int pop(Stack *sptr)
{
    if(!isEmpty(sptr))
    {
        return sptr->stackElements[sptr->top--];
    }
    return -1;
}


int peek(Stack *sptr)
{
    if(!isEmpty(sptr))
        return sptr->stackElements[sptr->top];
    return -1;    
}

int isOperator(char e)
{
    if((e=='+')||(e=='-')||(e=='*')||(e=='/')||(e=='^'))
    {
        return 1;
    }
    return 0;
}

int power(int a,int b)
{
    if(b == 0)
        return a;
    return a * power(a,b-1);    
}

int evaluate(Stack *sptr,char *expression)
{
    int term = 0;
    int t1,t2;
    char temp;
    int len = strlen(expression);
    for(int i=0;i<len;i++)
    {
        if(!isOperator(expression[i]))
        {
            temp = expression[i];
            term = atoi(&temp);
            //printf("Expression %d\n",term);
            push(sptr,term);
        }
        else
        {
            if(!isEmpty(sptr))
            {
                t2 = pop(sptr);
                t1 = pop(sptr);
                switch (expression[i])
                {
                case '+':
                    term = t1 + t2;
                    break;
                case '-':
                    term = t1 - t2;
                    break;
                case '*':
                    term = t1 * t2;
                    break;
                case '/':
                    term = t1 / t2;
                    break;
                case '^':
                    term = power(t1,t2);
                    break;
                default:
                    exit(-1);
                }
                push(sptr,term);
            }
        }
    }
    return term;
}

int main()
{
    char expression[20];
    printf("Enter Expression: ");
    scanf("%s",expression);
    Stack s;
    createStack(&s,strlen(expression));
    int res = evaluate(&s,expression);
    printf("Result of %s is %d\n",expression,res);
    return 0;
}