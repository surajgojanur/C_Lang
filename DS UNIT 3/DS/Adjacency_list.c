#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int vertex;
	strict Node *next;
}Node;

typedef struct{
	int numVertices;
	Node **adjList;
}Graph;

Node *createNode(int v){
	Node *newNode=malloc(sizeof(Node));
	newNode->vertex=v;
	newNode->next=NULL;
	return newNode;
}

void createGraph(Graph *g,int vertices){
	g->numVertices=vertices;
	g->adjList=malloc(vertices*sizeof(Node*));
	for(int i=0;i<vertices;i++){
		g->adjList[i]=NULL;
	}
}

void addEdge(Graph *g,int src,int dest){
	Node *newNode=createNode(dest);
	newNode->next=g->adjList[src];
	g->adjList[src]=newNode;

	newNode=createNode(src);
	newNode->next=g->adjList[dest];
	g->adjList[dest]=newNode;
}

void printGraph(Graph *g){
	for(int i=0;i<g->numVertices;i++){
		printf("Vertex %d",i);
		
		Node *temp=g->adjList[i];
		while(temp!=NULL){
			printf(" ->%d",temp->vertex);
			temp=temp->next;
		}printf("NULL \n");
	}
}
