#include <stdio.h> 
#include <stdlib.h> 

#define MAXSIZE 10 // Maximum capacity of the queue [3]

// Structure definition for the Circular Queue ADT
typedef struct {
    int items[MAXSIZE]; // Array to store elements [3]
    int front, rear;    // Pointers to the front and rear indices [3]
} CircularQueue; 

// Function Prototypes
void InitializeQueue(CircularQueue *q);
int IsEmpty(CircularQueue *q);
int IsFull(CircularQueue *q);
void Enqueue(CircularQueue *q, int element);
int Dequeue(CircularQueue *q);
void DisplayQueue(CircularQueue *q);

/**
 * Initializes the circular queue by setting front and rear to -1.
 */
void InitializeQueue(CircularQueue *q) {
    q->front = -1; 
    q->rear = -1; // [3]
}

/**
 * Checks if the queue is empty.
 * Returns 1 (True) if empty, 0 (False) otherwise.
 * The queue is empty when front is -1.
 */
int IsEmpty(CircularQueue *q) {
    return (q->front == -1); // [3]
}

/**
 * Checks if the queue is full (Overflow condition).
 * Returns 1 (True) if full, 0 (False) otherwise.
 * Uses the definition: (rear + 1) % MAXSIZE == front.
 */
int IsFull(CircularQueue *q) {
    // Check: (rear + 1) modulo MAXSIZE == front [3]
    return ((q->rear + 1) % MAXSIZE == q->front); // [3]
}

/**
 * Adds an element (Enqueue operation) at the rear of the queue.
 */
void Enqueue(CircularQueue *q, int element) {
    
    if (IsFull(q)) {
        printf("\n\t Queue is full! Cannot enqueue %d\n", element); // [3] (implied overflow check)
        return;
    }
    
    // If the queue was empty, set front to 0 [3] (Initialization logic)
    if (q->front == -1) 
        q->front = 0; 

    // Calculate new rear position circularly: rear -> (rear+1)%N [4]
    q->rear = (q->rear + 1) % MAXSIZE; 

    // Insert the element
    q->items[q->rear] = element; 
    printf("\n\t Enqueued %d\n", element);
}

/**
 * Removes and returns the element at the front of the queue (Dequeue operation).
 * Returns the element on success, or -1 on failure (underflow).
 */
int Dequeue(CircularQueue *q) { // [5]
    int element;
    
    if (IsEmpty(q)) {
        printf("\n\t Queue is empty! Cannot dequeue\n"); // [5]
        return -1; // [5]
    } 
    
    // Store the element to be deleted (at front index)
    element = q->items[q->front]; // [5]

    // Check if this is the last element in the queue
    if (q->front == q->rear) { 
        // If only one element was present, reset queue to empty state
        q->front = -1;
        q->rear = -1; // [5]
    } else {
        // Move front pointer circularly to the next position: front -> (front + 1) % MAXSIZE
        q->front = (q->front + 1) % MAXSIZE; // [5]
    }
    
    printf("\n\t Dequeued %d\n", element); 
    return element; // [6]
}

/**
 * Displays all elements in the queue from front to rear.
 */
void DisplayQueue(CircularQueue *q) { // [7]
    int i;
    
    if (IsEmpty(q)) {
        printf("\n\t Queue is empty!\n"); // [7]
        return;
    }
    
    printf("\n\t Queue elements: "); 
    i = q->front;
    
    // Loop starting at front and continuing until i wraps back to rear (inclusive) [8]
    while (i != q->rear) { 
        printf("%d ", q->items[i]);
        i = (i + 1) % MAXSIZE; // Circular advancement [8]
    }
    // Print the last element (which is at q->rear) [8]
    printf("%d\n", q->items[i]); 
}


int main(void) {
    CircularQueue q; // [9]
    int choice, element;
    
    // Initialize the queue structure
    InitializeQueue(&q); // [3]

    printf("\n*** Circular Queue Operations (MAX SIZE %d) ***\n", MAXSIZE);
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

    do {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) {
            // Error handling for non-integer input (not explicitly in source, but good practice)
            while(getchar() != '\n'); 
            choice = 0; 
        }

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                Enqueue(&q, element);
                break;
            case 2:
                Dequeue(&q); // [9]
                break;
            case 3:
                DisplayQueue(&q); // [9]
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}