#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "operation.h"
#include "colour.h"

int main(){    
    struct Student s1[10];
    system("cls");
    int ids[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    char *names[10] = {
        "Mayank", "Ram", "Sham", "Rahul", "Amit",
        "Ravi", "Karan", "Arjun", "Vikas", "Neeraj"};
    int class_no[10] = {10, 10, 9, 12, 11, 10, 9, 12, 11, 10};
    char grades[10] = {'A', 'B', 'A', 'C', 'B', 'A', 'B', 'C', 'A', 'B'};
    for (int i = 0; i < 10; i++)
    {
        strcpy(s1[i].name, names[i]);
        s1[i].id = ids[i];
        s1[i].grades = grades[i];
        s1[i].classes = class_no[i];
    }
    display(s1,10)
    ;
    return 0;
}