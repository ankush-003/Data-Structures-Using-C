#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#define MAX 20


void dfs(int adjmatrix[][MAX], int visited[], int src, int n)
{
    visited[src] = 1;
    printf(" %d-- ", src);
    for (int i = 0; i < n; i++)
    {
        if (adjmatrix[src][i] == 1 && visited[i] == 0)
        {
            dfs(adjmatrix,visited,i,n);
        }
    }
}

int numComponents(int vertex,int **adjMatrix,int n,int *visited,int compid) {
    int i;
    visited[vertex] = compid;
    printf(" %d-- belongs to component %d ", vertex, compid);
    for (i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && visited[i] == 0) {
            numComponents(i,adjMatrix,n,visited,compid);
        }
    }

}

int components(int **adjmat,int n,int *visited) {
    int i = 0;
    for(i=0;i < n;i++) {
        visited[i] = 0;
    }
    int compid = 1;
    for(i = 0; i < n;i++) {
        if(visited[i] == 0) {
            numComponents(i,adjmat,n,visited,compid);
            compid++;
        }
    }
    return compid - 1;
}

int main()
{
    int n;
    int adjmatrix[MAX][MAX];
    int visited[MAX];
    int i,j;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&adjmatrix[i][j]);
        }
        visited[i]=0;
    }
    int src = 0;
    dfs(adjmatrix,visited,src,n);
    return 0;
}