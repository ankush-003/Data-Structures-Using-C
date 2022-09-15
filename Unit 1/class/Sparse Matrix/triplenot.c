#include <stdio.h>
#include <stdlib.h>

typedef struct triple_notation
{
    int col;
    int row;
    int value;
}t_not;

int main()
{
    int rsize,csize,num,nonzero;
    printf("Enter row size and column size: ");
    scanf("%d%d",&rsize,&csize);
    printf("Enter number of non-zero values: ");
    scanf("%d",&nonzero);
    t_not matrix[rsize*csize];
    printf("Enter %d elements of sparse matrix\n",rsize * csize);
    matrix[0].row = rsize;
    matrix[0].col = csize;
    matrix[0].value = nonzero;
    int pos = 1;
    for(int i = 0; i < rsize;i++)
    {
        for (int j = 0;j< csize; j++)
        {
            scanf("%d",&num);
            if(num)
            {
                matrix[pos].value = num;
                matrix[pos].col = j;
                matrix[pos].row = i;
                pos++;
            } 
        } 
    }
    printf("R C V\n");
    for(int i = 0;i<pos;i++)
    {
        printf("%d %d %d\n",matrix[i].row, matrix[i].col, matrix[i].value);
    }
    return 0;
}