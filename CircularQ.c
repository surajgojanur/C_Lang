#include <stdio.h>

#define MAXSIZE 5

typedef struct {
    int items[MAXSIZE];
    int front;
    int rear;
} CircularQueue;

void InitializeQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int IsEmpty(CircularQueue *q) {
    return (q->front == -1);
}

int IsFull(CircularQueue *q) {
    return ((q->rear + 1) % MAXSIZE == q->front);
}

void Enqueue(CircularQueue *q, int element) {
    if (IsFull(q)) {
        printf("\nQueue is full! Cannot insert %d\n", element);
        return;
    }
    if (IsEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAXSIZE;
    q->items[q->rear] = element;
    printf("\nEnqueued %d\n", element);
}

int Dequeue(CircularQueue *q) {
    if (IsEmpty(q)) {
        printf("\nQueue is empty! Cannot dequeue.\n");
        return -1;
    }
    int element = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;  // Queue becomes empty after this dequeue
    } else {
        q->front = (q->front + 1) % MAXSIZE;
    }
    printf("\nDequeued %d\n", element);
    return element;
}

void DisplayQueue(CircularQueue *q) {
    if (IsEmpty(q)) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nQueue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("%d\n", q->items[q->rear]);  // Print the rear element
}

int main() {
    CircularQueue q;
    int choice, element;

    InitializeQueue(&q);

    do {
        printf("\nCircular Queue Operations using Array and Structures (Max Size: %d)", MAXSIZE);
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to insert: ");
                scanf("%d", &element);
                Enqueue(&q, element);
                break;
            case 2:
                Dequeue(&q);
                break;
            case 3:
                DisplayQueue(&q);
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

