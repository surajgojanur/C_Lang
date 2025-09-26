#include<stdio.h>
int main(){
    int arr[5];
    int *ptr = &arr[0];
    for(int i=0;i<5;i++){
        printf("Enter value of array %d ",i);
        scanf("%d",(ptr+i));
    }
    for(int i=0;i<5;i++){
        printf("\nValue at %d ",*(ptr+i));
    }
}