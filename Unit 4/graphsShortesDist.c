// to find shortest distance between two nodes in a graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#define MAX_NODES 50

struct node {
    int vertex;
    struct node* next;
};
typedef struct node node;

struct graph {
    int numVertices;
    node** adjLists;
    int* visited;
};
typedef struct graph graph;

struct queue {
    int *nodes;
    int front;
    int rear;
};
typedef struct queue queue;

void initQueue(queue *q) {
    q->nodes = (int *) malloc(sizeof(int)*MAX_NODES);
    q->front = -1;
    q->rear = -1;
}

void enqueue(queue *q,int info) {
    if(q->rear == MAX_NODES-1) {
        printf("Queue is full!");
    } else {
        if(q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->nodes[q->rear] = info;
    }
}

int dequeue(queue *q) {
    if(q->front == -1) {
        printf("Queue is Empty!");
        exit(0);
    }
    int info = q->nodes[q->front];
    q->front++;
    if(q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return info;
}

int isEmptyQ(queue *q) {
    return q->front == -1;
}

void createGraph(graph *g) {
    g->adjLists = (node **) malloc(g->numVertices * sizeof(node*));
    g->visited = (int *) malloc(g->numVertices * sizeof(int));
    for(int i = 0;i < g->numVertices;i++) {
        g->adjLists[i] = NULL;
        g->visited[i] = 0;
    };
}

node *createNode(int vertex) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(graph *g,int src,int dest) {
    // directed graph;
    node *temp = createNode(dest);
    temp->next = g->adjLists[src];
    g->adjLists[src] = temp;
}

int shortestDist(graph *g,int src,int dest) {
    queue bfsq;
    initQueue(&bfsq);

    int *dist = (int *) malloc(g->numVertices * sizeof(int));
    for(int i = 0;i < g->numVertices;i++) {
        dist[i] = -1;
    }
    g->visited[src] = 1;
    dist[src] = 0;
    node *temp = NULL;
    enqueue(&bfsq,src);
    while(!isEmptyQ(&bfsq)) {
        int currentVertex = dequeue(&bfsq);
        temp = g->adjLists[currentVertex];
        while(temp) {
            if(!g->visited[temp->vertex]) {
                g->visited[temp->vertex] = 1;
                dist[temp->vertex] = dist[currentVertex] + 1;
                enqueue(&bfsq,temp->vertex);
            }
            temp = temp->next;
        }
    }
    return dist[dest];
}

int main()
{
    graph g;
    scanf("%d",&g.numVertices);
    createGraph(&g);
    int src,dest;
    scanf("%d %d",&src,&dest);
    while(src != -1 && dest != -1) {
        addEdge(&g,src,dest);
        scanf("%d %d",&src,&dest);
    }
    scanf("%d %d",&src,&dest);
    printf("shortest distance between %d and %d is %d\n",src,dest,shortestDist(&g,src,dest));
    return 0;
}