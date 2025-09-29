#include<stdio.h>

int main(){
    char st[100];
    char ch;
    int i=0;
    while(ch!='\n'){
        scanf("%c",&ch);
        st[i]=ch;
        i++;
    }
    st[i]='\0';
 
    puts(st);
}