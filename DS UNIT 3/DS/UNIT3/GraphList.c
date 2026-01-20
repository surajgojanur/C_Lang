#include<stdio.h>
#include<stdlib.h>

typedef struct AdjNode
{
    int dest;
    struct AdjNode* next;
}*NODE;

typedef struct Adj{
    NODE head;
} *LIST;

typedef struct myGraph{
    int numVertices;
    LIST array;
}*Graph;

NODE newAdjNode(int dest){
    NODE newNode=(NODE)malloc(sizeof(struct AdjNode));
    newNode->dest=dest;
    newNode->next=NULL;
    return newNode;
}

Graph createGraph(int V){
    Graph graph = (Graph)malloc(sizeof(struct myGraph));
    graph->numVertices=V;
}
