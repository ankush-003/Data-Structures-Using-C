#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
typedef struct tnode
{
  char data;
  struct tnode *left;
  struct tnode *right;
}tnode;
int isoperator(char ch){
    switch(ch){
        case '+':
        case '-':
        case '*':
        case '/': return 1;
        default: return 0;
    }
}
tnode * construct_exptree(char *exp){
    stack st;
    st.top=-1;
    int i=0;
    tnode *temp,*root=NULL;
    while(exp[i]!='\0'){
        if(isoperator(exp[i])){
            root=(tnode *)malloc(sizeof(tnode));
            root->data=exp[i];
            temp=pop(&st);
            root->right=temp;
            temp=pop(&st);
            root->left=temp;
            push(&st,root);
        }
        else{
            root=(tnode *)malloc(sizeof(tnode));
            root->data=exp[i];
            root->left=root->right=NULL;
            push(&st,root);
        }
        i++;

    }
    return (pop(&st));

}

void inorder(tnode *t){
    if(t!=NULL){
        inorder(t->left);
        printf("%c  ",t->data);
        inorder(t->right);
    }
}

int exp_evaluation(tnode *root){
    int x;
    switch(root->data){
        case '+':return(exp_evaluation(root->left) + exp_evaluation(root->right));
                break;
        case '-': return (exp_evaluation(root->left) - exp_evaluation(root->right));
                break;
        case '*':return (exp_evaluation(root->left) * exp_evaluation(root->right));
                break;
        case '/':return (exp_evaluation(root->left) / exp_evaluation(root->right));
                break;
        default:printf("\n Enter the value for the operand %c: ", root->data);
                scanf("%d",&x);
                return x;
    }
}
int main(){
    char exp[100];
    int result;
    tnode *root=NULL;
    printf("\n Enter the postfix expression: ");
    scanf("%s",exp);
    root=construct_exptree(exp);
    printf("\n The infix expression is \n");
    inorder(root);
    printf("\n Result of evaluation : \n");
    result=exp_evaluation(root);
    printf("%d",result);
    return 0;
}