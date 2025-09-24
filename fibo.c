#include<stdio.h>

int fibonacci(int n);
int n;
int main(){
    scanf("Enter number : %d",&n);
    fibonacci(n);
}
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int fibNm1=fibonacci(n-1);
    int fibNm2=fibonacci(n-2);
    int fibNm=fibNm1+fibNm2;
    return fibNm;
}