#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

struct expressionTree {
    char op;
    struct expressionTree *lchild;
    struct expressionTree *rchild;
};
typedef struct expressionTree ETree;

struct stack {
    ETree *ele[20];
    int top;
};
typedef struct stack S;

int isOperator(char e) {
    switch(e) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return 1;
        default:
            return 0;    
    }
}

void initS(S *sptr) {
    sptr->top = -1;
    for(int i = 0;i < 20;i++) {
        sptr->ele[i] = NULL;
    }
}

ETree *createNode(char e) {
    ETree *newNode = (ETree *) malloc(sizeof(ETree));
    newNode->op = e;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

ETree *buildETree(ETree *root,char *postFix) {
    int len = strlen(postFix);
    S auxS;
    initS(&auxS);
    ETree *newNode;
    for(int i = 0;i < len;i++) {
        if(isOperator(postFix[i])) {
            ETree *rop,*lop;
            rop = pop(&auxS);
            lop = pop(&auxS);
            newNode = createNode(postFix[i]);
            newNode->lchild = lop;
            newNode->rchild = rop;
            push(&auxS,newNode);
        }
        else {// is an operand
            newNode = createNode(postFix[i]);
            push(&auxS,newNode);
        }
    }
    return pop(&auxS);
}

float evaluateOp(ETree *root){
    float result = -1;
    switch(root->op) {
        case '+':
            result = evaluateOp(root->lchild) + evaluateOp(root->rchild);
            break;
        case '-':
            result = evaluateOp(root->lchild) - evaluateOp(root->rchild);
            break;
        case '*':
            result = evaluateOp(root->lchild) * evaluateOp(root->rchild);
            break;
        case '/':
            result = evaluateOp(root->lchild) / evaluateOp(root->rchild);
            break;
        case '^':
            result = pow(evaluateOp(root->lchild),evaluateOp(root->rchild));
            break;
        default: 
            return root->op - '0';  
    }           
    return result;
}

float evalETree(ETree *root) {
    if(isOperator(root->op)) {
        return evaluateOp(root);
    }
}

int main()
{
    char postFix[30];
    ETree *root = NULL;
    printf("\nEnter the postfix Expression: ");
    scanf("%s",postFix);
    root = buildETree(root,postFix);
    float result = -1;
    result = evalETree(root);
    return 0;
}