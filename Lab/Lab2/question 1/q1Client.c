#include <stdio.h>
#include <stdlib.h>
#include "q1.h"


int main()
{
    Node *head = NULL;
    int choice,ele,pos;
    do
    {
        printf("Menu:\n1.) Insert Element\n2.) Search Element\n3.) Display\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element: ");
            scanf("%d",&ele);
            insertList(&head,ele);
            break;
        case 2:
            printf("Enter element to be searched: ");
            scanf("%d",&ele);
            pos = searchEle(&head,ele);
            if(pos != -1)
            {
                printf("Node with info %d found at %d!\n",ele,pos);
            }
            else
            {
                printf("Element not found!\n");
            }
            break;

        case 3:
            displayList(&head);
            break;

        default:
            exit(0);
            break;
        }
    } while (choice < 4);
    return 0;
}