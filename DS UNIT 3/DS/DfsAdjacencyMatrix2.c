#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* -------- Graph Structure -------- */
typedef struct Graph
{
    int numVertices;
    int **adjMatrix;
} Graph;

/* -------- Create Graph -------- */
void createGraph(Graph *g, int V)
{
    g->numVertices = V;

    g->adjMatrix = (int **)malloc(V * sizeof(int *));
    if (g->adjMatrix == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < V; i++)
    {
        g->adjMatrix[i] = (int *)malloc(V * sizeof(int));
        if (g->adjMatrix[i] == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }

        for (int j = 0; j < V; j++)
            g->adjMatrix[i][j] = 0;
    }
}

/* -------- Insert Edge (Undirected) -------- */
void insertEdge(Graph *g, int src, int dest)
{
    if (src < 0 || dest < 0 || src >= g->numVertices || dest >= g->numVertices)
    {
        printf("Invalid edge (%d, %d)\n", src, dest);
        return;
    }

    if (src == dest)
    {
        printf("Self-loops not allowed (%d, %d)\n", src, dest);
        return;
    }

    if (g->adjMatrix[src][dest] == 1)
    {
        printf("Edge already exists (%d, %d)\n", src, dest);
        return;
    }

    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

/* -------- Print Graph -------- */
void printGraph(Graph *g)
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < g->numVertices; i++)
    {
        for (int j = 0; j < g->numVertices; j++)
            printf("%d ", g->adjMatrix[i][j]);
        printf("\n");
    }
}

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

/* -------- Free Graph -------- */
void freeGraph(Graph *g)
{
    for (int i = 0; i < g->numVertices; i++)
        free(g->adjMatrix[i]);

    free(g->adjMatrix);
}

/* -------- Main -------- */
int main()
{
    int V, E;
    int src, dest;
    Graph g;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    if (V <= 0)
    {
        printf("Invalid number of vertices\n");
        return 0;
    }

    createGraph(&g, V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++)
    {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        insertEdge(&g, src, dest);
    }

    printGraph(&g);
    dfs(&g);
    freeGraph(&g);

    return 0;
}
