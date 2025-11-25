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
    if(q->rear < q->front){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(queue *q){
    if(q->rear == MAX -1){
        return 1;
    }else{
        return 0;
    }
}

void insert(queue *q,int item){
    if(isFull(q)){
        printf("\nOver flow condition");
    }
    q->data[++(q->rear)]=item;
}

int removeQ(queue *q){
    int ele=0;
    for(int i=0;i<3;i++){
        if(isEmpty(&q[i])){
            printf("\n UnderFlow condition");
            continue;
        }
        ele=q[i].data[(q->front)];
        if(q[i].front==q[i].rear){
            q[i].front=0;q[i].rear=-1;
        }else{
            q[i].front++;
        }
        return ele;
    }
    return -1;
}

void display(queue *q){
    printf("queue status\n");
    for(int i=0;i<3;i++){
        if(isEmpty(&q[i]))
            printf("\n Queue %d is empty\n",i);
            for(int j=q[i].front;j<=q[i].rear;j++){
                printf("%d | ",q[i].data[j]);
                printf("\n");
            }
    }
}

int main(void){
    int rmItem=0;
    int choice=0;
    int ele=0;
    int prior=0;
    int flag=1;
    queue q[4];
    for(int i=0;i<3;i++){
        q[i].front=0;
        q[i].rear=-1;
    }
    while(flag){
        printf("***************MENU************\n");
        printf("1 insert 2 remove 3 exit \n");
        printf("Enter your choice");
        scanf("%d",&choice);

    }
}