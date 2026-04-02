#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "operation.h"
#include <string.h>
#include <ctype.h> // For isalpha and isspace
#include "colour.h"
//? Here we can see

void cleanbuff()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
void sname(char *name)
{
    while (1)
    {
        printf(">>>Name :- ");
        fgets(name, 100, stdin);
        name[strcspn(name, "\n")] = '\0';

        if (strchr(name, '\n') == NULL && strlen(name) == 99)
        {
            cleanbuff();
        }

        int valid = 1;
        if (strlen(name) == 0)
        {
            valid = 0;
        }
        else
        {
            for (int i = 0; name[i] != '\0'; i++)
            {
                if (!isalpha(name[i]) && !isspace(name[i])) 
                {
                    valid = 0;
                    break;
                }
            }
        }

        if (valid)
        {
            break;
        }
        else
        {
            printf(bold red "User is asked to use proper naming (letters and spaces only)!\n" reset);
        }
    }
}
void classes(int *class)
{
    while (1)
    {
        printf(">>>Class :- ");
        scanf("%d", class);
        cleanbuff();
        if (*class > 0 && *class < 13)
        {
            break;
        }
        else
        {
            printf(bold red "Alert user is informed to input valid class\n" reset);
        }
    }
}
void social(int *sst)
{
    while (1)
    {
        printf(">>>SST :-");
        scanf("%d", sst);
        cleanbuff();
        if (*sst >= 0 && *sst <= 100)
        {
            break;
        }
        else
        {
            printf(bold red "Warning user is asked to use numbers between 0 -100 !\n" reset);
        }
    }
}
void science(int *sci)
{
    while (1)
    {
        printf(">>>Science :-");
        scanf("%d", sci);
        cleanbuff();
        if (*sci >= 0 && *sci <= 100)
        {
            break;
        }
        else
        {
            printf(bold red "Warning user is asked to use numbers between 0 -100 !\n" reset);
        }
    }
}
void smath(int *math)
{
    while (1)
    {
        printf(">>>Maths :-");
        scanf("%d", math);
        cleanbuff();
        if (*math >= 0 && *math <= 100)
        {
            break;
        }
        else
        {
            printf(bold red "Warning user is asked to use numbers between 0 -100 !\n" reset);
        }
    }
}
void shindi(int *hindi)
{
    while (1)
    {
        printf(">>>Hindi :-");
        scanf("%d", hindi);
        cleanbuff();
        if (*hindi >= 0 && *hindi <= 100)
        {
            break;
        }
        else
        {
            printf(bold red "Warning user is asked to use numbers between 0 -100 !\n" reset);
        }
    }
}
void seng(int *eng)
{
    while (1)
    {
        printf(">>>English :-");
        scanf("%d", eng);
        cleanbuff();
        if (*eng >= 0 && *eng <= 100)
        {
            break;
        }
        else
        {
            printf(bold red "Warning user is asked to use numbers between 0 -100 !\n" reset);
        }
    }
}
//? doubt on how it works need to  learn 
void idgeneration(int *id) {
    FILE * fp = fopen("data.csv","r");
    if (fp ==NULL ){
        *id = 1;fclose(fp);return ;
    }
    char c ;
    int len=0;
    while ((c=fgetc(fp))!=EOF){
        if (c=='\n'){len++;}
    }
    *id = len+1;
    fclose(fp);
}
void autograding(float *avg, char *grade)
{
    if (*avg <= 100 && *avg >= 85)
    {
        *grade = 'A';
    }
    else if (*avg >= 60)
    {
        *grade = 'B';
    }
    else if (*avg >= 33)
    {
        *grade = 'C';
    }
    else
    {
        *grade = 'F';
    }
}
// TODO to add autograding system and marks checker
void mte()
{
    FILE *fp;
    fp = fopen("data.csv", "a");
    if (fp == NULL)
    {
        printf(bold red "Error: Could not open data.csv for writing!\n" reset);
        return; // Corrected return type for void function
    }
    while (1)
    {
        char name[100];
        int sst, sci, eng, hindi, math, id, class;
        char grade; //* automating the id so it should be unique
        printf(red "\nNEW STUDENT ENROLL PORTAL\n" reset);

        idgeneration(&id);
        sname(name); // Pass name directly, not &name
        classes(&class);

        printf(red "\nMarks section\n" reset);
        social(&sst);
        science(&sci);
        smath(&math);
        shindi(&hindi);
        seng(&eng);

        float avg = (sst + sci + math + hindi + eng) / 5.0;

        autograding(&avg, &grade);

        printf("\nCalculated Average: %.2f | Grade: %c\n", avg, grade);

        printf(reset); 
        fprintf(fp, "%d,%s,%d,%c,%d,%d,%d,%d,%d\n", id, name, class, grade, sst, sci, math, hindi, eng);
        fclose(fp);
        printf("Data added success\n"); 
        char d;
        printf("Press Q or q to quit ");
        scanf(" %c", &d);
        if (d == 'Q' || d == 'q')
        {
            break;
        }
        cleanbuff();
    }
    fclose(fp);
    printf("Saved\n");
}
int main()
{
    mte();
    return 0;
}