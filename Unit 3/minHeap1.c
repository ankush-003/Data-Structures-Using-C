// Recursion
#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    int size;  //size of the heap
};


MinHeap* init_minheap(int size) {
    MinHeap* minheap = (MinHeap*)calloc(1, sizeof(MinHeap));
    minheap->size = size;
    minheap->arr = (int*)calloc(size, sizeof(int));
    return minheap;
}

void heapify(MinHeap *heap,int i) {
    int min = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;
    if(lchild < heap->size) {
        if(heap->arr[lchild] < heap->arr[rchild] && heap->arr[lchild] < heap->arr[min]) {
            min = lchild;
        }
    }
    if(rchild < heap->size) {
        if(heap->arr[rchild] < heap->arr[lchild] && heap->arr[rchild] < heap->arr[min] && rchild < heap->size) {
            min = rchild;
        }
    }
    if(min != i) {
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[min];
        heap->arr[min] = temp;
        heapify(heap,min);
    }
}

void create_minheap(MinHeap *heap) 
{   
    int i;
    for (i = (heap->size)/2 - 1; i >= 0; i--)
    {
        heapify(heap,i);
    }
}

void print_minheap(MinHeap* heap) {
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ",heap->arr[i]);
    }
}

void free_minheap(MinHeap* heap) {
    if (!heap)
        return;
    free(heap->arr);
    free(heap);
}

void insert_heap(MinHeap* heap,int data) {
    if(heap->size == 0) {
        printf("Heap Not Created!\n");
        return;
    }
    heap->arr = (int*)realloc(heap->arr,heap->size+1);
    heap->arr[heap->size] = data;
    heap->size++;
    int child = heap->size - 1;
    int parent = (child - 1)/2;
    while(parent >= 0 && heap->arr[parent] > heap->arr[child]) {
        int temp = heap->arr[parent];
        heap->arr[parent] = heap->arr[child];
        heap->arr[child] = temp;
        child = parent;
        parent = (child - 1)/2;
    }
}

int main() {

    int capacity; 
    printf("Enter the capacity of the heap: ");
    scanf("%d", &capacity);
    MinHeap* heap = init_minheap(capacity); //number of elements 
    int i=0;
    while(i < capacity){
        printf("Enter the element: ");
        scanf("%d", &heap->arr[i++]);
    }
    create_minheap(heap);
    print_minheap(heap);
    printf("\n");
    int data;
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);
    insert_heap(heap,data);
    print_minheap(heap);
    free_minheap(heap);
    return 0;
}