#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<stdbool.h>
#define MAX 20

typedef struct stack{
    char data[MAX];
    int top;
}stack;

stack* createStack(){
    stack* newStack=(stack*)malloc(sizeof(struct stack));
    newStack->top=-1;
    return newStack;
}

bool isEmpty(stack* stack){
    if(stack->top == -1){
        return true;
    }
    return false;
}

bool isFull(stack* stack){
    if(stack->top == MAX-1){
        return true;
    }
    return false;
}

void push(stack* stack,char data){
    if(isFull(stack)){
        printf("Stack overflow\n");
        exit(1);
    }
    stack->data[++stack->top]=data;
    return;
}

char pop(stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty");
        return -1;
    }
    char popEle=stack->data[stack->top--];
    return popEle;
}

char peek(stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty");
        return -1;
    }
    char peeked=stack->data[stack->top];
    return peeked;
}

int precd(char st){
    switch (st)
    {
    case '+':
    case '-':return 1;
    case '/':
    case '*':return 2;
    case '^':
    case '$':return 3;
    default:
        return 0;
    }
}

int main(){
    printf("Enter the infix : ");
    char infix[MAX],postfix[MAX];
    char ele;
    scanf("%s",infix);
    int i=0,j=0;
    stack* st=createStack();
    for(i=0;i<strlen(infix);i++){
        char ch=infix[i];
        if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else{
            if(ch == '('){
                push(st,ch);
            }
            else if(ch == ')'){
                while (st->data[st->top] != '('){
                    postfix[j++]=pop(st);
                }
                ele=pop(st);
            }

            else{
                while (!isEmpty(st) && precd(st->data[st->top]) >= precd(ch))
                {
                    postfix[j++]=pop(st);
                }
                push(st,ch);
            }
        }
    }

        while(!isEmpty(st)){
            postfix[j++]=pop(st);
        }
        postfix[j]='\0';
        printf("Converted to postfix %s ",postfix);
    
}