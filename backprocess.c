#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "colour.h"
#include "operation.h"
#include <windows.h>
void utf()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
}

void display(struct Student s1[], int size)
{
    system("cls");
    int st;
    printf("Id no");
    scanf("%d", &st);
    if (st < 0 || st >= size)
    {
        printf(red "Error: Invalid ID number. Please enter an ID within the valid range.\n" reset);
        Sleep(2000);
        return;
    }
    time();
    system("cls");
    printf(green);
    printf("\n+------+------+--------+");
    printf("\nName :- %s\n", s1[st].name);
    printf("Class :- %d\n", s1[st].classes);
    printf("Rollnumber :- %d\n", s1[st].id);
    printf("Grades :- %c\n", s1[st].grades);
    printf("+------+------+--------+");
    printf(reset);
    printf("\nPress any key to continue...");
    _getch();
    hello();
}

void infoboard(struct Student s1[], struct marks s2[], int size)
{   system("cls");
    int st;
    printf("Id no");
    scanf("%d", &st);
    if (st < 0 || st >= size)
    {
        printf(red "Error: Invalid ID number. Please enter an ID within the valid range.\n" reset);
        Sleep(2000);
        return;
    }
    time();
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
    printf("\nPress any key to continue...");
    _getch();
    hello(); // Animation for returning after displaying details
}

