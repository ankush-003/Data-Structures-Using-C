#include <stdio.h>
#include <stdlib.h>
#include "q2.h"

int main()
{
    Node *l1 = NULL;
    Node *l2 = NULL;
    Node *l3 = NULL;
    int choice,ele,pos;
    do
    {
        printf("Menu:\n1.) Insert List 1\n2.) Insert List 2\n3.) Merge Lists\n4.) Display\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element: ");
            scanf("%d",&ele);
            insertList(&l1,ele);
            break;
        case 2:
            printf("Enter Element: ");
            scanf("%d",&ele);
            insertList(&l2,ele);
            break;

        case 3:
            mergeLists(&l1,&l2,&l3);
            break;

        case 4:
            printf("List 1: ");
            displayList(&l1);
            printf("List 2: ");
            displayList(&l2);
            printf("List 3: ");
            displayList(&l3);
            break;

        default:
            exit(0);    
        }
    } while (choice < 5);
    return 0;
}