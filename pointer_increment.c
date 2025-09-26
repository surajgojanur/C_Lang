#include<stdio.h>
int main(){
    int a[]={1,2};
    int *ptr=&a[0];
    printf("ptr = %u ",*ptr);
    ptr++;
    printf("ptr = %u ",*ptr);
}