void wtboard(struct Student s1[], struct marks s2[], int key, int arr[], int len)
{
    char *str[3] = {"FAILED STUDENTS", "AVERAGE STUDENTS", "HIGH SCORE STUDENT"};
    printf("\n%45s\n", str[key]);

    printf("========================================================================================\n");
    printf("| %-3s | %-20s | %-7s | %-6s | %-4s | %-8s | %-6s | %-5s |\n",
"ID", "STUDENT NAME", "ENGLISH", "HINDI", "SST", "SCIENCE", "MATHS", "AVG");
    printf("----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < len; i++)
    {
        float avg = (s2[arr[i]].eng + s2[arr[i]].maths + s2[arr[i]].hindi + s2[arr[i]].science + s2[arr[i]].sst) / 5.0;

        printf("| %-3d | %-20s | %-7d | %-6d | %-4d | %-8d | %-6d | %-5.2f |\n",
            s1[arr[i]].id, s1[arr[i]].name, s2[arr[i]].eng, s2[arr[i]].hindi, s2[arr[i]].sst, s2[arr[i]].science, s2[arr[i]].maths, avg);
    }
    printf("========================================================================================\n");
    printf("Press any key to return ↩");
    _getch();
}
void sortersearch(struct Student s1[], struct marks s2[], int size)
{
    int num;
    while (1)
    {
        int arr[10];
        system("cls");
        printf(green);
        printf("========================\n");
        printf("------Details search----\n");
        printf("|  1.Failed student    |\n");
        printf("|  2.Average students  |\n");
        printf("|  3.High scores       |\n");
        printf("|  4.Deep search       |\n");
        printf("|  5.CMD Touch         |\n");
        printf("|  6.Exit              |\n");
        printf("========================\n");
        printf(reset);
        printf("Enter your choice --> ");
        scanf("%d", &num);

        if (num == 1)
        {
            int key = 0;
            int k = 0;
            for (int i = 0; i < size; i++)
            {
                int avg = (s2[i].eng + s2[i].maths + s2[i].hindi + s2[i].science + s2[i].sst) / 5;
                if (avg < 33)
                {
                    arr[k] = i;
                    k++;
                }
            }
            wtboard(s1, s2, key, arr, k);
        }
        else if (num == 2)
        {
            int key = 1;
            int k = 0;
            for (int i = 0; i < size; i++)
            {
                int avg = (s2[i].eng + s2[i].maths + s2[i].hindi + s2[i].science + s2[i].sst) / 5;
                if (avg > 33 && avg < 80)
                {
                    arr[k] = i;
                    k++;
                }
            }
            wtboard(s1, s2, key, arr, k);
        }
        else if (num == 3)
        {
            int key = 2;
            int k = 0;
            for (int i = 0; i < size; i++)
            {
                int avg = (s2[i].eng + s2[i].maths + s2[i].hindi + s2[i].science + s2[i].sst) / 5;
                if (avg > 80)
                {
                    arr[k] = i;
                    k++;
                }
            }
            wtboard(s1, s2, key, arr, k);
        }
        else if (num == 4)
        {
            deepsearch(s1, s2, size);
        }
        else if (num == 5)
        {
            printf("coming soon");
        }
        else if (num == 6)
        {
            break;
        }
        else
        {
            printf(red "Caution use available inputs !" reset);
            Sleep(1000);
        }
    }
}
void deepsearch(struct Student s1[], struct marks s2[], int size)
{
    while (1)
    {
        system("cls");
        int lan = size; // Use the passed 'size' parameter
        printf("=================Control protocol for deep search=================\n");
        printf(">>>User-->");
        char n[100];
        scanf("%s", n);
        if (strcmp(n, "id") == 0)
        {
            while (1)
            {
                int t;
                printf("id = ");
                scanf("%d", &t);
                if (t >= 0 && t < lan)
                { // Boundary check must happen BEFORE accessing s2[t]
                    float avg = (float)(s2[t].eng + s2[t].hindi + s2[t].maths + s2[t].science + s2[t].sst) / 5.0;
                    printf("================================================\n");
                    printf("Name :- %s\n", s1[t].name);
                    printf("Admission number :- %d\n", s1[t].id);
                    printf("Class :- %d\n", s1[t].classes);
                    printf("===============Detail Inforamtion===============\n");
                    printf("| Marks :- Subject |\n");
                    printf("English :- %d\n", s2[t].eng);
                    printf(" Hindi  :- %d\n", s2[t].hindi);
                    printf("  SST   :- %d\n", s2[t].sst);
                    printf("Science :- %d\n", s2[t].science);
                    printf("  Maths :- %d\n", s2[t].maths);
                    printf(">>>>>> Details analytics <<<<<< \n");
                    printf("Average performance -> %.2f\n", avg);
                    int arr[] = {s2[t].eng, s2[t].hindi, s2[t].sst, s2[t].science, s2[t].maths};
                    char *subjects[5] = {"English", "Hindi", "SST", "Science", "Maths"};
                    (avg > 33.00) ? printf("Status Pass\n") : printf("Status Fail\n");
                    if (avg < 33.00)
                    {
                        if (s2[t].eng < 33)
                        {
                            printf("English : %d\n", s2[t].eng);
                        }
                        else if (s2[t].hindi < 33)
                        {
                            printf("hindi :%d\n", s2[t].hindi);
                        }
                        else if (s2[t].science < 33)
                        {
                            printf("science : %d\n", s2[t].science);
                        }
                        else if (s2[t].maths < 33)
                        {
                            printf("Maths : %d\n", s2[t].maths);
                        }
                        else if (s2[t].sst < 33)
                        {
                            printf("SST : %d\n", s2[t].sst);
                        }
                    }
                    for (int i = 0; i < 4; i++)
                    { // Corrected outer loop for bubble sort (5 elements, 4 passes)
                        for (int j = 0; j < 4 - i; j++)
                        { // Corrected inner loop for bubble sort
                            if (arr[j] < arr[j + 1])
                            {
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                                char *tempsub = subjects[j];
                                subjects[j] = subjects[j + 1];
                                subjects[j + 1] = tempsub;
                            }
                        }
                    }

                    printf("\n%s||A -->high score ||%s ", green, reset);
                    printf("%s||B-->Middle score ||%s ", blue, reset);
                    printf("%s||C-->Low score||\n%s", red, reset);
                    printf("Subject-->Score\n");
                    for (int i = 0; i < 5; i++)
                    {
                        if (i < 2)
                        {
                            printf("%s %s -->  %d %s\n", green, subjects[i], arr[i], reset);
                        }
                        else if (i > 2)
                        {
                            printf("%s %s -->  %d %s\n", blue, subjects[i], arr[i], reset);
                        }
                        else
                        {
                            printf("%s %s -->  %d %s \n", red, subjects[i], arr[i], reset);
                        }
                    }
                    printf("Enter key to return");
                    _getch();
                }
            }
        }
        else if (strcmp(n, "name") == 0 || strcmp(n, "class") == 0)
        {
            if (strcmp(n, "name") == 0)
            {
                char search_name[100];
                printf("Enter name: ");
                scanf("%s", search_name);

                // Assuming max 10 students, adjust if 'size' can be larger than 10
                int matches[size];
                int count = 0;

                for (int i = 0; i < lan; i++)
                {
                    if (strcmp(s1[i].name, search_name) == 0)
                    {
                        matches[count++] = i;
                    }
                }
                if (count == 0)
                {
                    printf("No student found ❌\n");
                    _getch();
                    return;
                }
                printf("\nFound %d students:\n", count);
                for (int i = 0; i < count; i++)
                {
                    int idx = matches[i];
                    printf("[%d] Name: %s | ID: %d | Class: %d\n", i, s1[idx].name, s1[idx].id, s1[idx].classes);
                }
                int choice;
                printf("Select index (or -1 to cancel): ");
                scanf("%d", &choice);

                if (choice == -1)
                {
                    hello();
                    return;
                }

                if (choice >= 0 && choice < count)
                {
                    int t = matches[choice];
                    printf("\nSelected Student:\n");
                    printf("Name :- %s\n", s1[t].name);
                    printf("ID :- %d\n", s1[t].id);
                    printf("Class :- %d\n", s1[t].classes);

                    _getch();
                    hello();
                }
                else
                {
                    printf("Invalid choice ❌\n");
                    _getch();
                    hello();
                }
            }
            else if (strcmp(n, "class") == 0)
            {
                int cls;
                printf("Enter class: ");
                scanf("%d", &cls);
                searching();
                // Assuming max 10 students, adjust if 'size' can be larger than 10
                int matches[size];
                int count = 0;

                for (int i = 0; i < lan; i++)
                {
                    if (s1[i].classes == cls)
                    {
                        matches[count++] = i;
                    }
                }

                if (count == 0)
                {
                    printf("No students found\n");
                    _getch();
                    hello();
                    return;
                }

                printf("\nFound %d students:\n", count);
                for (int i = 0; i < count; i++)
                {
                    int idx = matches[i];
                    printf("[%d] Name: %s | ID: %d\n", i, s1[idx].name, s1[idx].id);
                }

                int choice;
                printf("Select index: ");
                scanf("%d", &choice);

                if (choice >= 0 && choice < count)
                {
                    int t = matches[choice];

                    printf("\nSelected Student:\n");
                    printf("Name :- %s\n", s1[t].name);
                    printf("ID :- %d\n", s1[t].id);
                    printf("Class :- %d\n", s1[t].classes);
                    _getch();
                    hello();
                }
                else
                {
                    printf("Invalid choice\n");
                    _getch();
                    hello();
                }
            }
        } // Closing brace for else if (strcmp(n,"name")==0||strcmp(n,"class")==0)
    } }// Closing brace for while(1)
