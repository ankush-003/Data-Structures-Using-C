#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#define SIZE 100

struct stack{
    union 
    {
        int *operands;
        char *elements;
    };
    int top;
    int size;
};
typedef struct stack stack;

void initStack(stack *sptr,int size)
{
    sptr->top = -1;
    sptr->size = size;
    sptr->elements = (char *) malloc(size * sizeof(char));
}

int isFull(stack *sptr)
{
    return sptr->top == sptr->size - 1; 
}

int isEmpty(stack *sptr)
{
    return sptr->top == -1;
}

void push(stack *sptr,char ele)
{
    if(!isFull(sptr))
    {
        sptr->elements[++sptr->top] = ele;
    }
}

char pop(stack *sptr)
{
    if(isEmpty(sptr))
    {
        printf("Stack is Empty!\n");
        exit(0);
    }
    char ele = sptr->elements[sptr->top--];
    return ele;
}

char peek(stack *sptr)
{
    return sptr->elements[sptr->top];
}

int isOperand(char ele)
{
    return (ele >='0')&&(ele<='9');
}

int precedence(char op)
{
    //printf("%c\n",op);
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
    case '%':
        return 2;
    case '^':
        return 3;        
    }
    return 0;
}

void infixToPrefix(char *infix,char *prefix)
{
    int n = strlen(infix);
    int k = n;
    prefix[k] = '\0';
    k--;
    stack s;
    initStack(&s,n);
    for(int i = n-1;i >= 0;i--)
    {
        if(isOperand(infix[i]))
        {
            prefix[k] = infix[i];
            k--;
            //printf("%s",prefix);
        }
        else {
            if(peek(&s)==')'||precedence(infix[i])>precedence(peek(&s)))
                push(&s,infix[i]);
            else if(infix[i]=='(')
            {
                while (!isEmpty(&s)&&(peek(&s)!=')'))
                {
                    prefix[k--] = pop(&s);
                }
                if(isEmpty(&s))
                {
                    printf("Invalid Expression!\n");
                    exit(0);
                }
                pop(&s);
            }
            else
            {
                while(!isEmpty(&s) && precedence(infix[i])<precedence(peek(&s)))
                {
                    prefix[k--] = pop(&s);
                }
                push(&s,infix[i]);
            }    
        }
    }
    while(!isEmpty(&s))
    {
        prefix[k--] = pop(&s);
    }
}

int evalOp(char op,int t1,int t2)
{
    int res = -1;
    switch (op)
    {
    case '+':
        res =  (t1)+ (t2);
        break;
    case '-':
        res =  (t1)- (t2);
        break;
    case '/':
        res =  (t1)/ (t2);
        break;
    case '*':
        res =  (t1)* (t2);
        break;
    case '%':
        res =  (t1)% (t2);
        break;
    case '^':
        res = pow( (t1), (t2));    
        break;
    }
    return res;
}

void initStack2(stack *sptr,int size)
{
    sptr->size = size;
    sptr->top = -1;
    sptr->operands = (int *) malloc(size * sizeof(int));
}

void pushOperand(stack *sptr,int ele)
{
    if(!isFull(sptr))
    {
        sptr->operands[++sptr->top] = ele;
    }
}

int popOperand(stack *sptr)
{
    if(!isEmpty(sptr))
    {
        return sptr->operands[sptr->top--];
    }
    return -1;
}

int evalPrefix(char *prefix)
{
    stack s;
    int len = strlen(prefix);
    initStack2(&s,len);
    char temp;
    int term1,term2;
    int res = -1;
    for(int i = len-1;i >= 0;i--)
    {
        if(isOperand(prefix[i]))
        {
            temp = prefix[i];
            pushOperand(&s,atoi(&temp));
        }
        else
        {
            term1 = popOperand(&s);
            term2 = popOperand(&s);
            res = evalOp(prefix[i],term1,term2);
            //printf("%d\n",res);
            pushOperand(&s,res);
        }    
    }
    res = popOperand(&s);
    return res;
}

int main()
{
    char infix[SIZE];
    char prefix[SIZE];
    printf("Enter Expression: ");
    scanf("%s",infix);
    infixToPrefix(infix,prefix);
    printf("Prefix Expression: %s\n",prefix);
    int res = evalPrefix(prefix);
    printf("Expression evaluates to: %d\n",res);
    return 0;
}