#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int front=-1,rear=-1,queue[MAX];
int dequeue();
void enqueue(int n);
int isEmpty();
void BFS(int visited[],int node,);

void enqueue(int n){
    if(front > rear || rear> MAX-1){
        printf("Stack OverFlow!!");
        return;
    }
    if(front == -1) front++;
    queue[front]=n;
}

int dequeue(){
    if(front == -1 || front > rear){
        printf("UnderFlow !!");
        return -1;
    }
    return queue[front++];
}

int isEmpty(){
    if(front == -1 || front>rear){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int V,E,u,v;
    int visited[MAX];
    int adjMatrix[MAX][MAX];
    printf("Enter the Vertices count");
    scanf("%d",&V);

    printf("Enter the Edges count");
    scanf("%d",&E);

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            adjMatrix[i][j]=0;
        }
    }

    
}