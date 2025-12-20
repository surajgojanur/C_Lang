#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int numVertices;
    int **adjMatrix;
}Graph; 


void CreateGraph(Graph *g,int vertices){
    g->numVertices=vertices;
    g->adjMatrix=malloc(vertices * sizeof(int *));

    //allocation of the columns 

    for(int i =0; i<vertices ; i++){
        g->adjMatrix[i]=malloc(vertices * sizeof(int));
    }
    // initialzing to the 0
    for(int i=0; i<vertices;i++){
        for (int j=0;j<vertices;j++){
            g->adjMatrix[i][j]=0;
        }
    }
}

void printGraph(Graph *g){
    printf("The adjency matrix is \n") ;

    for(int i=0;i<g->numVertices;i++){
        for(int j=0;j<g->numVertices;j++){
            printf("%d ",g->adjMatrix[i][j]);
        }
        printf("\n"); 
    }
}

void addEdge(Graph *g,int src,int dest){
    g->adjMatrix[src][dest]=1;
    g->adjMatrix[dest][src]=1; 
} 


int main(){
    Graph g; 
    int vertices,edges; 

    printf("Enter the number of vertices: ");
    scanf("%d",&vertices);

    CreateGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d",&edges);

    for(int i=0;i< edges;i++){
        int u,v;
        printf("Enter the edge %d(u,v) ",i+1);
        scanf("%d %d",&u,&v);

        addEdge(&g,u,v);
    }

    printGraph(&g); 

    return 0;
}
