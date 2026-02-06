#include<stdio.h>
#include<stdlib.h>
int main(){
    int *n=(int*)malloc(sizeof(int)*5);
    int m=10,length=5;
    for(int i=0;i<length;i++){
        n[i]=m;
        m+=10;
    }
    for(int i=0;i<length;i++){
        printf("%d ",n[i]);
    }
    free(n);
    return 0;
}