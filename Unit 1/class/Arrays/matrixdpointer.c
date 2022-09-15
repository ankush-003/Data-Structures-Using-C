#include <stdio.h>
#include <stdlib.h>

void read2d(int **mat,int rsize,int csize)
{
    printf("Enter elements of array\n");
    for (int i = 0; i < rsize; i++)
    {
        for (int j = 0; j < csize; j++)
        {
          scanf("%d",(*(mat + i) + j));  
        }
    }
}

void print2d(int **mat,int rsize, int csize)
{
    printf("Elements of array are\n");
    for (int i = 0; i < rsize; i++)
    {
        for (int j = 0; j < csize; j++)
        {
          printf("%d\t",*(*(mat + i) + j));  
        }
        printf("\n");
    }
}

int main()
{
    int rsize, csize;
    int **mat;// to create array of pointers, pointer to a pointer
    printf("Enter row size and column size\n");
    scanf("%d %d",&rsize,&csize);
    mat = (int **) malloc(rsize * sizeof(int *));
    for (int i = 0; i < rsize; i++)
    {
        mat[i] = (int *) malloc(csize * sizeof(int));
    }

    read2d(mat,rsize,csize);
    print2d(mat,rsize,csize);
}