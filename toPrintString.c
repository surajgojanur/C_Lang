#include<stdio.h>
void printString(char st[]);
int main(){
    char st1[]="Suraj";
    char st2[]="Gojanur";
    printString(st1);
    printString(st2);
    return 0;
}
void printString(char st[]){
    for(int i=0;'\0'!=st[i];i++){
        printf("%c",st[i]);    
    }
    // printf("%s",st);  
    printf("\t");
}