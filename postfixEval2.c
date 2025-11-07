#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX 100

typedef struct stack
{
    int data;
    int top;
}stack;

stack createStack(stack* st){
    stack* st=(stack*) malloc(struct stack);
    st->top=-1;
}

void isEmpty(stack* st){
    if (st->top == -1)
    {
        /* code */
    }
    
}

void push(stack* st,int data){
    if(st->top == MAX-1){
        printf("Stack overfloow\n");
        return;
    }
    st->data[st->top++]=data;
}

void pop(stack* st){
    if()
}

void main(){
    printf("Empty ");
}