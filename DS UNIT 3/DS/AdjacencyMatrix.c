#include<stdio.h>
#include<stdlib.h>
int main(){
	int V , E;
	int u, v;

	printf("Enter number of vertices : ");
	scanf("%d", &V);

	printf("Enter number of edges : ");
	scanf("%d", &E);

	int adjMatrix[V][V];

	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			adjMatrix[i][j]=0;
		}
	}
	printf("Enter the edges (pairs of vertices u v):\n");
	for(int i=0;i<E;i++){
		scanf("%d %d",&u,&v);
		adjMatrix[u][v]=1;
	}

	printf("\n Adjacency Matrix : \n");
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			printf("%d ",adjMatrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
