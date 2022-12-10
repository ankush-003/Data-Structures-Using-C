//Heap using Bottom up Approach
#include<stdio.h>
#define Max 50
void minheapify(int heap[], int i,int n){
    int lchild,rchild;
    int min=i;
    int temp;
    lchild=2*i+1;
    rchild=2*i+2;
    
    if(lchild<n && heap[lchild]<heap[min])
             min=lchild;
    
    
    if(rchild<n && heap[rchild]<heap[min])
            min=rchild;
    
    if(min!=i){
        temp=heap[i];
        heap[i]=heap[min];
        heap[min]=temp;
        minheapify(heap,min,n);

    }
    

}
void printheap(int heap[], int n){
    printf("\n Heap Elements :\n");
    for(int i=0;i<n;i++)
        printf("%d  ", heap[i]);
}
void build_minheap(int heap[],int n){
    int i;
    for(i=(n/2)-1 ; i>=0;i--)
        minheapify(heap, i,n);
}
void insert(int heap[],int ele,int *n){
    int temp;
    heap[*n]=ele;
    *n=*n+1;
    int i=*n-1;
    while(i!=0 && heap[i]<heap[(i-1)/2]){
        temp=heap[i];
        heap[i]=heap[(i-1)/2];
        heap[(i-1)/2]=temp;
        i=(i-1)/2;

    }
}
int delet(int heap[],int *n){
    int min=heap[0];
    heap[0]=heap[*n-1];
    *n=*n-1;
    minheapify(heap,0,*n);
    return min;
}
int main(){

    int n;
    int heap[Max];
    int ele;
    int min;
    printf("\n Enter the size of the heap:  ");
    scanf("%d", &n);
    printf("\n Enter the elements : ");
    for(int i=0;i<n;i++)
        scanf("%d", &heap[i]);
    printheap(heap,n);
    build_minheap(heap,n);
    printheap(heap,n);
    printf("\n Insert the element to be inserted: ");
    scanf("%d", &ele);
    insert(heap,ele,&n);
    printheap(heap,n);
    min=delet(heap,&n);
    printf("\n Heap after delete :\n");
    printheap(heap,n);
}
