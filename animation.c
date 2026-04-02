#include "operation.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "colour.h"

// TODO Loading animation here 1 loading 2 returning 3 terminating operation 4.fetching data
void loading()
{
    system("cls");
    char *hello[] = {"Loading.", "Loading..", "Loading...", "Loading...."};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            system("cls");
            printf("%s%s>>>%s%s", bold, green, hello[j], reset);
            Sleep(350);
        }
    }
}

void searching()
{
    char *hello[] = {">", ">>", ">>>", ">>>>"};
    char *toke[] = {"Searching.", "Matching Records."};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // system("cls");
            printf("\r%s %s[%-4s]%s%s", bold, yellow, hello[j], toke[i], reset);
            Sleep(400);
        }
    }
}

void time()
{
    system("cls");
    char *rotate[] = {
        "→",
        "↘",
        "↓",
        "↙",
        "←",
        "↖",
        "↑",
        "↗"};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            system("cls");
            printf("%s%s>>> Fetching Data [%s]%s ", bold, green, rotate[j], reset);
            Sleep(350);
        }
    }
}

void hello()
{
    char *tok[] = {".", "..", "...", "...."};
    system("cls");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            system("cls");
            printf("%s>>>%s Returning%s %s", bold, green, tok[j], reset);
            Sleep(300);
        }
    }
}

void welcome(){
    system("cls");
    printf("%s%s>>>%s%s\n", bold, white, "Creator - CoreShadow🤘", reset);  
    Sleep(6000);
    system("cls");
    char *hello[] = {"welcome", "wait..", "Loading.", "Loading.."};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            system("cls");
            printf("%s%s>>>%s%s", bold, green, hello[j], reset);
            Sleep(500);
        }
    }
}

void terminate(){
    system("cls");
    char *hel[] = {"Terminating.","Terminating..","Terminating...","Bye"};
    for (int i =0;i<1;i++){
        system("cls");
        for(int j =0;j<4;j++){
            system("cls");
            printf("%s%s>>>%s %s", bold, red, hel[j], reset);
            Sleep(900);
        }
    }
}