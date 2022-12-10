// MinHeap - Top Down Approach

#include<stdio.h>
#define MAX 100
void swap( int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int parent(int i){
    return (i-1)/2;
}
void insert(int heap[],int ele,int *n){
    int i;
    if(*n>=MAX){
        printf("\n Heap is Full cannot insert");
        return;
    }
    heap[*n]=ele;
    *n = *n+1;
    i=*n-1;
    while(i!=0 && heap[i]<heap[parent(i)]){
        swap(&heap[parent(i)], &heap[i]);
        i=parent(i);
    }
    
}
void print_heap(int heap[],int n){
    for(int i=0;i<n;i++)
        printf("%d ", heap[i]);
}
int main(){
    int heap[MAX];
    int n,min;
    int ele, size=0;
    printf("\n How many elements in the heap?? : " );
    scanf("%d",&n);
    printf("\n Enter the elements of the heap : \n");
    for(int i=0;i<n;i++){
        scanf("%d", &ele);
        insert(heap, ele, &size);
    }
    printf("\n Elements of heap\n");
    print_heap(heap,n);
}