//
// Created by Kishi Kishore N on 05/12/25.
//
#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int vertices;
    int **adjMatrix;
};

struct Graph* createGraph(int num_vertices);
void addEdge(struct Graph* g, int src , int des);
void printGraph(struct Graph* g);
void freeGraph(struct Graph* g);
void dfs(struct Graph* g);
void dfsUtil(struct Graph* g,int v, int* visited);

int main() {
    int num_vertices =9;
     struct Graph* g=  createGraph(num_vertices);
    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,0,3);
    addEdge(g,1,0);
    addEdge(g,1,4);
    addEdge(g,1,5);
    addEdge(g,2,0);
    addEdge(g,2,3);
    addEdge(g,2,6);
    addEdge(g,3,2);
    addEdge(g,3,0);
    addEdge(g,3,6);
    addEdge(g,3,7);
    addEdge(g,4,1);
    addEdge(g,4,8);
    addEdge(g,5,1);
    addEdge(g,6,2);
    addEdge(g,7,3);
    printGraph(g);
    dfs(g);
    return 0;
}


struct Graph* createGraph(int num_vertices) {
    struct Graph* g = malloc(sizeof( struct Graph));
    if (g!=NULL) {
        g->vertices = num_vertices;

        g->adjMatrix = malloc(num_vertices*sizeof(int*));
        for (int i=0; i<g->vertices; i++) {
            *(g->adjMatrix+i) = malloc(num_vertices*sizeof(int));
            for (int j=0;j<g->vertices; j++) {
                *(*(g->adjMatrix+i)+j) = 0;
            }
        }
        return g;
    }
    return NULL;

}
struct Graph* createGraphleak(int num_vertices) {
    struct Graph* g = malloc(sizeof(struct Graph));
    if (g == NULL) return NULL;

    g->vertices = num_vertices;

    g->adjMatrix = malloc(num_vertices * sizeof(int*));
    if (g->adjMatrix == NULL) {
        free(g);
        return NULL;
    }

    for (int i = 0; i < num_vertices; i++) {
        g->adjMatrix[i] = malloc(num_vertices * sizeof(int));
        if (g->adjMatrix[i] == NULL) {
            // ✅ clean previously allocated rows
            for (int j = 0; j < i; j++)
                free(g->adjMatrix[j]);

            free(g->adjMatrix);
            free(g);
            return NULL;
        }

        for (int j = 0; j < num_vertices; j++)
            g->adjMatrix[i][j] = 0;
    }

    return g;
}

void addEdge(struct Graph* g, int src , int des) {
    g->adjMatrix[src][des] = 1;
    // g->adjMatrix[des][src] = 1;
}


void printGraph(struct Graph* g) {
    int num = g->vertices;

    for (int i=0; i<num; i++) {
        for (int j=0; j<num; j++) {
            printf("%d  ",*(*(g->adjMatrix+i)+j));
        }
        printf("\n");
    }
}

void freeGraph(struct Graph* g) {
    for (int i = 0; i < g->vertices; i++) {
        free(g->adjMatrix[i]);
    }
    free(g->adjMatrix);
    free(g);
}




void dfsUtil(struct Graph* g,int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[v][i] == 1 && !visited[i]) {
            dfsUtil(g, i, visited);
        }
    }
}

void dfs(struct Graph* g) {
    int* visited = (int*)malloc(g->vertices * sizeof(int));

    for (int i = 0; i < g->vertices; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal starting from vertex 0:\n");
    dfsUtil(g, 0, visited);
    printf("\n");

    free(visited);
}