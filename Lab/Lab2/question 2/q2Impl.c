#include <stdio.h>
#include <stdlib.h>
#include "q2.h"

void insertList(Node **head,int ele)
{
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->info = ele;
    temp->next = NULL;
    temp->prev = NULL;
    if((*head) == NULL)
    {
        *head = temp;
    }
    else {
        Node *pres = *head;
        while((pres->next != NULL)&&((pres->info) < ele))
        {
           pres = pres->next;
        }
        if(((pres->info) > ele)&&(pres != *head))
        {
            temp->next = pres;
            temp->prev = pres->prev;
            pres->prev->next = temp;
            pres->prev = temp;
        }
        else if (pres->info == ele)
        {
            return;
        }
        else if (((pres->info) >= ele)&&(pres == *head))
        {
            temp->next = pres;
            temp->prev = pres->prev;
            pres->prev = temp;
            *head = temp;
        }
        else
        {
            pres->next = temp;
            temp->prev = pres;
        }
    }
}

void displayList(Node **head)
{
    if(*head == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        Node *temp = *head;
        printf("Elements of list are: \n");
        while(temp != NULL)
        {
            printf("%d->",temp->info);
            temp = temp->next;
        }
        printf("\b\b\n");
    }
}

void mergeLists(Node **l1, Node **l2,Node **l3)
{
    Node *pres = *l1;
    while (pres != NULL)
    {
        insertList(l3,pres->info);
        pres = pres->next;
    }
    pres = *l2;
    while (pres != NULL)
    {
        insertList(l3,pres->info);
        pres = pres->next;
    }
}