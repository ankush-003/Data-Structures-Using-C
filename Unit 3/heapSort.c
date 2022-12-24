#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int N, int i) {
    int max = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;
    if(lchild < N) {
        if(arr[lchild] > arr[max]) {
            max = lchild;
        }
    }
    if(rchild < N) {
        if(arr[rchild] > arr[max]) {
            max = rchild;
        }
    }
    if(max != i) {
        swap(&arr[i],&arr[max]);
        heapify(arr,N,max);
    }
}

void heapsort(int *arr, int N) {
    for (int i = N/2 - 1; i >= 0; i--)
    {
        heapify(arr,N,i);
    }
    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

int main()
{
    printf("Enter the size of the array: ");
    int N;
    scanf("%d",&N);
    int *arr = (int*)malloc(N * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&arr[i]);
    }
    heapsort(arr,N);
    printf("The sorted array is: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}