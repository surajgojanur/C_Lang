#include<stdio.h>

int main(){
    int n;
    printf("Enter Number n :");
    scanf("%d",&n);
    static int sum;
    for(int i=1,j=n;i<=n && j>=1;i++,j--){
        sum=sum+i;
        printf("J is : %d \n",j);
    }
    printf("\n \n Sum is : %d\n",sum);
    return 0;
}