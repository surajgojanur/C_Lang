#include<stdio.h>

int main(){

    float flt;
    int *ptr=&flt;
    *ptr=3.12;
    printf(flt);
}