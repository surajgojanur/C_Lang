#include<stdio.h>
int main(){
    int n=22;
    int m=24;
    int *ptr1=&n;
    int *ptr2=&m;
    printf("Subtraction of pointers %u ",ptr1-ptr2);
    printf("Comprastion of pointers %u ",ptr1==ptr2);
}