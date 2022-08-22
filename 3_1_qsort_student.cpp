#include <iostream>


/*
Using QSORT to sort student structs based on grades and Student ID
*/

using namespace std;

struct student {
    int grade;
    int studentId;
    char name[10];
};

int studentIdCompareFunc(const void * student1, const void * student2);
int studentGradeCompareFunc(const void * voidA, const void * voidB);

int main()
{
    const int ARRAY_SIZE = 10;  /* (AD): Prefer "#define D_ARRAY_SIZE 10" at top. */
    student studentArray[ARRAY_SIZE] = {
        {81, 10009, "Aretha"},
        {70, 10008, "Candy"},
        {68, 10010, "Veronica"},
        {78, 10004, "Sasha"},
        {75, 10007, "Leslie"},
        {100, 10003, "Alistair"},
        {98, 10006, "Belinda"},
        {84, 10005, "Erin"},
        {28, 10002, "Tom"},
        {87, 10001, "Fred"},
    };

    int sizeOfStudentStruct = sizeof(student);

    qsort(studentArray, ARRAY_SIZE, sizeOfStudentStruct, studentIdCompareFunc);

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf ("%d (%s) ", studentArray[i].studentId, studentArray[i].name);
    }

    cout << "\nThe top grades are:\n";

    qsort(studentArray, ARRAY_SIZE, sizeOfStudentStruct, studentGradeCompareFunc);

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf ("%s: %d \n", studentArray[i].name, studentArray[i].grade);
    }
/* (AD): Missing return statement */
    return 0;
}


int studentIdCompareFunc(const void * voidA, const void * voidB)
{
    student* st1 = (student *) voidA;
    student* st2 = (student *) voidB;
    return st1->studentId - st2->studentId;
}

int studentGradeCompareFunc(const void * voidA, const void * voidB)
{
    student* st1 = (student *) voidA;
    student* st2 = (student *) voidB;
    return st2->grade - st1->grade;
}

