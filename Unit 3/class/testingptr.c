#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include<stdbool.h>
#include <math.h>

void change(int **ptr1,int **ptr2) {
    *ptr1 = *ptr2;
}

int main()
{
    int a = 6;
    int b = 9;
    int *ptr1 = &a,*ptr2 = &b;
    change(&ptr1,&ptr2);
    printf("%d %d\n",*ptr1,*ptr2);
    return 0;
}