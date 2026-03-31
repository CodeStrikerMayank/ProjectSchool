#ifndef OPERATION_H
#define OPERATION_H
struct Student
{
    int id;
    char name[100];
    char grades;
    int classes;
};
struct marks{
    int aid;
    int maths;
    int science;
    int sst;
    int hindi;
    int eng ;
};
void welcome();
void loading();
void searching();
void time();
void hello();
void terminate();
void utf();
void display(struct Student s1[],int size);
void infoboard(struct Student s1[],struct marks s2[],int size);
void wtboard(struct Student s1[],struct marks s2[],int key, int arr[], int len);
void sortersearch(struct Student s1[],struct marks s2[],int size);
void deepsearch(struct Student s1[],struct marks s2[]);

#endif