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



void insertArray(int tree[], int *size, int value) {
    if (*size >= 8) {
        printf("Tree is full!\n");
        return;
    }
    tree[(*size)++] = value; 
}

// Display for Array Representation
// Source: [7]
void displayArray(int tree[], int size) {
    if (size == 0) {
        printf("Tree is empty!\n");
        return;
    }
    printf("Binary Tree (Level Order Array): "); 
    for (int i = 0; i < size; i++) 
        printf("%d ", tree[i]);
    printf("\n");
}

int parent(int index) { 
    return (index - 1) / 2; 
}

int leftChild(int index) { 
    return 2 * index + 1; 
}

int rightChild(int index) { 
    return 2 * index + 2; 
}

void displayNodeRelations(int tree[], int size, int index) {
    if (index < 0 || index >= size) {
        printf("Invalid index!\n");
        return;
    }
    
    printf("Node at index %d: %d\n", index, tree[index]);
    
    if (index > 0)
        printf("  Parent: %d\n", tree[parent(index)]);
    else 
        printf("  Parent: None (Root)\n");

    if (leftChild(index) < size)
        printf("  Left Child: %d\n", tree[leftChild(index)]); 
    else
        printf("  Left Child: None\n");

    if (rightChild(index) < size)
        printf("  Right Child: %d\n", tree[rightChild(index)]);
    else
        printf("  Right Child: None\n");
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

    printf("=== ARRAY REPRESENTATION DEMO ===\n");
    int tree[8];
    int size = 0;

    // Using the same values
    for (int i = 0; i < n; i++) {
        insertArray(tree, &size, values[i]);
    }

    displayArray(tree, size);
    
    printf("\nNode Relations:\n");
    for(int i = 0; i < size; i++) {
        displayNodeRelations(tree, size, i);
        printf("---\n");
    }

    return 0;
}