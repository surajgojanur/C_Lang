#include<stdio.h>
#include<stdlib.h>

typedef struct mynode{
	int data;
	struct mynode *llink,*rlink;
}*NODE;

NODE createNode(int data);



void insertFirst(NODE Head,int data);
void insertLast(NODE Head,int data);
void deleteLast(NODE Head);
void deleteFirst(NODE Head);
void insertPos(NODE Head,int pos,int data);
int searchEle(NODE Head,int data);
NODE reverse(NODE Head);
void insertSorted(NODE Head,int data);
void display(NODE Head);

int main(){
	NODE dls=createNode(3);
	display(dls);
}

NODE createNode(int data){
	NODE newNode=(NODE)malloc(sizeof(struct mynode));
	if(newNode == NULL){
		printf("OUT OF MEMORY\n");
		exit(1);
	}
	newNode->data=data;
	newNode->llink=newNode;
	newNode->rlink=newNode;
	return newNode;
}
void display(NODE Head){
	if(Head == NULL){
		printf("Empty List\n");
		return;
	}
	NODE curr=Head;
	printf("HEAD->");
	do{
		printf("[%d]->",curr->data);
		curr=curr->llink;
	}while(curr != Head);
}

void insertFirst(NODE Head,int data){
	newNode=createNode(data);
	newNode->rlink=Head;
	
	Head->llink=newNode;
	Head->link=newNode;

