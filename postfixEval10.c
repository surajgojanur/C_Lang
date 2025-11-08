#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

typedef struct stack{
	int data;
	int top;
}stack;

stack* createStack();
void push(stack* st,char  data);
char pop(stack* st);
char peek(stack* st);
bool isEmpty(stack* st);
bool isFull(stack* st);


//stack* createStack(){
//stack* st=(stack*)malloc(sizeof(struct stack));
//	if(st == null){
//		printf("Out of Memory");
//		exit(0);
//	}
//	st->top=-1;
//	return st;
//}

bool isFull(stack* st){
	return 

void push(stack* st,char data){
	if(s1.top

int main(){
	stack s1;
	s1.top =-1;
	stack *s = &s1;
	printf("%d ",s1.top);
}

