#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "colour.h"
#include "operation.h"
#include <windows.h>

void display(struct Student s1[], int size){ 
    int st;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    printf("Id no");
    scanf("%d",&st);
    if (st < 0 || st >= size) {
        printf(red "Error: Invalid ID number. Please enter an ID within the valid range.\n" reset);
        Sleep(2000);
        return;
    }
    system("cls");
    printf(green);
    printf("\n+------+------+--------+");
    printf("\nName :- %s\n",s1[st].name);
    printf("Class :- %d\n",s1[st].classes);
    printf("Rollnumber :- %d\n",s1[st].id);
    printf("Grades :- %c\n",s1[st].grades);
    printf("+------+------+--------+");
    printf(reset);
    printf("\nPress any key to continue...");
    _getch();
}

void infoboard(struct Student s1[],struct marks s2[],int size){
    int st;
    printf("Id no");
    scanf("%d",&st);
    if (st < 0 || st >= size) {
        printf(red "Error: Invalid ID number. Please enter an ID within the valid range.\n" reset);
        Sleep(2000);
        return;
    }
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
}

void wtboard(struct Student s1[],struct marks s2[],int key,int arr[], int len){
    char *str[3]={"FAILED STUDENTS","AVERAGE STUDENTS","HIGH SCORE STUDENT"};
    printf("\n%45s\n", str[key]);
    
    printf("========================================================================================\n");
    printf("| %-3s | %-20s | %-7s | %-6s | %-4s | %-8s | %-6s | %-5s |\n",
        "ID", "STUDENT NAME", "ENGLISH", "HINDI", "SST", "SCIENCE", "MATHS", "AVG");
    printf("----------------------------------------------------------------------------------------\n");

    for(int i = 0; i < len; i++){
        float avg = (s2[arr[i]].eng + s2[arr[i]].maths + s2[arr[i]].hindi + s2[arr[i]].science + s2[arr[i]].sst) / 5.0;

        printf("| %-3d | %-20s | %-7d | %-6d | %-4d | %-8d | %-6d | %-5.2f |\n",
            s1[arr[i]].id, s1[arr[i]].name, s2[arr[i]].eng, s2[arr[i]].hindi, s2[arr[i]].sst, s2[arr[i]].science, s2[arr[i]].maths, avg);
    }
    printf("========================================================================================\n");
    printf("Press any key to return ↩");
    _getch();
}
void sortersearch(struct Student s1[],struct  marks s2[],int size){
    int num;
    while(1){
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
        scanf("%d",&num);
        if (num==1){
            int key = 0;
            int k = 0;
            for (int i = 0;i<size;i++){
                int avg = (s2[i].eng+s2[i].maths+s2[i].hindi+s2[i].science+s2[i].sst)/5;
                if (avg<33){
                    arr[k] = i;
                    k++;
                }
            }
            wtboard(s1,s2,key,arr,k);
        }
        else if (num ==2 ){
            int key = 1;
            int k = 0;
            for (int i=0;i<size;i++){
                int avg =(s2[i].eng+s2[i].maths+s2[i].hindi+s2[i].science+s2[i].sst)/5;
                if (avg > 33 && avg < 80){
                    arr[k]= i;
                    k++;
                }
            }
            wtboard(s1,s2,key,arr,k);
        }
        else if (num==3){
            int key = 2;
            int k = 0;
            for (int i=0;i<size;i++){
                int avg =(s2[i].eng+s2[i].maths+s2[i].hindi+s2[i].science+s2[i].sst)/5;
                if (avg>80){
                    arr[k]= i;
                    k++;
                }
            }
            wtboard(s1,s2,key,arr,k);
        }
        else if (num ==4){printf("coming soon");}
        else if (num == 5){  printf("coming soon");}
        else if (num == 6){break; }
        else {
            printf(red "Caution use available inputs !" reset);
            Sleep(1000);
        }
    }
}
void deepsearch(struct Student s1[],struct marks s2 ){
    while(1){
        system("cls");
        int lan = sizeof(s1)/sizeof(s1[0]);
        printf("=================Control protocol for deep search=================");
        printf(">>>User-->");
        char* n[100] ;
        scanf("%s",&n);
        if (strcmp(n,"id")==0){
            while(1){int t ;
                printf("id = ");
                scanf("%d",&t);
                if (t>0&&t<lan){
                    
                }
            }
        }        
    }
}