#include<stdio.h>
void addressCheck(int* n);
int main(){
    int n=4;
    addressCheck(&n);
    printf("Adress = %u\n",&n);
}
void addressCheck(int* n){
    printf("Adress in function = %u\n",n);
}