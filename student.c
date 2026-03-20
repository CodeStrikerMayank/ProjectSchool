#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "operation.h"
#include "colour.h"

int main(){    
    struct Student s1[10];struct marks s2[10];
    system("cls");
    int ids[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    char *names[10] = {
        "Mayank", "Ram", "Sham", "Rahul", "Amit",
        "Ravi", "Karan", "Arjun", "Vikas", "Neeraj"};
    int class_no[10] = {10, 10, 9, 12, 11, 10, 9, 12, 11, 10};
    char grades[10] = {'A', 'B', 'A', 'C', 'B', 'A', 'B', 'C', 'A', 'B'};
    int maths_marks[10]   = {85, 76, 90, 65, 88, 72, 95, 81, 55, 89};
    int science_marks[10] = {92, 81, 88, 70, 95, 68, 98, 79, 60, 91};
    int sst_marks[10]     = {78, 85, 92, 68, 89, 74, 96, 83, 58, 87};
    int hindi_marks[10]   = {88, 79, 85, 75, 91, 80, 92, 85, 65, 90};
    int eng_marks[10]     = {90, 82, 95, 72, 87, 75, 99, 80, 62, 94};
    for (int i = 0; i < 10; i++)
    {
        strcpy(s1[i].name, names[i]);
        s2[i].aid = ids[i];
        s1[i].id = ids[i];
        s1[i].grades = grades[i];
        s1[i].classes = class_no[i];
        s2[i].science = science_marks[i];
        s2[i].sst  = sst_marks[i];
        s2[i].eng = eng_marks[i];
        s2[i].hindi = hindi_marks[i];
        s2[i].maths = maths_marks[i];
        
    }
    infoboard(s1,s2,10)
    ;
    return 0;
}