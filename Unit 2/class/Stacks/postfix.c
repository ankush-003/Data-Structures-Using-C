#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    char *stackelements;
    int capacity;
    int top;
}Stack;

void createStack(Stack *s,int capacity)
{
    s->capacity = capacity;
    s->top = -1;
    s->stackelements = (char *) malloc(capacity * sizeof(char));
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
        sptr->stackelements[++(sptr->top)] = ele; 
    }
    else
    {
        printf("Stack overflowed");
        exit(0);
    }
}

char peek(Stack *sptr)
{
    if(!isEmpty(sptr))
        return sptr->stackelements[sptr->top];
    return '\0';    
}

char pop(Stack *sptr)
{
    if(!isEmpty(sptr))
    {
        return sptr->stackelements[sptr->top--];
    }
    return '\0';
}

int isOperand(char e)
{
    if((e>='a' && e<='z')||(e>='A' && e<='Z'))
    {
        return 1;
    }
    return 0;
}

int prec(char c)
{
    switch(c)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '^':return 3;
        default: printf("Invalid operator");
                exit(0);
    }
}

int isLeftAssociative(char e)
{
    switch (e)
    {
    case '+':
    case '-':
    case '*':
    case '/':return 1;
        break;
    case '^':return 0;
    default:
        printf("Invalid token!\n");
        exit(0);
    }
}

char *infixToPostFix(char *expression)
{
    Stack s;
    int len = strlen(expression);
    createStack(&s,len);
    char *postFix = (char *) malloc(len * sizeof(char));
    int k = 0;
    for (int i = 0; i < len; i++)
    {
        if(isOperand(expression[i]))
        {
            postFix[k++] = expression[i];
        }
        else
        {
            if(expression[i]=='(')
            {
                push(&s,expression[i]);
            }
            else if (expression[i]==')')
            {
                while (!isEmpty(&s)||peek(&s)!='(')
                {
                    postFix[k++] = pop(&s);
                }
                if(isEmpty(&s))
                {
                    printf("Invalid infix expression!\n");
                    exit(0);
                }
                pop(&s);

            }
            else
            {
                if((isEmpty(&s))||(prec(expression[i])>prec(peek(&s))))
                {
                    push(&s, expression[i]);
                    continue;
                }
                else if (prec(expression[i]) < prec(peek(&s)))
                {
                    while (!isEmpty(&s) && (prec(expression[i]) == prec(peek(&s))))
                    {
                        postFix[k++] = pop(&s);
                    }
                    push(&s,expression[i]);
                    continue;
                }
                if(!isEmpty(&s)&&(prec(expression[i])==prec(peek(&s))))
                {
                    if(isLeftAssociative(expression[i]))
                    {
                        while (!isEmpty(&s) && (prec(expression[i])==prec(peek(&s))))
                        {
                            postFix[k++] = pop(&s);
                        }
                        push(&s,expression[i]);
                        continue;
                    }
                }
            }
        }
    }
    while (!isEmpty(&s))
    {
        postFix[k++] = pop(&s);
    }
    postFix[k] = '\0';
    return postFix;
}

int main()
{
    char expression[20];
    char *postfix;
    printf("Enter the infix expression: ");
    scanf("%s",expression);
    postfix = infixToPostFix(expression);
    printf("%s",postfix);
    return 0;
}