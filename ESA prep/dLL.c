#include<stdio.h>
#include<stdlib.h>

typedef struct mynode{
    int data;
    struct mynode *next;
    struct mynode *prev;
}*Node;

Node createNode(int data){
    Node nN=(Node)malloc(sizeof(struct mynode));
    if(nN==NULL){
        printf("OUT OF MEMROY");
        exit(1);
    }
    nN->data=data;
    nN->next=nN;
    nN->prev=nN;
    return nN;
}
Node insertFront(Node head,int key){
    if(head==NULL){
        return createNode(key);
    }
    Node temp=createNode(key);
    temp->next=head;
    temp->prev=head->prev;
    head->prev=temp;
    temp->prev->next=temp;
    return temp;
}
Node insertRear(Node head,int key){
    if(head==NULL){
        return createNode(key);
    }
    Node temp=createNode(key);
    temp->prev=head->prev;
    temp->next=head;
    head->prev->next=temp;
    head->prev=temp;
    return head;
}
void printDLL(Node head){
    if(head==NULL){
        printf("Empty DLL");
        return;
    }
    Node temp=head;
    printf("Start->");
    printf("%d->",temp->data);
    temp=temp->next;
    while(temp!=head){
        printf("%d->",temp->data);
        temp=temp->next;
    }printf("END");
    printf("\n");
}
int main(){
    Node head=createNode(4);
    printDLL(head);
    head=insertFront(head,2);
    printDLL(head);
    head=insertRear(head,6);
    printDLL(head);
}