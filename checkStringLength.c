#include<stdio.h>
void countString(char *arr[]);
int main(){
    char st[]="surajgojanur";
    countString(&st);
}
void countString(char *arr[]){
    int count=0;
    for(int i=0;*arr[i]!='\0';i++){
        count++;
    }
    printf("length = %d ",count);
}