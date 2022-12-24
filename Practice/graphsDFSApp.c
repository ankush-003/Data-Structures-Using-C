#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct graph {
    int numVertices;
    node **adjLists;
} graph;

void initGraph(graph *g, int numVertices) {
    g->numVertices = numVertices;
    g->adjLists = (node **) malloc(numVertices * sizeof(node *));
    for(int i = 0; i < numVertices; i++) {
        g->adjLists[i] = NULL;
    }
}

void addEdge(graph *g, int src, int dest) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = dest;
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
    // addEdge(g, dest, src);
    newNode = (node *) malloc(sizeof(node));
    newNode->data = src;
    newNode->next = g->adjLists[dest];
}

void dfs_helper(graph *g, int src, int *visited) {
    visited[src] = 1;
    printf("%d ",src);
    node *temp = g->adjLists[src];
    while(temp) {
        if(!visited[temp->data]) {
            dfs_helper(g, temp->data, visited);
        }
        temp = temp->next;
    }
}

void dfs(graph *g, int src) {
    int *visited = (int *) malloc(sizeof(int) * g->numVertices);
    for(int i = 0; i < g->numVertices; i++) {
        visited[i] = 0;
    }
    printf("DFS: ");
    dfs_helper(g, src, visited);
    printf("\n");
}

int isCyclic(graph *g, int *visited, int parent, int current) {
    visited[current] = 1;
    node *temp = g->adjLists[current];
    while(temp) {
        if(!visited[temp->data]) {
            if(isCyclic(g, visited, current, temp->data)) {
                return 1;
            }
        } else if(temp->data != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void cycle_finder(graph *g) {
    int *visited = (int *) malloc(g->numVertices * sizeof(int));
    for(int i = 0; i < g->numVertices; i++) {
        visited[i] = 0;
    }
    for(int i = 0; i < g->numVertices; i++) {
        if(!visited[i]) {
            if(isCyclic(g, visited, -1, i)) {
                printf("Cycle Found!\n");
                return;
            }
        }
    }
}

void printPaths_helper(graph *g, int src, int dest, int *visited, int *path, int count) {
    path[count] = src;
    (count)++;
    visited[src] = 1;
    if(src == dest) {
        printf("\n Path Length: %d \n",count);
        for(int i = 0; i <= count; i++) {
            printf("%d ",path[i]);
        }
        printf("\n");
    } else {
        for(node *temp = g->adjLists[src];temp;temp = temp->next) {
            if(!visited[temp->data]) {
                printPaths_helper(g, temp->data, dest, visited, path, count);
            }
        }
    }
    // removing the current node
    // (*count)--;
    visited[src] = 0;
}

void printPaths(graph *g, int src, int dest) {
    int *visited = (int *) malloc(sizeof(int) * g->numVertices);
    for(int i = 0; i < g->numVertices; i++) {
        visited[i] = 0;
    }
    int count = 0;
    int *path = (int *) malloc(sizeof(int) * g->numVertices);
    printf("Paths: ");
    printPaths_helper(g, src, dest, visited, path, count);
}


int main()
{
    graph *g = (graph *) malloc(sizeof(graph));
    initGraph(g, 6);
    // addEdge(g, 0, 1);
    // addEdge(g, 0, 2);
    // addEdge(g, 1, 2);
    // addEdge(g, 2, 3);
    // addEdge(g, 3, 4);
    // addEdge(g, 4, 5);
    // addEdge(g, 5, 3);
    addEdge(g, 0, 1);
    addEdge(g,1,2);
    addEdge(g,2,3);
    addEdge(g,3,4);
    addEdge(g,4,5);
    // addEdge(g,5,0);
    dfs(g, 0);
    printPaths(g, 0, 5);
    cycle_finder(g);
    return 0;
}