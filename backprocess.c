#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "colour.h"
#include "operation.h"
#include <windows.h>
void display(struct Student s1[], int size){ // Added 'size' parameter
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
    // Added bounds check for 'st'
    if (st < 0 || st >= size) {
        printf(red "Error: Invalid ID number. Please enter an ID within the valid range.\n" reset);
    }
}
