#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#define MAX 100

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

void bfs(graph *g, int src) {
    printf("In BFS: ");
    int queue[MAX];
    int front = -1;
    int rear = -1;
    int *visited = (int *) malloc(sizeof(int) * g->numVertices);
    for(int i = 0; i < g->numVertices; i++) {
        visited[i] = 0;
    }
    queue[++rear] = src;
    ++front;
    visited[src] = 1;
    printf("In BFS: ");
    int current;
    node *temp = NULL;
    while(front <= rear && rear < MAX) {
        current = queue[front++];
        printf("%d ",current);
        temp = g->adjLists[current];
        while(temp) {
            if(!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[++rear] = temp->data;
            }
            temp = temp->next;
        }
    }
}

void shortestDist(graph *g, int src, int dest) {
    int queue[MAX];
    int front = -1;
    int rear = -1;
    int *visited = (int *) malloc(sizeof(int) * g->numVertices);
    for(int i = 0; i < g->numVertices; i++) {
        visited[i] = 0;
    }
    queue[++rear] = src;
    ++front;
    visited[src] = 1;
    int current;
    node *temp = NULL;
    int *dist = (int *) malloc(sizeof(int) * g->numVertices);
    for(int i = 0; i < g->numVertices; i++) {
        dist[i] = -1;
    }
    dist[src] = 0;
    while(front <= rear && rear < MAX) {
        current = queue[front++];
        temp = g->adjLists[current];
        while(temp) {
            if(!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[++rear] = temp->data;
                dist[temp->data] = dist[current] + 1;
            }
            temp = temp->next;
        }
    }
    printf("Shortest distance between %d and %d is %d\n", src, dest, dist[dest]);
}

int main()
{
    graph *g = (graph *) malloc(sizeof(graph));
    initGraph(g, 4);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 4);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);
    addEdge(g, 3, 4);
    for(int i = 0; i < g->numVertices; i++) {
        node *temp = g->adjLists[i];
        printf("Adjacency list of vertex %d is: ", i);
        while(temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    bfs(g, 0);
    shortestDist(g, 0, 4);
    return 0;
}