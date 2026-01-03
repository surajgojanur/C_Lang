#include<stdio.h>
#include<stdlib.h>


typedef struct
{
    /* data */
    int numV;
    int **adjMatrix;
}mynode;

void createGraph(mynode *g,int V){
    g->adjMatrix=malloc(sizeof(int *)*V);
    g->numV=V;
    if(g->adjMatrix==NULL){
        printf("out of memroy");
        exit(1);
    }
    for(int i=0;i<V;i++){
        g->adjMatrix[i]=malloc(sizeof(int)*V);
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            g->adjMatrix[i][j]=0;
    }
    }
    return;
}

void dfs(int **adjMatrix,int V,int sv,int *visited){
    printf("%d ",sv);
    visited[sv]=1;
    for(int i=0;i<V;i++){
        if(adjMatrix[sv][i]==1 && visited[i]==0){
            dfs(adjMatrix,V,i,visited);
        }
    }
}

void insertGraph(mynode *g,int src,int dest){
    if(src < g->numV && dest < g->numV && dest >=0 && src >= 0){
    g->adjMatrix[src][dest]=1;
    g->adjMatrix[dest][src]=1;
    }else{
        printf("Error");
        exit(1);
    }
    
}

void printGraph(mynode *g){
    if(g==NULL)
    printf("Empty Graph");
    for(int i=0;i<g->numV;i++){
        for(int j=0;j<g->numV;j++){
            printf("%d",g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(mynode *g){
    if(g==NULL)
    printf("Empty Graph");
    for(int i=0;i<g->numV;i++){
        
            free(g->adjMatrix[i]);
        
        
    }
    free(g->adjMatrix);
}



int main(){
    int u,v,E,V;
    mynode g;
    printf("Enter no of Verties");
    scanf("%d",&V);
    createGraph(&g,V);
    printf("Enter no of Edges");
    scanf("%d",&E);
    printGraph(&g);
    for(int i=0;i<E;i++){
        scanf("%d %d",&u,&v);
        insertGraph(&g,u,v);
    }
    printGraph(&g);

    printf("\n\nDFS");
    
    int *visited = calloc(V, sizeof(int));

    for(int i=0;i<V;i++){
        
            if(visited[i]==0){
                dfs(g.adjMatrix,V,i,visited);
                
        
        }
    }
    freeGraph(&g);
}