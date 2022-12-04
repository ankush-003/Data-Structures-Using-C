#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

typedef struct polynode {
    int coeff;
    int exp;
    struct polynode *next;
} node;

node *createNode(int coeff, int exp) {
    node *new = (node *)malloc(sizeof(node));
    new->coeff = coeff;
    new->exp = exp;
    new->next = NULL;
    return new;
}

void insertList(node **head, int coeff, int exp) {
    if(*head == NULL) {
        *head = createNode(coeff, exp);
        return;
    }
    node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(coeff, exp);
}

void display(node *head) {
    while(head->next != NULL) {
        printf("%d.x^%d+", head->coeff, head->exp);
        head = head->next;
    }
    printf("%d.x^%d \n", head->coeff, head->exp);
}

void get_poly(node **head) {
    int ch;
    do {
        printf("Do you want to add data?(0/1) : ");
        scanf("%d", &ch);
        if(!ch) {
            break;
        }
        int coeff, exp;
        printf("\nEnter coeff : ");
        scanf("%d", &coeff);
        printf("\nEnter exponent : ");
        scanf("%d", &exp);
        insertList(head, coeff, exp);
    } while(ch);
}

int power(int x, int y) {
    if(y == 0) {
        return 1;
    }
    for(int i = 1; i < y;i++) {
        x *= x;
    }
    return x;
}

void evalDerivative(node *head, int x) {
    int result = 0;
    node *curr = head;
    while(curr) {
        result += curr->coeff * curr->exp * power(x, curr->exp - 1);
        curr = curr->next;
    }
    printf("Derivative of the polynomial is %d \n", result);
}

void multiply(node *head1, node *head2) {
    node *curr1 = head1;
    node *curr2 = head2;
    node *result = NULL;
    while(curr1) {
        while(curr2) {
            insertList(&result, curr1->coeff * curr2->coeff, curr1->exp + curr2->exp);
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
        curr2 = head2;
    }
    display(result);
}


int main()
{
    node *head = NULL;
    get_poly(&head);
    display(head);
    evalDerivative(head, 2);
    return 0;
}