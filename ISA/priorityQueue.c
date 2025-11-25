#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct 
{
    int data[MAX];
    int front;
    int rear;
}queue;

int isEmpty(queue *q){
    return (q->rear < q->front);
}

int isFull(queue *q){
    return (q->rear == MAX - 1);
}

void insert(queue *q,int item){
    if(isFull(q)){
        printf("\nOverflow condition\n");
        return;
    }
    q->data[++(q->rear)] = item;
}

int removeQ(queue q[]){
    for(int i=0;i<3;i++){   // check from high to low priority
        if(isEmpty(&q[i])){
            continue;
        }
        int ele = q[i].data[q[i].front];

        if(q[i].front == q[i].rear){
            // reset queue
            q[i].front = 0;
            q[i].rear = -1;
        } else {
            q[i].front++;
        }

        return ele;
    }
    printf("\nUnderflow! All queues empty.\n");
    return -1;
}

void display(queue q[]){
    printf("\n********* Queue Status *********\n");
    for(int i=0;i<3;i++){
        printf("\nPriority %d -> ", i);
        if(isEmpty(&q[i])){
            printf("EMPTY");
        } else {
            for(int j = q[i].front ; j <= q[i].rear; j++){
                printf("%d ", q[i].data[j]);
            }
        }
    }
    printf("\n********************************\n");
}

int main(void){
    int choice, ele, prior;
    int flag = 1;

    queue q[3];

    for(int i=0;i<3;i++){
        q[i].front = 0;
        q[i].rear = -1;
    }

    while(flag){
        printf("\n*************** MENU ***************\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter priority (0=High, 1=Med, 2=Low): ");
                scanf("%d", &prior);

                if(prior < 0 || prior > 2){
                    printf("Invalid priority!\n");
                    break;
                }

                printf("Enter element: ");
                scanf("%d", &ele);

                insert(&q[prior], ele);
                break;

            case 2:
                ele = removeQ(q);
                if(ele != -1)
                    printf("Removed element = %d\n", ele);
                break;

            case 3:
                display(q);
                break;

            case 4:
                flag = 0;
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
