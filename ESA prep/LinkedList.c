#include<stdio.h>
#include<stdlib.h>

typedef struct mynode{
    int data;
    struct mynode *link;
}*Node;


Node createNode(int data){
    Node nN=(Node)malloc(sizeof(struct mynode));
    if(nN==NULL){
        printf("Out of memory");
        exit(1);
    }else{
        nN->data=data;
        nN->link=NULL;
    }return nN;
}

Node insertNode(Node head,int data){
    if(head==NULL){
        return createNode(data);
    }else{
        Node nN=createNode(data);
        Node curr=head;
        while(curr->link!=NULL){
            curr=curr->link;
        }
        curr->link=nN;
    }
    return head;
}

Node deleteNode(Node head,int key){
    if(head==NULL){
        printf("Empty List");
        return NULL;
    }
    if(head->data==key){
        Node temp=head;
        head=head->link;
        free(temp);
        return head;
    }
    
        Node curr=head;
        while(curr->link!=NULL){
            if(curr->link->data==key){
                Node temp=curr->link;
                curr->link=curr->link->link;
                free(temp);
                return head;
            }
            curr=curr->link;
        }printf("Element not found");
        return head;
    }


void printLL(Node head){
    if(head==NULL){
        printf("Empty LL");
    }else{
        Node curr=head;
        while(curr!=NULL){
            printf("%d -> ",curr->data);
            curr=curr->link;
        }
    }printf("\n");
    return;
}

Node insertInSorted(Node head,int key){
    Node nN=createNode(key);
    if(head==NULL || key<head->data){
        nN->link=head;
        return nN;
    }
    Node curr=head;
    while(curr->link != NULL && curr->link->data < key){
        curr=curr->link;
    }
    nN->link=curr->link;
    curr->link=nN;
    return head;
}
Node sortLL(Node head){
    if(head==NULL){
        printf("EMmpty LL");
    }
    Node nN=createNode(head->data);
    Node curr=head;
    while(curr!=NULL){
        nN=insertInSorted(nN,curr->data);
        curr=curr->link;
    }return nN;

}
int main(){
    Node head=createNode(10);
    head=insertNode(head,5);
    head=insertNode(head,1);
    head=insertNode(head,6);
    head=insertNode(head,99);
    head=insertNode(head,7);
    printLL(head);
    
    head=deleteNode(head,6);
    head=deleteNode(head,3);
    printLL(head);
    printf("Sorting All LL");
    head=sortLL(head);
    printLL(head);
}