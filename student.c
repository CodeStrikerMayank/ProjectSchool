#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "operation.h"
#include <conio.h>
#include "colour.h"
void backup(){
    if (CopyFile("data.csv","databackp.csv",FALSE)){
        printf("Data Backup complete ✅");
        Sleep(1000);
    }
    else{
        printf("%sError data not found. Code: %lu%s",red,GetLastError(),reset);
    }
}
int main()
{
    utf();
    welcome();

    while (1)
    {
        FILE *fp = fopen("data.csv", "r");
        if (fp == NULL)
        {
            system("cls");
            printf(yellow "Welcome! 'data.csv' not found.\n" reset);
            printf("You must enroll a new student to begin.\n\n");
            printf("Press any key to proceed to the enrollment portal...");
            _getch();
            addon();
            continue; 
        }
        else{
            backup();
            printf("Data Backup");
        }

        char c;
        int size = 0;
        while ((c = fgetc(fp)) != EOF)
        {
            if (c == '\n')
            {
                size++;
            }
        }
        fclose(fp);

        if (size == 0)
        {
            system("cls");
            printf(yellow "Data file is empty.\n" reset);
            printf("You must enroll a new student to begin.\n\n");
            printf("Press any key to proceed to the enrollment portal...");
            _getch();
            addon();
            continue; 
        }

        struct Student s1[size];
        struct marks s2[size];
        extract(s1, s2);

        int choice;
        system("cls");
        printf(cyan);
        printf("\n\t\t========================================\n");
        printf("\t\t|                                      |\n");
        printf("\t\t|      SCHOOL MANAGEMENT SYSTEM        |\n");
        printf("\t\t|                                      |\n");
        printf("\t\t========================================\n\n");
        printf(green);
        printf("\t\t\t1. Display Student Report Card\n");
        printf("\t\t\t2. New Student Enrollment\n");
        printf("\t\t\t3. Update Student Details\n");
        printf("\t\t\t4. Display Basic Student Info\n");
        printf("\t\t\t5. Advanced Search & Filtering\n");
        printf("\t\t\t6. Exit\n");
        printf(reset);
        printf("\n\t\tEnter your choice --> ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            choice = 0;
        }

        switch (choice)
        {
        case 1:
            loading();
            infoboard(s1, s2, size);
            break;
        case 2:
            loading();
            addon();
            break;
        case 3:
            loading();
            update(s1, s2, size);
            break;
        case 4:
            loading();
            display(s1, size);
            break;
        case 5:
            loading();
            sortersearch(s1, s2, size);
            break;
        case 6:
            terminate();
            printf(green "\n\nExiting program. Goodbye!\n" reset);
            return 0;
        default:
            printf(red "\n\t\tInvalid choice. Please try again.\n" reset);
            Sleep(1000);
            break;
        }
    }

    return 0; 
}