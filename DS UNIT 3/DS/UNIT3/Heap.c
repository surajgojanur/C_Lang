#include<stdio.h>
#define MAX 100

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void printHeap(int heap[],int size){
    printf("Max-Heap: ");
    for(int i=0;i<size;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}

void upheapify(int heap[],int index){
    int parent=(index-1)/2;
    while(index > 0 && heap[parent] < heap[index]){
        swap(&heap[parent],&heap[index]);
        index=parent;
        parent=(index-1)/2;
    }
}

void downheapify(int heap[],int size,int index){
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left < size && heap[left] > heap[largest])
        largest=left;

    if(right < size && heap[right] > heap[largest])
        largest=right;
    
    if(largest != index){
        swap(&heap[index],&heap[largest]);
        downheapify(heap,size,largest);
    }
}

void insert(int heap[],int *size,int value){
    if(*size >= MAX){
        printf("Heap Overflow \n");
        return;
    }
    heap[*size]=value;

    upheapify(heap,*size);
    (*size)++;
}

void buildMaxHeap(int heap[],int size){
    for(int i=(size/2)-1;i>=0;i--){
        downheapify(heap,size,i);
    }
    printHeap(heap,size);
}

void deleteRoot(int heap[],int *size){
    if(*size <= 0){
        printf("Heap is empty\n");
        return;
    }
    int deletedValue=heap[0];
    heap[0]=heap[*size-1];
    (*size)--;

    downheapify(heap,*size,0);

    printf("Deleted Root : %d \n",deletedValue);
}

void heapSort(int heap[],int size){
    buildMaxHeap(heap,size);
    for(int i=size-1;i>0;i--){
        swap(&heap[0],&heap[i]);
        downheapify(heap,i,0);
    }
}

int main(){
    int heap[MAX];
    int size=0;
    printf(" === 1 INSERTION DEMO (UPHeapify ===\n");
    insert(heap,&size,10);
    insert(heap,&size,20);
    insert(heap,&size,15);
    insert(heap,&size,30);
    insert(heap,&size,40);

    printHeap(heap,size);

    printf("\n");
    printf("=== DELETION DEMO ( DELETE ROOT) \n");
    deleteRoot(heap,&size);
    printHeap(heap,size);
    printf("\n");

    printf("=== Build Heap DEMO ( Bottom-up)=== \n");
    int arr[]={4,10,3,5,1};
    int n=5;
    for(int i=0;i<n;i++)
        heap[i]=arr[i];
    printf("\n");

    printf("Array before sort: ");
    for(int i=0;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");

    heapSort(heap,n);
    printf("Sorted Array: ");
    for(int i=0;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");

    return 0;
}
