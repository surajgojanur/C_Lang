#include<stdio.h>
#include<stdlib.h>

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
	for(int i=0;i<vertices;i++){
		g->adjMatrix[i]=calloc(vertices,vertices*sizeof(int));
	}
	//initialzing to the 0
//	for(int i=0;i<vertices;i++){
//		for(int j=0;j<vertices;j++){
//			g->adjMatrix[i][j]=0;
//		}
//	}
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
	return 0;
}
