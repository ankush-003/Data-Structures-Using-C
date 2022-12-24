#include <stdio.h>
#include <stdlib.h>

void read2d(int *ptr,int rsize,int csize)
{
    printf("Enter elements of array\n");
    for (int i = 0; i < rsize; i++)
    {
        for(int j = 0;j < csize;j++)
        {
            scanf("%d",ptr + i*csize + j);
        }
    }   
}

void print2d(int *ptr,int rsize,int csize)
{
    printf("Array elements are:\n");
    for (int i = 0; i < rsize; i++)
    {
        for(int j = 0;j < csize;j++)
        {
            printf("%d ",*(ptr + i*csize + j));
        }
        printf("\n");
    }
    
}

int main()
{
    /*int *ptr;
    int rsize, csize;
    printf("Enter row size and column size \n");
    scanf("%d%d",&rsize,&csize);
    ptr = (int*) malloc(sizeof(int)*rsize*csize);
    read2d(ptr,rsize,csize);
    print2d(ptr,rsize,csize);
    int *ptr1[rsize];
    for (int i = 0; i < rsize;i++)
    {
        ptr1[i] = (int*) malloc(sizeof(int)*csize);
    }
    printf("Enter elements of array:\n");
    for (int i = 0; i < rsize; i++)
    {
        for (int j = 0; j < csize; j++)
        {
            scanf("%d",ptr1[i] + j);  
        }
    }
    printf("Entered elements are:\n");
    for (int i = 0; i < rsize; i++)
    {
        for (int j = 0; j < csize; j++)
        {
            printf("%d\t",*(ptr1[i]+j));  
        }
        printf("\n");
    }*/
    
    int rowsize;
    printf("Enter row size ");
    scanf("%d",&rowsize);
    int colsize[rowsize];
    printf("Enter column size for each row:\n");
    for (int i = 0; i < rowsize; i++)
    {
        scanf("%d",colsize+i);
    }
    int *ptr[rowsize];
    int csize;
    for (int i = 0; i < rowsize;i++)
    {
        csize = colsize[i];
        ptr[i] = (int*) malloc(sizeof(int)*csize);
    }
    /*printf("Enter elements:\n");
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < colsize[i]; i++)
        {
            scanf("%d",(ptr[i] + j));
        }
        
    }*/
    printf("Elements of array are:\n");
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            printf("%d\t",*(ptr[i] + j));
        }
        printf("\n");
    }
}