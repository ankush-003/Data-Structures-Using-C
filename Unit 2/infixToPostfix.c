#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    int top,capacity;
    char *arr;
}Stack;

void createStack(Stack *sptr,int capacity)
{
    sptr->capacity = capacity;
    sptr->top = -1;
    sptr->arr = (char *) malloc(capacity * sizeof(char));
}

int isFull(Stack *sptr)
{
    return sptr->top == sptr->capacity - 1;
}

int isEmpty(Stack *sptr)
{
    return sptr->top == -1;
}

void push(Stack *sptr,char ele)
{
    if(isFull(sptr))
    {
        printf("Stack Overflowed!\n");
        exit(-1);
    }
    else
    {
        sptr->arr[++(sptr->top)] = ele;
    }
}

char pop(Stack *sptr)
{
    if(isEmpty(sptr))
    {
        printf("Stack Underflowed!\n");
        return '\0';
    }
    else
    {
        return sptr->arr[sptr->top--];
    }
}

char peek(Stack *sptr)
{
    if(isEmpty(sptr))
    {
        return '\0';
    }
    else
    {
        return sptr->arr[sptr->top];
    }
}

int prec(char ele)
{
    switch (ele)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;    
    }
    return -1;
}

int isOperand(char c)
{
    if((c >= 'a' && c<= 'z')||(c >= 'A' && c<='Z'))
    {
        return 1;
    }
    return 0;
}

void infixToPostfix(char *expression)
{
    Stack s;
    createStack(&s,strlen(expression));
    int k=-1;
    for (int i = 0;expression[i]; i++)
    {
        if (isOperand(expression[i]))
        {
            expression[++k] = expression[i];
        }
        else if (expression[i]=='(')
        {
            push(&s,expression[i]);
        }
        else if (expression[i]==')')
        {
            while(!isEmpty(&s) && peek(&s)!='(')
            {
                expression[++k] = pop(&s);
            }
            if(isEmpty(&s) && peek(&s) != '(')
            {
                printf("Invalid Expression!\n");
                exit(-1);
            }
            pop(&s);
        }
        else
        {
            if((prec(expression[i])>prec(peek(&s)))||peek(&s)=='(')
            {
                push(&s,expression[i]);
            }
            else
            {
                while (!isEmpty(&s)&&(prec(expression[i])<=prec(peek(&s))))
                {
                    expression[++k] = pop(&s);
                }
                // // checking left or right associative
                // while(!isEmpty(&s)&&(prec(expression[i])==prec(peek(&s))))
                // {
                //     if(prec(peek(&s))==3)// ^ is right associative
                //     {
                //         break;
                //     }
                //     else // left associative
                //     {
                //         expression[++k] = pop(&s);
                //     }
                // }
                push(&s,expression[i]);
            }
        }
    }
    while (!isEmpty(&s))
    {
        expression[++k] = pop(&s);
    }
    expression[++k] = '\0';// we have to end the string here only!
}

int main() {
    char exp[20];
    printf("Enter infix Expression: ");
    scanf("%s",exp);
    infixToPostfix(exp);
    printf("Postfix expression: %s\n",exp);
    return 0;
}
