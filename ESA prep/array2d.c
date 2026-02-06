#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[3][3];
    int count=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]=count++;
        }
    }
    int sum=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sum+=arr[i][j];
        }
    }
    printf("%d",sum);
    return 0;
}