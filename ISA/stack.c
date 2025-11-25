#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

typedef struct stack{
    int data[MAX];
    int top;
}stack;

stack* createStack(){
    stack* newStack=(stack*)malloc(sizeof(struct stack));
    newStack->top=-1;
    return newStack;
}

void push(stack* stack,int data){
    if(stack->top == MAX){
        printf("Stack over flow can't pushh\n");
        return;
    }
    stack->data[++stack->top]=data;
    printf(" %d pushed to the stack\n",data);
}

int pop(stack* stack){
    if(stack->top == -1){
        printf("Stack is empty\n  ");
        return -1;
    }
    int poped=stack->data[stack->top--];
    printf("Stack %d has been poped\n",poped);
    return poped;
}

bool isEmpty(stack* stack){
    if(stack->top==-1){
        return true;
    }
    return false;
}

int peek(stack* stack){
    if(isEmpty(stack)){
     printf("Stack is empty\n");
     return -1;
    }

    int peeked=stack->data[stack->top];
    printf("top element peeked %d\n",peeked);
    return peeked;
}

bool isFull(stack* stack){
    if(stack->top==MAX){
        printf("Stack Overflow\n");
        return true;
    }
    return false;
}

int main(){
    stack* st1=createStack();
    push(st1,1);
    int p2=peek(st1);
    int p1=pop(st1);
    
    bool b1=isEmpty(st1);
    bool b2=isFull(st1);

}