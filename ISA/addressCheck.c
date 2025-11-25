#include<stdio.h>
void addressCheck(int* n);
int main(){
    int n=4;
    printf("Address = %u\n",&n);
    addressCheck(&n);
}

void addressCheck(int* n){
    printf("Address in function = %u\n",n);
}