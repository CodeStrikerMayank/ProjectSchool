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
void idgeneration(int *id)
{
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL)
    {
        *id = 1;
        return;
    }
    char c;
    int len = 0;
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '\n')
        {
            len++;
        }
    }
    *id = len + 1;
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
void addon()
{
    while (1)
    {
        FILE *fp = fopen("data.csv", "a");
        if (fp == NULL)
        {
            printf(bold red "Error: Could not open data.csv for writing!\n" reset);
            return;
        }
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
    printf("Saved\n");
}
void extract(struct Student s1[], struct marks s2[])
{
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL)
    {
        printf(red "NO DATA FOUND. Please add students using the enrollment portal.\n" reset);
        return; // Removed return 0; as function returns void
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

    rewind(fp); // Reset file pointer to the beginning
    int i = 0;
    while (i < size && fscanf(fp, "%d,%99[^,],%d,%c,%d,%d,%d,%d,%d\n",
                            &s1[i].id,
                            s1[i].name,
                                &s1[i].classes,
                                &s1[i].grades,
                                &s2[i].sst,
                                &s2[i].science,
                                &s2[i].maths,
                                &s2[i].hindi,
                                &s2[i].eng) == 9) // Expecting 9 successful conversions
    {
        s2[i].aid = s1[i].id;
        i++;
    }
    fclose(fp); // Close the file after reading
}
void view(struct Student s1[],struct marks s2[],int size){
    for (int i=0;i<size;i++){
        printf("%d %s %d %c %d %d %d %d %d\n ",
                                s1[i].id,
                                s1[i].name,
                                s1[i].classes, // Corrected indentation
                                s1[i].grades,  // Corrected indentation
                                s2[i].sst,     // Corrected indentation
                                s2[i].science, // Corrected indentation
                                s2[i].maths,   // Corrected indentation
                                s2[i].hindi,   // Corrected indentation
                                s2[i].eng);    // Corrected indentation
    }
}
/*int main()
{    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL)
    {
        printf(red "NO DATA FOUND. Please add students using the enrollment portal.\n" reset);
        return 0 ;
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
    struct Student s1[size];
    struct marks s2[size];
    extract(s1, s2);
    view(s1,s2,size);
    printf("%d %s %c",s1[4].id,s1[4].name,s1[4].grades);
    return 0;
}
// Removed the main function from extraction.c to resolve "multiple definition of 'main'" error.
// The primary main function is in student.c.
// int main()
// {    FILE *fp = fopen("data.csv", "r");
//     if (fp == NULL)
//     {
//         printf(red "NO DATA FOUND. Please add students using the enrollment portal.\n" reset);
//         return 0 ;
//     }
//     char c;
//     int size = 0;
//     while ((c = fgetc(fp)) != EOF)
//     {
//         if (c == '\n')
//         {
//             size++;
//         }
//     }
//     fclose(fp);
//     struct Student s1[size];
//     struct marks s2[size];
//     extract(s1, s2);
//     view(s1,s2,size);
//     printf("%d %s %c",s1[4].id,s1[4].name,s1[4].grades);
//     return 0;
// }*/
void update(struct Student s1[], struct marks s2[], int size) {
    int target_id, found = 0;
    printf("\nEnter the Student ID to update: ");
    scanf("%d", &target_id);
    cleanbuff();

    for (int i = 0; i < size; i++) {
        if (s1[i].id == target_id) {
            found = 1;
            printf("Student Found: %s. Enter new details:\n", s1[i].name);
            
            sname(s1[i].name);
            classes(&s1[i].classes);
            
            printf("Enter new Marks (SST, Science, Math, Hindi, English):\n");
            social(&s2[i].sst);
            science(&s2[i].science);
            smath(&s2[i].maths);
            shindi(&s2[i].hindi);
            seng(&s2[i].eng);
            float avg = (s2[i].sst + s2[i].science + s2[i].maths + s2[i].hindi + s2[i].eng) / 5.0;
            autograding(&avg, &s1[i].grades);
            
            break; 
    }

    if (!found) {
        printf(bold red "Error: Student ID %d not found!\n" reset, target_id);
        return;
    }
    FILE *fp = fopen("data.csv", "w");
    if (fp == NULL) {
        printf("Error saving updates!\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d,%s,%d,%c,%d,%d,%d,%d,%d\n", 
                s1[i].id, s1[i].name, s1[i].classes, s1[i].grades,
                s2[i].sst, s2[i].science, s2[i].maths, s2[i].hindi, s2[i].eng);
    }

    fclose(fp);
    printf(green "Student record updated and saved successfully!\n" reset);
}

}