#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

int **createMatrix(int rsize, int csize) {
    int **matrix = (int **) malloc(rsize * sizeof(int *));
    for(int i = 0; i < rsize; i++) {
        matrix[i] = (int *) malloc(csize * sizeof(int));
    }
    return matrix;
}

void displayMatrix(int **matrix, int rsize, int csize) {
    for (int i = 0; i < rsize; i++)
    {
        for (int j = 0; j < csize; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    } 
}

void mulMatrices(int **mat1, int **mat2, int rsize1, int csize2, int csize1) {
    int **res = createMatrix(rsize1,csize2);
    int sum = 0;
    for(int i = 0; i < rsize1; i++) {
        for(int j = 0; j < csize2;j++) {
            sum = 0;
            for(int k = 0; k < csize1;k++) {
                sum += mat1[i][k] * mat2[k][j];
            }
            res[i][j] = sum;
        }
    }
    printf("Multiplication Result:\n");
    displayMatrix(res, rsize1, csize2);
}

int main()
{
    printf("Enter Row size and Column Size for Matrix1: ");
    int rsize1,csize1;
    scanf("%d %d",&rsize1, &csize1);
    int **mat1 = createMatrix(rsize1,csize1);
    for (int i = 0; i < rsize1; i++)
    {
        for (int j = 0; j < csize1; j++)
        {
            printf("Enter data for row %d column %d: ",i,j);
            scanf("%d",&(mat1[i][j]));
        }
        
    }

    printf("Enter Row size and Column Size for Matrix2: ");
    int rsize2, csize2;
    scanf("%d %d",&rsize2, &csize2);
    int **mat2 = createMatrix(rsize2,csize2);
    for (int i = 0; i < rsize2; i++)
    {
        for (int j = 0; j < csize2; j++)
        {
            printf("Enter data for row %d column %d: ",i,j);
            scanf("%d",&(mat2[i][j]));
        }
        
    }
    printf("Matrix1:\n");
    displayMatrix(mat1, rsize1, csize1);
    printf("\nMatrix2:\n");
    displayMatrix(mat2, rsize2, csize2);

    if(csize1 == rsize2) {
        mulMatrices(mat1, mat2, rsize1, csize2, csize1);
    } else printf("Matrices cannot br multiplied!");
    return 0;
}