#include<stdlib.h>
#include<stdio.h>

/*edge list structure for each edge */
typedef struct{
    unsigned int first;
    unsigned int second;
}edge;

struct node {
  int vertex;
  struct node* next;
};
typedef struct node node;

struct graph {
    int numVertices;
    int *visited;
    node **adjLists;
};
typedef struct graph graph;

void createGraph(graph* g,edge *edges,int numVertices,int numEdges) {
    int i;
    g->numVertices = numVertices;
    g->adjLists = malloc(numVertices * sizeof(node*));
    g->visited = malloc(numVertices * sizeof(int));

    for (i = 0; i < numVertices; i++) {
        g->adjLists[i] = NULL;
        g->visited[i] = 0;
    }

    for (i = 0; i < numEdges; i++) {
        int src = edges[i].first;
        int dest = edges[i].second;

        // Insert at the beginning
        node* newNode = malloc(sizeof(node));
        newNode->vertex = dest;
        newNode->next = g->adjLists[src];
        g->adjLists[src] = newNode;

        // Insert at the beginning
        newNode = malloc(sizeof(node));
        newNode->vertex = src;
        newNode->next = g->adjLists[dest];
        g->adjLists[dest] = newNode;
    }
}

static int isCyclic(int current,graph *g,int parent) {
    g->visited[current] = 1;
    node* temp = g->adjLists[current];
    int isCycle = 0;
    while (temp && !isCycle) {
        int adjVertex = temp->vertex;
        if (g->visited[adjVertex] == 0) {
            if (isCyclic(adjVertex,g,current)) {
                isCycle = 1;
            }
        } else if (adjVertex != parent) {
            isCycle = 1;
        }
        temp = temp->next;
    }
    return isCycle;
}

unsigned int cycle_finder(edge *edges , unsigned int n, unsigned int order)
{
    // to find the cycle in the graph
    graph g;
    createGraph(&g,edges,order,n);
    int i;
    for (i = 0; i < order; i++) {
        if (g.visited[i] == 0) {
            if (isCyclic(i,&g,-1)) {
                return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    unsigned int order;  /* number of vertices */
    unsigned int n; /* number of edges */
    scanf("%d", &n);
    scanf("%d", &order);
    edge *edges;
    unsigned int ans;
    edges = malloc(n*sizeof(edge));
    if(edges==NULL)
    {
        return 1;
    }
    for(int i=0;i<n;++i)
    {
        scanf("%d", &edges[i].first);
        scanf("%d", &edges[i].second);
    }
        
    ans= cycle_finder(edges, n, order);
    printf(ans? "cyclic":"acyclic");
    free(edges);
    return 0;

}
