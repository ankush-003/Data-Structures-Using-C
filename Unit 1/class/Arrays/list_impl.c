// stack follows last in first out
// queue follows first in first out
// abstract data types
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void create_list(List *lptr,int lsize)
{
    lptr->arr = (int *) malloc(lsize * sizeof(int));
    lptr->arrsize = lsize;
    lptr->noe = 0;   
}

void insert_ele(List *lptr,int ele,int pos)
{
    //three cases
    // if pos is beyond array size
    if (pos >= (lptr->arrsize))
    {
        printf("Invalid position you noob!\n");
        return;
    }
    // this case is to append if pos > noe     
    if ((pos >= (lptr->noe))&&(pos < (lptr->arrsize)))
    //else if (pos > (lptr->noe))
    {
        lptr->arr[lptr->noe] = ele;
        lptr->noe++;
        return;// else noe is updated is twice
    }
    // if pos is noe it comes to this loop and escapes for loop
    /*else
    {
        for (int i = (lptr->noe)-1; i >= pos; i--)
        {
            lptr->arr[i+1] = lptr->arr[i];
        }
        lptr->arr[pos] = ele;
        lptr->noe++;
    } */   
    for (int i = (lptr->noe)-1; i >= pos; i--)
    {
        lptr->arr[i+1] = lptr->arr[i];
    }
    lptr->arr[pos] = ele;
    lptr->noe++;
}

void display(List *lptr)
{
    printf("Contents of the list are:\n");
    for (int i = 0; i < (lptr->noe); i++)
    {
        printf("%d\t",lptr->arr[i]);
    }
    printf("\nnumber of elements: %d\n",lptr->noe);
}

void delete_ele(List *lptr,int pos)
{
    if(pos >= lptr->arrsize)
        printf("Out of bound of array\n");
    else if (pos >= lptr->noe)
        printf("No element to be deleted\n");
    else
    {
        for (int i = pos; i < ((lptr->noe)); i++)
        {
            lptr->arr[i] = lptr->arr[i+1];
        }
        lptr->noe--;
        printf("Element deleted successfully\n");
    }        
}

int search(List *lptr,int ele)
{
    int pos = -1;
    for (int i = 0; i < (lptr->noe); i++)
    {
        if((lptr->arr[i])==ele)
            pos = i;
    }
    return pos;
}