#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct queue{
    int items[MAX];
    int front,rear;
};

int empty(struct queue *cq){
    return ((cq->front == cq->rear) ? 1: 0);
}
int remove1(struct queue *cq){
    if (empty(cq))
    {
        /* code */
        printf("queue underflow");
        exit(1);
    }
    if(cq->front == MAX-1)
        cq->front=0;
    else
        cq->front++;
    return (cq->items[cq->front]);
}
void insert(struct queue *cq,int x){
    if(cq->rear == MAX -1)
        cq->rear=0;
    else
        cq->rear++;

    if(cq->rear == cq->front){
        printf("queue overflow");
        exit(1);
    }
    cq->items[cq->rear]=x;
    return;
}

void display(struct queue *q){
    int current_front=q->front;
    if(empty(q)){
        printf("\nQueue is empty");
        return ;
    }
    printf("\n Queue elements:" );

    if(current_front == MAX -1)
        current_front=0;
    else
        current_front++;

    while (current_front != (q->rear +1 )% MAX){
        printf("%d ",q->items[current_front]);
        current_front=(current_front +1 )%MAX;
    }
    printf("\n");
}

int main(void){
    int choice,element,removed_item;
    struct queue q;

    q.front=q.rear = MAX-1;
    printf("Circular queue operations\n");
    printf("1. insert 2 . remove 3. display 4 exit");

    do{
        printf("\nEnter choice");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d",&element);
            insert(&q,element);
            display(&q);
            break;
        
            case 2:
            removed_item=remove1(&q);
            printf("Rempved item : %d\n",removed_item);
            display(&q);
            break;
        
            case 3:
            display(&q);
            /* code */
            break;
        
            case 4:
            /* code */
            printf("Exiting");
            break;
        
        default:
            break;
        }
    }while (choice!=4);
    return 0;
    
}