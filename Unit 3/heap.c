/*
i) Complete Binary Tree
ii) Parental Dominance

1) There exists exactly one essentially complete binary tree with n nodes, height is equal to floor(log2N)
2) The root of heap contains the largest Element(max Heap / Descending)
3) A node of heap considered with all its descendants is also a heap

-> In array representation (top-down, left-right) parental node keys will be first floor(n/2) positions of array
*/

// Top Down Max Heap

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#define MAX 50


int main()
{
    int arr[MAX];
    int i,n,child,parent;
    printf("Enter Number of elements: ");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d : ",i);
        scanf("%d",&arr[i]);
    }
    int temp;
    //heapify (assuming one element has formed heap)
    for(i = 1;i < n;i++) {
        temp = arr[i];
        child = i;
        parent = (child - 1) / 2;
        while (child > 0 && arr[parent] < temp)
        {
            arr[child] = arr[parent];
            child = parent;
            parent = (child - 1) / 2;
        }
        arr[child] = temp;
    }
    // Display Heapified Elements
    printf("Elements of heap: ");
    for(i = 0; i < n;i++) {
        printf("%d ",arr[i]);
    }

    // Heap sort: (nlogn)
    for(i = n-1;i > 0;i++) {
        temp = arr[i];
        arr[i] = arr[0];
        parent = 0;
        if(i == 1) {
            child = -1;// to stop
        }
        else {
            child = 1;
        }
        if(i > 2 && arr[2] > arr[1]) 
            child = 2;
        while (child >= 0 && temp < arr[child])
        {
            arr[parent] = arr[child];
            parent = child;
            child = 2 * parent + 1;
            
        }
            
    }
    return 0;
}