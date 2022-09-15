#include <stdio.h>
#include <stdlib.h>

void readj(int *ptr[],int rsize,int csize[])
{
    printf("Enter elements of jag array\n");
    for (int i = 0; i < rsize; i++)
    {
        for (int j = 0; j < csize[i]; j++)
        {
            scanf("%d",(ptr[i] + j));//(*(ptr + i) + j)
        }
        
    }
    
}

void printj(int *ptr[],int rsize,int csize[])
{
    printf("Entered elements are\n");
    for (int i = 0; i < rsize; i++)
    {
        for (int j = 0; j < csize[i]; j++)
        {
            printf("%d\t",*(ptr[i] + j));//*(*(ptr + i) + j)
        }
        printf("\n");
    }
}

int main()
{
    int rsize;
    printf("Enter row size: ");
    int *ptr[rsize];
    scanf("%d",&rsize);
    int csize[rsize];
    for(int i = 0;i < rsize;i++)
    {
        printf("Enter column size of %dth row ",i);
        scanf("%d",&csize[i]);
    }
    for (int i = 0; i < rsize; i++)
    {
        ptr[i] = (int*) malloc(csize[i]*sizeof(int));
    }
    //POINTER ARRAY IS IN STACK
    //POINTER ARRAY ELEMENTS ARE IN HEAP
    readj(ptr,rsize,csize);
    printj(ptr,rsize,csize);
}