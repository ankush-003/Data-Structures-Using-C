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