// Helps in finding the shortest path between two nodes in a graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

struct queue {
    int front;
    int rear;
    int items[MAX];
}



void bfs(int adjmat[][MAX],int visited[],int src,int n){
    Queue q;
    int ele;
    initq(&q,src);
    visited[src] = 1;
    enqueue(&q,src);
    while(!isEmpty(&q)) {
        ele = dequeue(&q);
        for(int i = 0;i < n;i++) {
            if(adjmat[ele][i] == 1 && visited[i]==0) {
                enqueue(&q,i);
            }

        }
    }
}

int main()
{
    // Code
    return 0;
}