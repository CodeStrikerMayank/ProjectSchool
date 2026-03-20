#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
# include "colour.h"
struct Student
{
    int id;
    char *name[100];
    char grades;
    int classes;
};
void display(struct Student s1[]){int st;
    printf("Id no");
    scanf("%d",&st);
    system("cls");
    printf(green);
    printf("\n+------+------+--------+");
    printf("\nName :- %s\n",s1[st].name);
    printf("Class :- %d\n",s1[st].classes);
    printf("Rollnumber :- %d\n",s1[st].id);
    printf("Grades :- %c\n",s1[st].grades);
    printf("+------+------+--------+");
    printf(reset);}
    
int main(){system("cls");
    int ids[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    char *names[10] = {
        "Mayank", "Ram", "Sham", "Rahul", "Amit",
        "Ravi", "Karan", "Arjun", "Vikas", "Neeraj"};
    int class_no[10] = {10, 10, 9, 12, 11, 10, 9, 12, 11, 10};
    char grades[10] = {'A', 'B', 'A', 'C', 'B', 'A', 'B', 'C', 'A', 'B'};
    int size;
    struct Student s1[10];
    for (int i =0;i<10;i++){
        strcpy(s1[i].name,names[i]);
        s1[i].id = ids[i];
        s1[i].grades = grades[i];
        s1[i].classes = class_no[i];
    }
    display(s1);
    return 0;

}