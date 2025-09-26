#include<stdio.h>
void swap(int* a,int* b);
int main(){
    int a=2,b=4;
    printf("Before swap\n");
    printf("a = %d b = %d \n",a,b);
    swap(&a,&b);
    printf("After swap\n");
    printf("a = %d b = %d",a,b);
}
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}