#include<stdio.h>

int main(){
    int n;
    int *ptr=&n;
    *ptr=0;
    
    printf("n = %d \n",n);
    printf("ptr = %d \n",*ptr);

    *ptr+=5;
    printf("n = %d \n",n);
    printf("ptr = %d \n",*ptr);

    (*ptr)++;
    printf("n = %d \n",n);
    printf("ptr = %d \n",*ptr);

    return 0;
}