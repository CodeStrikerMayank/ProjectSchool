#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "colour.h"
#include "operation.h"
#include <windows.h>
void display(struct Student s1[], int size){ 
    int st;
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
    printf(reset);
    Sleep(3000);
    if (st < 0 || st >= size) {
        printf(red "Error: Invalid ID number. Please enter an ID within the valid range.\n" reset);
    }
}
void infoboard(struct Student s1[],struct marks s2[],int size){
    int st;
    printf("Id no");
    scanf("%d",&st);
    system("cls");
    printf(green);

    printf("\n+-------------------------------------------------+\n");
    printf("|               STUDENT REPORT CARD               |\n");
    printf("+-------------------------+-----------------------+\n");
    
    printf("| Name: %-17s | Roll No: %-12d |\n", s1[st].name, s1[st].id);
    
    printf("+---------+---------+---------+---------+---------+\n");
    printf("|  Maths  | Science | English |  Hindi  |   SST   |\n");
    printf("+---------+---------+---------+---------+---------+\n");
    printf("|   %3d   |   %3d   |   %3d   |   %3d   |   %3d   |\n", 
        s2[st].maths, s2[st].science, s2[st].eng, s2[st].hindi, s2[st].sst);
    printf("+---------+---------+---------+---------+---------+\n\n");
    printf(reset);
    Sleep(3000);
    if (st < 0 || st >= size) {
        printf(red "Error: Invalid ID number. Please enter an ID within the valid range.\n" reset);
    }
}