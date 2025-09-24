#include<stdio.h>

int fact(int n);

int main(){
    int n=0;
    printf("Enter a number : \n");
    scanf("%d",&n);
    int result=fact(n);
    printf("Factorail of %d is %d\n",n,result);
}
int fact(int n){
    if(n==0){
        return  1;
    }
    int factNn=fact(n-1);
    int factN=factNn*n;
    return factN;
}
