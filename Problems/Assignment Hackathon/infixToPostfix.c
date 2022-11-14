#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

struct stack {
    int top;
    int size;
    char *arr;
};
typedef struct stack stack;

stack *createStack(int size) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->size = size;
    s->arr = (char *)malloc(sizeof(char) * size);
    return s;
}

bool isEmpty(stack *s) {
    return s->top == -1;
}

bool isFull(stack *s) {
    return s->top == s->size - 1;
}

void push(stack *s, char data) {
    if(isFull(s)) {
        printf("Stack Overflowed\n");
        return;
    }
    s->arr[++s->top] = data;    
}

char pop(stack *s) {
    if(isEmpty(s)) {
        printf("Stack Underflowed\n");
        return -1;
    }
    return s->arr[s->top--];
}

char peek(stack *s) {
    if(isEmpty(s)) {
        printf("Stack Underflowed\n");
        return -1;
    }
    return s->arr[s->top];
}

bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch) {
    switch(ch) {
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

int infixToPostfix(char *infix, char *postfix) {
    stack *s = createStack(strlen(infix));
    int i, j;
    for(i = 0,j = 0; infix[i]; i++) {
        if(isOperand(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '(') {
            push(s, infix[i]);
        }
        else if(infix[i] == ')') {
            while(!isEmpty(s) && peek(s) != '(') {
                postfix[j++] = pop(s);
            }
            if(!isEmpty(s) && peek(s) != '(') {
                printf("Invalid Expression\n");
                return -1;
            }
            pop(s);
        } else {
            while(!isEmpty(s) && precedence(infix[i]) <= precedence(peek(s))) {
                postfix[j++] = pop(s);
            }
            push(s, infix[i]);
        }
    }
    while(!isEmpty(s)) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
}

int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    char postfix[100];
    infixToPostfix(exp, postfix);
    printf("Postfix Expression %s\n", postfix);// abcd^e-fgh*+^*+i-
    return 0;
}