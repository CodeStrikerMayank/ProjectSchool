#include "operation.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "colour.h"

// TODO Loading animation here 1 loading 2 returning 3 terminating operation 4.fetching data
void welcome(){
    system("cls");
    printf("%s%s>>>%s%s\n", bold, white, "Creator - CoreShadow🤘", reset);  
    Sleep(6000);
    system("cls");
    char *hello[] = {"welcome", "wait..", "Loading.", "Loading.."};
    for (int i = 0; i < 1; i++)
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