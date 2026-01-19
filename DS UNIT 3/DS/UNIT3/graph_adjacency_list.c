#include <stdio.h>
#include <stdlib.h>

// --- Structure Definitions ---

typedef struct AdjNode {
    int dest;
    struct AdjNode* next;
} *NODE;

typedef struct Adj {
    NODE head;
} *LIST;

typedef struct myGraph {
    int numVertices;
    LIST array;
} *Graph;

// --- Helper Functions ---

// Function to create a new adjacency node
NODE newAdjNode(int dest) {
    NODE newNode = (NODE) malloc(sizeof(struct AdjNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
Graph createGraph(int V) {
    Graph graph = (Graph) malloc(sizeof(struct myGraph));
    graph->numVertices = V;

    // Create an array of adjacency lists
    graph->array = (LIST) malloc(V * sizeof(struct Adj));

    // Initialize each adjacency list as empty by making head NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph graph, int src, int dest) {
    // Add an edge from src to dest. 
    // A new node is added to the adjacency list of src.
    NODE newNode = newAdjNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = newAdjNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(Graph graph) {
    for (int v = 0; v < graph->numVertices; ++v) {
        NODE Curr_Node = graph->array[v].head;
        printf("\nAdjacency list of vertex %d\n head ", v);
        while (Curr_Node) {
            printf("-> %d", Curr_Node->dest);
            Curr_Node = Curr_Node->next;
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void freeGraph(Graph graph) {
    NODE head, temp;
    if (graph) {
        if (graph->array) {
            for (int v = 0; v < graph->numVertices; ++v) {
                head = graph->array[v].head;
                temp = NULL;
                while (head) {
                    temp = head;
                    head = head->next;
                    free(temp);
                }
            }
            free(graph->array);
        }
        free(graph);
    }
}

// --- Main Driver Code ---

int main() {
    int V = 3;
    Graph graph = createGraph(V);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    
    printGraph(graph);
    
    freeGraph(graph);
    
    return 0;
}