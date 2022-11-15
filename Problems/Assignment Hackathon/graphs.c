#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#define MAX 100
struct node {
    int vertex;
    struct node *next;
};
typedef struct node node;

struct queue {
  int items[MAX];
  int front;
  int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);

struct graph {
    int *visited;
    node **adjList;
    int numVertices;
};
typedef struct graph graph;

void initGraph(graph *g, int numVertices) {
    g->numVertices = numVertices;
    g->adjList = malloc(numVertices * sizeof(node *));
    g->visited = malloc(numVertices * sizeof(int));
    int i;
    for (i = 0; i < numVertices; i++) {
        g->adjList[i] = NULL;
        g->visited[i] = 0;
    }
}

void addEdge(graph *g, int src, int dest) {
    node *newNode = malloc(sizeof(node));
    newNode->vertex = dest;
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;

    newNode = malloc(sizeof(node));
    newNode->vertex = src;
    newNode->next = g->adjList[dest];
    g->adjList[dest] = newNode;
}

void printGraph(graph *gptr) {
    node *temp = NULL;
    for (int i = 0; i < gptr->numVertices; i++)
    {
        printf(" %d: ", i);
        temp = gptr->adjList[i];
        while (temp != NULL)
        {
            printf(" %d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void dfsGraph(graph *gptr,int src) {
    node *temp = NULL;
    gptr->visited[src] = 1;
    printf(" %d-> ",src);
    temp = gptr->adjList[src];
    while (temp != NULL)
    {
        if (gptr->visited[temp->vertex] == 0)
        {
            dfsGraph(gptr,temp->vertex);
        }
        temp = temp->next;
    }
}

void bfs(graph* graph, int startVertex) {
  struct queue* q = createQueue();
  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    // printQueue(q);
    int currentVertex = dequeue(q);
    printf("Visited %d\n", currentVertex);

    node* temp = graph->adjList[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}

int main()
{
    graph *gptr = malloc(sizeof(graph));
    initGraph(gptr, 5);
    addEdge(gptr, 0, 1);
    addEdge(gptr, 0, 4);
    addEdge(gptr, 1, 2);
    addEdge(gptr, 1, 3);
    addEdge(gptr, 1, 4);
    addEdge(gptr, 2, 3);
    addEdge(gptr, 3, 4);
    printGraph(gptr);
    printf("Graph DFS: ");
    dfsGraph(gptr,0);
    printf("Graph BFS: ");
    bfs(gptr,0);
    return 0;
}

struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
  if (q->rear == MAX - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}
