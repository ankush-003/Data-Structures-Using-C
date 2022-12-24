#include <stdio.h>
#include <stdlib.h>
#include "cdll.h"

int main()
{
    List cdll;
    initList(&cdll);
    int choice,pos,ele,flag;
    do
    {
        printf("Menu:\n1.) Insert Front\n2.) Insert Last\n3.) Insert at a Position\n");
        printf("4.) Delete Front\n5.) Delete Last\n6.) Delete at a Positon\n7.) Delete Element\n");
        printf("8.) Display List\n9.) Destroy List\n10.) Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d",&ele);
            insertFront(&cdll,ele);
            printf("Element %d inserted\n",ele);
            break;
        
        case 2:
            printf("Enter element: ");
            scanf("%d",&ele);
            insertLast(&cdll,ele);
            printf("Element %d inserted\n",ele);
            break;

        case 3:
            printf("Enter element: ");
            scanf("%d",&ele);
            printf("Enter position: ");
            scanf("%d",&pos);
            insertAtPos(&cdll,ele,pos);
            //printf("Element %d inserted at %d\n",ele,pos);
            break;

        case 4:
            flag = deleteFront(&cdll,&ele);
            if(!flag)
                printf("Deleted Node with info %d\n",ele);
            break;

        case 5:
            flag = deleteLast(&cdll,&ele);
            if(!flag)
                printf("Deleted Node with info %d\n",ele);
            break;   

        case 6:
            printf("Enter position of node to be deleted: ");
            scanf("%d",&pos);
            flag = deleteAtPos(&cdll,&ele,pos);
            if(!flag)
                printf("Deleted Node with info %d\n",ele);    
            break;

        case 7:
            printf("Enter info to be deleted: ");
            scanf("%d",&ele);
            deleteInfo(&cdll,ele);
            break;

        case 8:
            display(&cdll);
            break;

        case 9:
            destroyList(&cdll);
            break;        
    
        default:
            exit(0);
            break;
        }
    } while (choice < 10);
    return 0;
}