#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Create graph using adjacency matrix */
int **createGraph(int V)
{
    int **adjMatrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        adjMatrix[i] = (int *)malloc(V * sizeof(int));
    }

    /* Initialize matrix to 0 */
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    return adjMatrix;
}

/* Print graph */
void printGraph(int **adjMatrix, int V)
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

/* DFS traversal */
void dfs(int **adjMatrix, bool *visited, int node, int V)
{
    visited[node] = true;
    printf("%d->", node);

    for (int neighbor = 0; neighbor < V; neighbor++)
    {
        if (adjMatrix[node][neighbor] == 1 && !visited[neighbor])
        {
            dfs(adjMatrix, visited, neighbor, V);
        }
    }
}

/* Free graph memory */
void freeGraph(int **adjMatrix, int V)
{
    for (int i = 0; i < V; i++)
    {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}

int main()
{
    int V, E;
    int u, v;

    printf("Enter number of vertices : ");
    scanf("%d", &V);

    printf("Enter number of edges : ");
    scanf("%d", &E);

    int **adjMatrix = createGraph(V);

    bool *visited = (bool *)malloc(V * sizeof(bool));
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    printf("Enter the edges (pairs of vertices u v):\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;        // directed graph
        // adjMatrix[v][u] = 1;     // uncomment for undirected
    }

    printGraph(adjMatrix, V);

    int startNode = 0;
    printf("\nDFS Traversal starting from %d : ", startNode);
    dfs(adjMatrix, visited, startNode, V);
    printf("\n");

    freeGraph(adjMatrix, V);
    free(visited);

    return 0;
}
