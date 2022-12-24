#include "cdll.h"
#include <stdio.h>
#include <stdlib.h>

void initList(List* pl)
{
    pl->head = NULL;
}

Node *createNode(int ele)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    if(newNode != NULL)
    {
        newNode->info = ele;
        newNode->next = newNode->prev = NULL;
    }
    return newNode;
}

void insertFront(List* pl,int ele)
{
    Node *temp = createNode(ele);
    if(pl->head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        pl->head = temp;
    }
    else
    {
        Node *last = pl->head->prev;
        temp->next = pl->head;
        temp->prev = last;
        last->next = temp;
        pl->head->prev = temp;
        pl->head = temp;
    }
}

void insertLast(List* pl,int ele)
{
    Node *temp = createNode(ele);
    if(pl->head == NULL)
    {
        pl->head = temp;
        temp->next = pl->head;
        temp->prev = pl->head;
    }
    else {
        temp->next = pl->head;
        temp->prev = pl->head->prev;
        pl->head->prev->next = temp;
        pl->head->prev = temp;
    }
}

int countNode(List *pl)
{
    Node *temp = pl->head;
    int count = 0;
    if(pl->head != NULL)
    {
        do
        {
            temp = temp->next;
            count++;
        } while (temp != pl->head);
    }
    return count;
}

void insertAtPos(List* pl,int ele,int pos)
{
    if(pos == 1)
    {
        insertFront(pl,ele);
    }
    else if (pos == countNode(pl) + 1)
    {
        insertLast(pl,ele);
    }
    else if (pl->head == NULL)
    {
        printf("Invalid Position!\n");
    }
    else
    {
        Node *temp = createNode(ele);
        Node *pres = pl->head;
        int count = 1;
        do
        {
            pres = pres->next;
            count++;
        } while ((pres != pl->head)&&(count != pos));
        
        if(count == pos)
        {
            temp->next = pres;
            temp->prev = pres->prev;
            pres->prev->next = temp;
            pres->prev = temp;
        }
        else
        {
            printf("Invalid position!\n");       
        }
    }
}

void destroyList(List* pl)
{
    if(pl->head == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        Node *temp = NULL;
        Node *pres = pl->head;
        Node *last = pl->head->prev;
        while(pres != last)
        {
            temp = pres;
            pres = pres->next;
            printf("Deleted Node with info %d\n",temp->info);
            free(temp);
        }
        printf("Deleted Node with info %d\n",pres->info);
        free(pres);
        pres = temp = NULL;
    }
    pl->head = NULL;
}

void display(List* pl)
{
    if(pl->head)
    {
        Node *temp = pl->head;
        printf("\nElements of list are:\n");
        while (temp != (pl->head->prev))
        {
            printf("<-%d->",temp->info);
            temp = temp->next;
        }
        printf("<-%d->\n",temp->info);
    }
    else
    {
        printf("List is empty!\n");
    }
    printf("Number of Nodes %d\n",countNode(pl));
}

int deleteFront(List* pl,int *pe)
{
    if(pl->head == NULL)
    {
        printf("Empty List\n");
    }
    else if (pl->head == pl->head->prev)
    {
        //single node 
        *pe = pl->head->info;
        free(pl->head);
        pl->head = NULL;
        return 0;
    }
    else
    {
        Node *temp = pl->head;
        pl->head = temp->next;
        temp->prev->next = pl->head;
        pl->head->prev = temp->prev;
        *pe = temp->info;
        free(temp);
        return 0;
    }
    return -1;
}

int deleteLast(List* pl,int *pe)
{
    if(pl->head == NULL)
    {
      printf("Empty List!\n");
      return 1;
    }
    else if(pl->head->next == pl->head)
    {
        *pe = pl->head->info;
        free(pl->head);
        pl->head = NULL;
        return 0;
    }
    else
    {
        Node *last = pl->head->prev;
        pl->head->prev = last->prev;
        last->prev->next = pl->head;
        *pe = last->info;
        free(last);
        return 0;
    }
}

int deleteAtPos(List* pl,int *pe,int pos)
{
    if(pl->head == NULL)
    {
        printf("Empty List\n");
        *pe = NULL;
        return 1;
    }
    else if (pl->head->next == pl->head)
    {
        if(pos != 1)
        {
            printf("Invalid Position!\n");
            *pe = NULL;
            return 2;
        }
        else
        {
            *pe = pl->head->info;
            free(pl->head);
            pl->head = NULL;
            return 0;   
        }
    }
    else
    {
        int count = 0;
        Node *temp = pl->head;
        Node *last = pl->head->prev;
        temp = last;
        while()
    }
    
    
}

int deleteInfo(List* pl,int pe)
{
    return -1;
}