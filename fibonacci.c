#include<stdio.h>
void fibo(int n);
int main(){
    int n;
    printf("enter a numbe for fibo");
    scanf("%d",&n);
    fibo(n);
    return 0;
}
void fibo(int n){
    int fibo[n];
    fibo[0]=0;
    fibo[1]=1;
    fibo[2]=1;
    printf("%d\t%d\t%d\t",fibo[0],fibo[1],fibo[2]);
    for(int i=3;i<n;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
        printf("%d \t",fibo[i]);
    }
    }
