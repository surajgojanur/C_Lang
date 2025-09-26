#include<stdio.h>

void printString(char *st);
int main(){
    char st1[]="suraj";
    char st2[]="gojanur";
    printString(st1);
    printString(st2);
}
void printString(char *st){
    // while(*st!='\0'){
    //     printf("%c",*st);
    //     st++;
    // }
    printf("%s",st);
    printf("\t");
}