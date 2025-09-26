#include<stdio.h>

int main(){

    //Print 'i' value from it's pointer to pointer
    int i=1;
    int *ip=&i;
    int **ipp=&ip;
    printf("%d \n",**ipp);
}