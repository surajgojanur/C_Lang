#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

// Function to create a new node
NODE * getnode(int info) {
    NODE *new = (NODE *)malloc(sizeof(NODE));

    if (new == NULL) {
        printf("Insufficient memory\n");
        exit(1);
    }

    new->data = info;
    new->next = NULL;
    return new;
}

// Insert at rear
void insert_rear(NODE **front, NODE **rear, int info) {
    NODE *ptr = getnode(info);

    if (*front == NULL) {  
        *front = *rear = ptr;
    } else {
        (*rear)->next = ptr;
        *rear = ptr;
    }
}

// Delete from front
int delete_front(NODE **front, NODE **rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    NODE *ptr = *front;
    int item = ptr->data;

    *front = (*front)->next;

    if (*front == NULL) 
        *rear = NULL;

    free(ptr);

    printf("Deleted item: %d\n", item);
    return item;
}

// Insert at front
void insert_front(NODE **front, NODE **rear, int info) {
    NODE *new = getnode(info);

    new->next = *front;
    *front = new;

    if (*rear == NULL)
        *rear = new;
}

// Delete from rear
int delete_rear(NODE **front, NODE **rear) {
    if (*front == NULL) {
        printf("Empty list\n");
        return -1;
    }

    NODE *ptr = *front;
    NODE *prevptr = NULL;
    int item;

    if (ptr->next == NULL) {  
        item = ptr->data;
        *front = *rear = NULL;
        free(ptr);
        return item;
    }

    while (ptr->next != NULL) {
        prevptr = ptr;
        ptr = ptr->next;
    }

    item = ptr->data;
    prevptr->next = NULL;
    *rear = prevptr;
    free(ptr);

    return item;
}

// Display
void display(NODE *front) {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque contents: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

// Main function with menu
int main() {
    NODE *front = NULL, *rear = NULL;
    int choice, item;

    while (1) {
        printf("\n---- DEQUE MENU ----\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                insert_front(&front, &rear, item);
                break;

            case 2:
                printf("Enter item: ");
                scanf("%d", &item);
                insert_rear(&front, &rear, item);
                break;

            case 3:
                delete_front(&front, &rear);
                break;

            case 4:
                item = delete_rear(&front, &rear);
                if (item != -1) printf("Deleted item: %d\n", item);
                break;

            case 5:
                display(front);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
