#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

Node *insertfront(Node *head,int digit)
{
    Node *temp = NULL;
    temp = (Node *) malloc(sizeof(Node));
    temp->digit = digit;
    temp->rlink = NULL;
    temp->llink = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        head->llink = temp;
        temp->rlink = head;
        head = temp;
    }
    return head;
}

Node *createlist(Node *head,int number)
{
    int rem;
    while(number > 0)
    {
        rem = number%10;
        number = number/10;
        head = insertfront(head,rem);
        //printf("inserted %d\n",head->digit);
    }
    return head;
}

void displaylist(Node *head)
{
    printf("Elements of list are: \n");
    Node *temp = head;
    while(temp != NULL)
    {
        printf("%d->",temp->digit);
        temp = temp->rlink;
    }
    printf("NULL\n");
}

Node *addlist(Node *l1,Node *l2,Node *res)
{
    Node *cur1 = NULL, *cur2 = NULL;
    int carry = 0, sum;
    cur1 = l1;
    cur2 = l2;
    //to reach last node
    while(cur1->rlink != NULL)
        cur1 = cur1->rlink;

    while(cur2->rlink != NULL)
        cur2 = cur2->rlink;  

    while (cur1!=NULL && cur2!= NULL)
    {
        sum = cur1->digit + cur2->digit + carry;
        if(sum > 9)
        {
            carry = sum / 10;
            sum = sum % 10;
        }
        else
            carry = 0;
        res = insertfront(res,sum);
        cur1 = cur1->llink;
        cur2 = cur2->llink;
    }

    if(cur1 == NULL && cur2 == NULL)
    {
        if(carry)
            res = insertfront(res,carry);
    }
    else
    {
       while (cur1!=NULL)
        {
            sum = cur1->digit + carry;
            if(sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }
            else
                carry = 0;
            res = insertfront(res,sum);
            cur1 = cur1->llink;
        } 

        while (cur2!=NULL)
        {
            sum = cur2->digit + carry;
            if(sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }
            else
                carry = 0;
            res = insertfront(res,sum);
            cur2 = cur2->llink;
        } 
        if(carry)
        res = insertfront(res,carry);
    }
    return res;
}