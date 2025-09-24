#include<stdio.h>

int main(){
    int n=10;
    int *ptr=&n;
    int _n=*ptr;
    printf("This is n = %d \n",n);
    printf("This is ptr = %d \n",*ptr);
    printf("This is _n = %d \n",_n);
    printf("This is ptr of n = %p \n",&n);
    printf("This is ptr pointing to the n  = %p \n",ptr);
    printf("This is ptr address = %p \n",&ptr);
    printf("This is _n ptr address = %p \n",&_n);

}