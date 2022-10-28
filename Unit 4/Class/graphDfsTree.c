#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#define MAX 20

void dfs(int adjmatrix[][MAX], int visited[], int src, int n,int parent)
{
    visited[src] = 1;
    printf(" %d-- ", src);
    for (int i = 0; i < n; i++)
    {
        if(adjmatrix[src][i] == 1 && visited[i]==1 && i!=parent)
        {
            printf("Cyclic Graph\n");
            exit(0);
        }
        if (adjmatrix[src][i] == 1 && visited[i] == 0)
        {
            dfs(adjmatrix,visited,i,n,src);
        }

    }
}


int main()
{
    // Code
    return 0;
}