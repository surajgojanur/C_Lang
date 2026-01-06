#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    /* data */
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Error\n");
        return NULL;
    }
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

Node* insert(Node* root,int value){
    Node* newNode=createNode(value);
    if(root == NULL){
        return newNode;
    }

    Node* queue[8];
    int front=0;
    int rear=0;

    queue[rear++]=root;

    while (front<rear)
    {
        /* code */
        Node* temp = queue[front++];

        if(temp->left == NULL){
            temp->left=newNode;
            return root;
        }else{
            queue[rear++]=temp->left;
        }

        if(temp->right == NULL){
            temp->right=newNode;
            return root;
        }else{
            queue[rear++]=temp->left;
        }
    }
    return root;
}

void preOrderTraversal(Node* root){
    if(root == NULL)return;
    printf("%d ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL)return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ",root->data);
}

void InOrderTraversal(Node* root){
    if(root == NULL)return;
    InOrderTraversal(root->left);
    printf("%d ",root->data);
    InOrderTraversal(root->right);
}

int main(){
    Node* root = NULL;
    int values[] = {1,2,3,4,5};
    int n=sizeof(values)/sizeof(values[0]);


    printf("Inserting nodes : ");
    for(int i=0;i<n;i++){
        printf("%d ",values[i]);
        root = insert(root,values[i]);
    }printf("\n\n");

    printf("Preorder ( Root LEFT RIGHT)");
    preOrderTraversal(root);
    printf("\n");

    printf("Inorder ( LEFT Root RIGHT)");
    InOrderTraversal(root);
    printf("\n");

    printf("Postorder ( LEFT RIGHT  Root)");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}