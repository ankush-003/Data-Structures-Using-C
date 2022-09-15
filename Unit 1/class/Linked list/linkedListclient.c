#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main()
{
    Node *sl1_head;
    sl1_head = createList(sl1_head);
    int choice, ele, pos;

    do
    {
        printf("Menu:\n1.) Insert Front\n2.) Insert Rear\n3.) Insert at Pos\n4.) Delete Front\n5.) Delete Rear\n6.) Delete at position\n7.) Destroy List\n8.) Display List\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be inserted: ");
            scanf("%d",&ele);
            sl1_head = insertFront(sl1_head,ele);
            break;
        
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d",&ele);
            sl1_head = insertRear(sl1_head,ele);
            break;

        case 3:
            printf("Enter element to be inserted: ");
            scanf("%d",&ele);
            printf("Enter position: ");
            scanf("%d",&pos);
            sl1_head = insertAtPos(sl1_head,pos,ele);
            break;

        case 4:
            deleteFront(sl1_head);
            break;
            
        case 5:
            deleteRear(sl1_head);
            break;

        case 6:
            printf("Enter position of node to be deleted: ");
            scanf("%d",&pos);
            deleteAtPos(sl1_head,pos);
            break;
            
        case 7:
            sl1_head = destroyList(sl1_head);
            break;

        case 8:
            displayList(sl1_head);
            break;

        default:
            exit(0);
        }
    } while (choice < 9);
    
}

