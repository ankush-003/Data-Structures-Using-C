#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

int main()
{
    int num1, num2;
    Node *ptr_num1 = NULL, *ptr_num2 = NULL, *ptr_res = NULL;
    printf("Enter Number 1 and Number 2: ");
    scanf("%d%d",&num1,&num2);
    ptr_num1 = createlist(ptr_num1,num1);
    ptr_num2 = createlist(ptr_num2,num2);
    displaylist(ptr_num1);
    displaylist(ptr_num2);
    ptr_res = addlist(ptr_num1,ptr_num2,ptr_res);
    displaylist(ptr_res);
    return 0;
}