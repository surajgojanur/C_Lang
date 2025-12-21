#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
	int numVertices;
	int **adjMatrix;
}Graph;

void CreateGraph(Graph *g,int vertices){
	g->numVertices=vertices;
	g->adjMatrix=malloc(vertices*sizeof(int *));

	if(g->adjMatrix == NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	// for(int i=0;i<vertices;i++){
    //     g->adjMatrix[i]=calloc(vertices, sizeof(int));
    // }
    
	//initialzing to the 0
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			g->adjMatrix[i][j]=0;
		}
	}
}

void printGraph(Graph *g){
	printf("The adjency Matrix is\n");

	for(int i=0;i<g->numVertices;i++){
		for(int j=0;j<g->numVertices;j++){
			printf("%d ",g->adjMatrix[i][j]);
		}
		printf("\n");
	}
}

void addEdge(Graph *g,int src,int dest){
	if(src >= 0 && src < g->numVertices && dest >=0 && dest < g->numVertices){
	g->adjMatrix[src][dest]=1;
	g->adjMatrix[dest][src]=1;
	}else{
	printf("Invalid Edges (%d %d)\n",src,dest);
	}
}

void freeGraph(Graph *g){
	for(int i=0;i<g->numVertices;i++){
		free(g->adjMatrix[i]);
	}
	free(g->adjMatrix);
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

int main(){
	Graph g;
	int vertices,edges;

	printf("enter the number of vertices : ");
	scanf("%d",&vertices);

	CreateGraph(&g,vertices);
	

	printf("Enter the nummber of edges : ");
	scanf("%d",&edges);
	printGraph(&g);
	for(int i=0;i<edges;i++){
		int u,v;
		printf("Enter the edges %d(u,v)",i+1);
		scanf("%d %d",&u,&v);

		addEdge(&g,u,v);
	}
	printGraph(&g);

    int start;
    printf("Enter the start vertex for DFS: ");
    scanf("%d", &start);

    bool *visited = calloc(vertices, sizeof(bool));
    if (!visited) {
        printf("Memory allocation failed\n");
        freeGraph(&g);
        return 1;
    }

    if (start >= 0 && start < vertices) {
        printf("DFS traversal: ");
        dfs(g.adjMatrix, visited, start, vertices);
        printf("NULL\n");
    } else {
        printf("Invalid start vertex\n");
    }

    free(visited);
    freeGraph(&g);
    return 0;
}
