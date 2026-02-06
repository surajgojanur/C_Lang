#include<stdio.h>

int main(){
    int a=10;
    char ch='a';
    float f=3.14;
    double d=3.14159265358979323846;
    printf("Size of int: %u bytes\n", sizeof(a));
    printf("Size of char: %lu bytes\n", sizeof(ch));
    printf("Size of float: %lu bytes\n", sizeof(f));
    printf("Size of double: %lu bytes\n", sizeof(d));
    return 0;
}