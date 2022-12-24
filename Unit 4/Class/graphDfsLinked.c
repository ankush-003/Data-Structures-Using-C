#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#define MAX 20

struct gnode
{
    int vertex;
    struct gnode *next;
};
typedef struct gnode gnode;

struct graph {
    int numVertices;
    int *visited;
    gnode **adjLists;
};
typedef struct graph graph;

int isEmpty(gnode *head)
{
    return head == NULL;
}

void initGraph(graph *g, int n)
{
    g->numVertices = n;
    g->adjLists = (gnode **) malloc(n * sizeof(gnode *));
    g->visited = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        g->adjLists[i] = NULL;
        g->visited[i] = 0;
    }
}

void addEdge(graph *gptr, int src, int dest)
{
    // Add edge from src to dest
    gnode *newNode = (gnode *) malloc(sizeof(gnode));
    newNode->vertex = dest;
    newNode->next = gptr->adjLists[src];
    gptr->adjLists[src] = newNode;
    // Add edge from dest to src
    newNode = (gnode *) malloc(sizeof(gnode));
    newNode->vertex = src;
    newNode->next = gptr->adjLists[dest];
    gptr->adjLists[dest] = newNode;
}

void printGraph(graph *gptr) {
    gnode *temp = NULL;
    for (int i = 0; i < gptr->numVertices; i++)
    {
        printf(" %d: ", i);
        temp = gptr->adjLists[i];
        while (temp != NULL)
        {
            printf(" %d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void dfsGraph(graph *gptr,int src) {
    gnode *temp = NULL;
    gptr->visited[src] = 1;
    printf(" %d-> ",src);
    temp = gptr->adjLists[src];
    while (temp != NULL)
    {
        if (gptr->visited[temp->vertex] == 0)
        {
            dfsGraph(gptr,temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n,src,dest,numEdges;
    graph ugraph;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    initGraph(&ugraph, n);
    printf("Enter the number of edges: ");
    scanf("%d",&numEdges);
    for(int i = 0;i < numEdges;i++) {
        printf("Enter the source and destination: ");
        scanf("%d %d",&src,&dest);
        addEdge(&ugraph,src,dest);  
    }
    printGraph(&ugraph);
}