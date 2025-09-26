#include<stdio.h>
void square(int* n);
int main(){
    int n=2;
    square(&n);
    printf("%d ", n);
}
void square(int* n){
    *n=(*n)*(*n);
}