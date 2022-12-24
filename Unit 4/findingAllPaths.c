// print all paths from source to destination
// using backtracking
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int vertex;
    struct node *next;
};
typedef struct node node;

node adjNodes[10];
int pathCount = 0;

node *insertRear(node *head,int vertex) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    if(head == NULL) {
        return newNode;
    }
    node *cur = head;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
    return head;
}

void readAdjList(node *adjNodes,int n) {
    for(int i = 0;i < n;i++) {
        printf("Enter the number of nodes adjacent to %d: ",i);
        int adjCount;
        scanf("%d",&adjCount);
        node *temp = &adjNodes[i];
        for(int j = 0;j < adjCount;j++) {
            printf("Enter the node adjacent to %d: ",i);
            int adjNode;
            scanf("%d",&adjNode);
            temp = insertRear(temp,adjNode);
        }
    }
}

void printAll(int src,int dest,int visited[10],int path[10]) {
    visited[src] = 1;
    path[pathCount++] = src;
    if(src == dest) {
        for(int i = 0;i < pathCount;i++) {
            printf("%d ",path[i]);
        }
        printf("\n");
    }
    else {
        node *cur = adjNodes[src].next;
        while(cur != NULL) {
            if(visited[cur->vertex] == 0) {
                printAll(cur->vertex,dest,visited,path);
            }
            cur = cur->next;
        }
    }
    pathCount--;
    visited[src] = 0;
}

void printPaths(node *adjNodes,int src,int dest,int n) {
    int visited[10];
    int path[10];
    for(int i = 0; i < n;i++) {
        visited[i] = 0;
    }
    printAll(src,dest,visited,path);
}

int main() {
    int i,src,dest,n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the adjacency list: ");
    readAdjList(adjNodes,n);
    printf("Enter the source and destination: ");
    scanf("%d %d",&src,&dest);
    printPaths(adjNodes,src,dest,n);
    return 0;
}
