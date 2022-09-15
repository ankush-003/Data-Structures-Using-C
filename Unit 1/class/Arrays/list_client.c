#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include "list.h"

int main()
{
    List mylist;
    int choice;
    int lsize, ele, pos;
    while(1)
    {
        printf("Menu:\n");
        printf("1. Create list\n2. Insert Element\n3. Delete Element\n4. Display\n5. Search\n6. Exit\n");
        printf("Enter choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter list size: ");
            scanf("%d",&lsize);
            create_list(&mylist,lsize);
            break;

        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d",&ele);
            printf("Enter the position: ");
            scanf("%d",&pos);    
            insert_ele(&mylist,ele,pos);
            break;

        case 3:
            printf("Enter position to be deleted: ");
            scanf("%d",&pos);
            delete_ele(&mylist,pos);
            break;

        case 4:
            display(&mylist);
            break;

        case 5:
            printf("Enter element to be searched: ");
            scanf("%d",&ele);
            pos = search(&mylist,ele);
            if (pos!=-1)
                printf("Element %d found at %d\n",ele,pos);
            else
                printf("Element unavailable\n");    
            break;

        default:
            exit(0);
        }
    }
}