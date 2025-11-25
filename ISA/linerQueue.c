#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct queue
{
    int items[MAX];
    int front,rear;
};

int isEmpty(struct queue *q)
{
    /* data */
    if(q->rear == q->front -1)
        return 1;
    else
        return 0;
}

int isFull(struct queue *q){
    if(q->rear == MAX - 1)
        return 1;
    else
        return 0;
}

void insert(struct queue *q){
    int ele;
    if(isFull(q)){
        printf("\n\t Queue overflow");
        return;
    }
    else{
        printf("Enter valuse to be inserted : ");
        scanf("%d",&ele);
        q->rear++;
        q->items[q->rear]=ele;
    }
    return;
}

int remove1(struct queue *q){
    int item;
    if(isEmpty(q)){
        printf("Stack Under flow");
        return 0;
    }
    else{
        item=q->items[q->front];
        q->front++;
        printf("\n\t The delted item is %d",item);
    }
    return item;
}

void display(struct queue *q){
    int j;
    if(isEmpty(q)){
        printf("\n\t queue under flow");
        return ;
    }
    else{
        printf("\n The elements in queue are \n");

        for(j=q->front; j >= 0 && j <= q->rear; j++)
            printf("\t %d",q->items[j]);
    }
}

int main(void){
    int choice,x,i,ele;
    struct queue q;
    q.rear = -1; q.front=0;
    printf("\n\t Queue operations using the array");
    printf("\n 1 insert 2 remvoe 3 diplsay 4 exit");
    do{
        printf("\n Enter the choice");
        scanf("%d",&choice);
        switch (choice)
        {
        
        
            case 1:
            insert(&q);
            display(&q);
            break;
        
            case 2:
            i=remove1(&q);
            display(&q);
            /* code */
            break;
        
            case 3:
            if(q.rear >= 0 && q.rear <= MAX-1)
                display(&q);
                break;
            /* code */
            break;

            case 4:
            printf("\n\t Enit POint");
            break;
        
        default:
        printf("Enter valid option");
            break;
        }
    }while (choice!=4);
    return 0;
    
}