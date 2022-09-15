#include "q1.h"
#include <stdio.h>
#include <stdlib.h>

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

int searchEle(Node **head,int ele)
{
    if(*head == NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        int pos = 1;
        Node *pres = *head;
        while(pres != NULL)
        {
            if((pres->info == ele)&&(pres!=NULL))
            {
                return pos;
            }
            pres = pres->next;
            pos++;
        }
    }
    return -1;
}
