#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#define MAX 20

void minHeapify(int *heap,int i,int n) {
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;
    int min = i;
    
    if(heap[lchild] < heap[rchild] && heap[lchild] < heap[min] && lchild < n) {
        min = lchild;
    }
    if(heap[rchild] < heap[lchild] && heap[rchild] < heap[min] && rchild < n) {
        min = rchild;
    }
    if(min != i) {
        // swapping min with root
        int temp = heap[i];
        heap[i] = heap[min];
        heap[min] = temp;
        // swapping till we reach leaf node
        minHeapify(heap,min,n);
    }

}

void buildMinHeap(int *heap,int n) {
    int i;
    for(i=(n/2-1);i>=0;i--) {
        minHeapify(heap,i,n);
    }
}

void insertHeap(int *heap,int ele,int *n) {
    if(*n > MAX-1) {
        printf("Heap is FUll!\n");
    }
    else {
        // We dont have to compare with sibling node so we cant use heapify
        heap[*n] = ele;
        (*n)++;
        int i = *n - 1;
        int temp;
        while(i!=0 && heap[i]<heap[(i-1)/2]) {
            temp = heap[i];
            heap[i] = heap[(i-1)/2];
            heap[(i-1)/2] = temp;
        }
    }
}

int delete(int *heap,int *n) {
    int min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    minHeapify(heap,0,n);
    return min;
}

void printHeap(int *heap,int n) {
    printf("Heap Elements: ");
    for(int i = 0;i < n;i++) {
        printf("%d ",heap[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    int heap[MAX];
    printf("Enter size of heap: ");
    scanf("%d",&n);
    

    int ele;
    printf("Enter element to be inserted: ");
    scanf("%d",&ele);
    insertHeap(heap,ele,&n);

    int min = delete(heap,&n);
    printf("Min Element %d is deleted!\n",min);
    return 0;
}