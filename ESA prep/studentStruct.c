#include<stdio.h>
#include<stdlib.h>

typedef struct Student{
    char name[50];
    int age;
    float grade;
}*student;

int main(){
    int n=3;
    student st=(student)malloc(sizeof(struct Student)*n);
    for(int i=0;i<n;i++){
        printf("Enter name, age and grade of student %d: ",i+1);
        scanf("%s %d %f",st[i].name,&st[i].age,&st[i].grade);
    }
    printf("\nStudent Details:\n");
    for(int i=0;i<n;i++){
        printf("Name: %s, Age: %d, Grade: %.2f\n",st[i].name,st[i].age,st[i].grade);
    }
    free(st);
    return 0;
}