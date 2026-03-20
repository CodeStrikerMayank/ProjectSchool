#ifndef OPERATION_H
#define OPERATION_H
struct Student
{
    int id;
    char name[100];
    char grades;
    int classes;
};
void display(struct Student s1[],int size);

#endif