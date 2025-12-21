#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

// TO insert element into the queue
void enqueue(int vertex)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

// Function to delete element from the queue
int dequeue()
{
    int delete_item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        delete_item = queue[front];
        front++;
        return delete_item;
    }
}

int isQueueEmpty()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    else
        return 0;
}

void BFS(int adjMatrix[MAX][MAX], int visited[MAX], int startNode, int V)
{
    enqueue(startNode);
    visited[startNode] = 1;

    printf("BFS Traversal");
    while (!isQueueEmpty())
    {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 1; i <= V; i++)
        {
            if (adjMatrix[current - 1][i - 1] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main()
{
    int V, E, u, v, startNode;
    int adjMatrix[MAX][MAX];
    int visited[MAX];

    printf("Enter the number of vertices:");
    scanf("%d", &V);
    printf("Enter the numner of Edge");
    scanf("%d", &E);

    for (int i = 0; i < V; i++)
    {
        visited[i + 1] = 0;
        for (int j = 0; j < V; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    // Input Edge
    printf("Enter edges ( u ,v ) :\n ");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        adjMatrix[u - 1][v - 1] = 1;
        adjMatrix[v - 1][u - 1] = 1;
    }

    printf("Enter Starting vertex for BFS: ");
    scanf("%d", &startNode);

    BFS(adjMatrix, visited, startNode, V);

    return 0;
}