#include<stdio.h>
int product(int* a,int* b);
int sum(int* a,int* b);
int averge(int* a,int* b);

int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("Product %d",product(&a,&b));
    printf("Sum of a & b %d ",sum(&a,&b));
    printf("Averge of a & b %d",averge(&a,&b));
}
int product(int* a,int* b){
    return (*a)*(*b);
}
int sum(int* a,int* b){
    return (*a)+(*b);
}
int averge(int* a,int* b){
    return (*a)+(*b)/2;
}