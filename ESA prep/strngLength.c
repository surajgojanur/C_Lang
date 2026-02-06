#include<stdio.h>
int countString(char arr[]){
    int count=0;
    for(int i=0;arr[i]!='\0';i++){
        count++;
        }
        return count;
}
int main(){
    char st[]="suraj";
    printf("%d\n",countString(st));
    return 0;
}