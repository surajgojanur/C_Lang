#include<stdio.h>
#include<string.h>
struct student{
    int rollNo;
    // char name[100];
    char *name;
    float cgpa;
};
int main(){
    struct student s1;
    s1.rollNo=1;
    // strcpy(s1.name,"Suraj");
    s1.name="Suraj";
    s1.cgpa=6.9;
    printf("Name : %s\n",s1.name);
    printf("Roll NO : %d\n",s1.rollNo);
    printf("cgpa : %f\n",s1.cgpa);

    struct student s2;
    s2.name="Mahesh";
    s2.rollNo=2;
    s2.cgpa=2.2;
    printf("Name : %s\n",s2.name);
    printf("Roll NO : %d\n",s2.rollNo);
    printf("cgpa : %f\n",s2.cgpa);

}