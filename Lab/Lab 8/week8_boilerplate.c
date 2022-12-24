
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 50
#define INFINITY 9999

typedef struct graph {
int n; /* Number of vertices in graph */
int adj[MAX_NODES][MAX_NODES]; /* Adjacency matrix */
} Graph;

//creates the graph
void create_graph(Graph * adj_mat)
    {
        
        int i, j;
        for (int i = 0; i < adj_mat->n; ++i)
        {
            for (int j = 0; j < adj_mat->n; ++j)
            {
                adj_mat->adj[i][j] = 0;
            }
        }
        while (1)
        {
            //edge between two vertex
            scanf("%d %d\n", &i, &j);
            if (i < 0 && j <= 0 || i >= adj_mat->n || j >= adj_mat->n)
            {
                break;
            }
            adj_mat->adj[i][j] = 1;
        }
    }
//helper functions for inserting an element into a queue 
void append(int *queue, int v, int *pqr)
{
    ++(*pqr);
    queue[*pqr] = v;
}
//helper function to delete from a queue 
int delete (int *queue, int *pqr)
{
    int res = queue[0];
    for (int i = 0; i < *pqr; ++i)
    {
        queue[i] = queue[i + 1];
    }
    --(*pqr);
    return res;
}

//bfs function to calculate the minimum distance 
//You are required to complete this function
int find_dist(Graph * adj_mat, int source, int dest)
{
    int queue[MAX_NODES];
    int pqr = -1;
    int visited[MAX_NODES];
    int dist[MAX_NODES];
    for (int i = 0; i < adj_mat->n; ++i)
    {
        visited[i] = 0;
        dist[i] = -1;
    }
    append(queue, source, &pqr);
    visited[source] = 1;
    dist[source] = 0;
    while (pqr != -1)
    {
        int v = delete (queue, &pqr);
        for (int i = 0; i < adj_mat->n; ++i)
        {
            if (adj_mat->adj[v][i] == 1 && visited[i] == 0)
            {
                append(queue, i, &pqr);
                visited[i] = 1;
                dist[i] = dist[v] + 1;
            }
        }
    }
    return dist[dest];
}

int main()
{
    Graph adj_mat;

    int source, dest;

    //number of vertex
    scanf("%d\n", &adj_mat.n);
    // creates adj matrix
    create_graph(&adj_mat);

    //source vertex
    scanf("%d\n", &source);

    //destination vertex
    scanf("%d", &dest);
    
    int result = find_dist(&adj_mat, source, dest);
    printf("%d",result);
    return 0;
}