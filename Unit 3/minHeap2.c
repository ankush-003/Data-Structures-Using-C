// Iterative
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

// void heapify(MinHeap *heap,int i) {
//     int min = i;
//     int lchild = 2 * i + 1;
//     int rchild = 2 * i + 2;
//     if(lchild < heap->size) {
//         if(heap->arr[lchild] < heap->arr[rchild] && heap->arr[lchild] < heap->arr[min]) {
//             min = lchild;
//         }
//     }
//     if(rchild < heap->size) {
//         if(heap->arr[rchild] < heap->arr[lchild] && heap->arr[rchild] < heap->arr[min] && rchild < heap->size) {
//             min = rchild;
//         }
//     }
//     if(min != i) {
//         int temp = heap->arr[i];
//         heap->arr[i] = heap->arr[min];
//         heap->arr[min] = temp;
//         heapify(heap,min);
//     }
// }

void create_minheap(MinHeap *heap) 
{   
    int i,parent,child,temp;
    for (i = (heap->size)/2 - 1; i >= 0; i--)
    {
        parent = i;
        temp = heap->arr[parent];
        child = 2*i + 1;
        while (child < heap->size)
        {
            if(child + 1 < heap->size) {
                if(temp > heap->arr[child + 1]) {
                    child++;
                }
            }
            if(temp > heap->arr[child]) {
                heap->arr[parent] = heap->arr[child];
                parent = child;
                child = parent*2 + 1;
            }
            else {
                break;
            }
        }
        heap->arr[parent] = temp;
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

int main() {

    int capacity; 
    scanf("%d", &capacity);
    MinHeap* heap = init_minheap(capacity); //number of elements 
    int i=0;
    while(i < capacity){
        scanf("%d", &heap->arr[i++]);
    }
    create_minheap(heap);
    print_minheap(heap);
    free_minheap(heap);
    return 0;
}