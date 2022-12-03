

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

Node *createList(Node *head)
{
    head = NULL;
    return head;
}

Node *insertFront(Node *head,int ele)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = ele;
    newNode->link = NULL;

    if(!head) // or head == NULL
    {
        head = newNode;
    }
    else
    {
        newNode->link = head;
        head = newNode;
    }
    return head;
}

Node *insertRear(Node *head,int ele)
{
    Node *newNode = NULL, *current;
    newNode = (Node *) malloc(sizeof(Node));
    newNode->data = ele;
    newNode->link = NULL;
    current = head;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        while(current->link != NULL)
        {
            current = current->link;
        }
        current->link = newNode;
    }
    return head;
}

Node *insertAtPos(Node *head,int pos,int ele)
{
    if(pos == 1)
    {
        head = insertFront(head, ele);
        return head;
    }
    else if (head == NULL)
    {
        printf("Invalid Position as list is empty\n");
        return head;
    }
    else
    {
        Node *newNode = NULL, *cur = head;
        newNode = (Node *) malloc(sizeof(Node));
        newNode->data = ele;
        newNode->link = NULL;

        for(int i = 1;(i < (pos - 1));i++) {
            //i  till pos - 1 because we stop at pos - 1
            cur = cur->link;
            if(cur == NULL)
            {
                printf("Invalid position\n");
                head = insertRear(head, ele);
                printf("Appended at end\n");
                return head;
            }
        }
        newNode->link = cur->link;
        cur->link = newNode;
        return head;    
    }
}

void displayList(Node *head)
{
    Node *cur = head;
    int count = 0;
    printf("\nList elements are:\n");
    while(cur)
    {
        printf("%d --> ",cur->data);
        cur = cur->link;
        count++;
    }
    printf("Null\nNumber of elements: %d\n\n",count);
}

Node *deleteFront(Node *head)
{
    if(head == NULL)
    {
        printf("No elements to be deleted\n");
    }
    else
    {
        Node *temp = head;
        head = temp->link;
        printf("Deleted element: %d at front\n",temp->data);
        free(temp);
        temp = NULL;
    }
    return head;
}

Node *deleteRear(Node *head)
{
    if(head == NULL)
    {
        printf("No elements to delete!\n");
    }
    else
    {
        Node *prev = NULL;
        Node *pres = head;
        while (pres->link != NULL)
        {
            prev = pres;
            pres = pres->link;
        }
        prev->link = NULL;
        printf("Deleted Node with data %d\n",pres->data);
        free(pres);
        pres = NULL; 
    }
    return head;
}

Node *deleteAtPos(Node *head,int pos)
{
    if(head == NULL)
    {
        printf("No element to be deleted!\n");
    }
    else if (pos == 1)
    {
        head = deleteFront(head);
    }
    else
    {
        Node *prev = NULL;
        Node *pres = head;
        int count = 1;
        while ((pres != NULL)&&(count != pos))
        {
            prev = pres;
            pres = pres->link;
            count++;
        }
        if(pres == NULL)
        {
            printf("Invalid postion!\n");
        }
        else
        {
            prev->link = pres->link;
            printf("Deleted Node with data %d\n",pres->data);
            free(pres);
        }
    }
    return head;
}

Node *destroyList(Node *head)
{
    if(head == NULL)
    {
        printf("Empty list!\n");
    }
    else
    {
        Node *prev = NULL;
        Node *pres = head;
        while (pres != NULL)
        {
            prev = pres;
            pres = pres->link;
            printf("Deleted Node with data %d\n",prev->data);
            free(prev);
        }
        prev = NULL;
        head = pres;
    }
    return head;
}