#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "operation.h"
#include "colour.h"

int main()
{
    utf();
    welcome();
    struct Student s1[10];
    struct marks s2[10];

    // Data Initialization
    int ids[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Using 0-9 for  array access
    char *names[10] = {
        "Mayank", "Ram", "Sham", "Rahul", "Amit",
        "Ravi", "Karan", "Arjun", "Vikas", "Neeraj"};
    int class_no[10] = {10, 10, 9, 12, 11, 10, 9, 12, 11, 10};
    char grades[10] = {'F', 'B', 'A', 'C', 'B', 'A', 'B', 'C', 'A', 'B'};
    int maths_marks[10] = {28, 76, 90, 65, 88, 72, 95, 81, 55, 89};
    int science_marks[10] = {29, 81, 88, 70, 95, 68, 98, 79, 60, 91};
    int sst_marks[10] = {27, 85, 92, 68, 89, 74, 96, 83, 58, 87};
    int hindi_marks[10] = {28, 79, 85, 75, 91, 80, 92, 85, 65, 90};
    int eng_marks[10] = {29, 82, 95, 72, 87, 75, 99, 80, 62, 94};

    for (int i = 0; i < 10; i++)
    {
        strcpy(s1[i].name, names[i]);
        s2[i].aid = ids[i];
        s1[i].id = ids[i];
        s1[i].grades = grades[i];
        s1[i].classes = class_no[i];
        s2[i].science = science_marks[i];
        s2[i].sst = sst_marks[i];
        s2[i].eng = eng_marks[i];
        s2[i].hindi = hindi_marks[i];
        s2[i].maths = maths_marks[i];
    }

    int choice;
    while (1)
    {
        system("cls");
        printf(green);
        printf("\n====================================\n");
        printf("       SCHOOL MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf(green);
        printf("\n1. Display Student Report Card\n");
        printf("2. Display Student Details\n");
        printf("3. Advanced Search & Filtering\n");
        printf("4. Exit\n");
        printf(reset);
        printf("\nEnter your choice --> ");

        if (scanf("%d", &choice) != 1)
        {
            // Clear invalid input
            while (getchar() != '\n')
                ;
            choice = 0; // Set to a default invalid choice
        }

        switch (choice)
        {
        case 1:
            loading();
            infoboard(s1, s2, 10);
            break;
        case 2:
            loading();
            display(s1, 10);
            break;
        case 3:
            loading();
            sortersearch(s1, s2, 10); // Pass the size of the student array
            break;
        case 4:
            terminate();
            printf(green "Exiting program. Goodbye!\n" reset);
            return 0;
        default:
            printf(red "Invalid choice. Please try again.\n" reset);
            Sleep(1000);
            break;
        }
    }

    return 0;
}