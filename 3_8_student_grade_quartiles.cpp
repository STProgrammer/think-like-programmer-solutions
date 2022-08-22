#include <iostream>
#define D_ARRAY_SIZE 10
#define D_NUM_QUARTILES 4

using namespace std;

struct student {
    int grade;
    int studentId;
    char name[10];
};


int studentGradeCompareFunc(const void * voidA, const void * voidB);


int main()
{
    student studentArray[D_ARRAY_SIZE] = {
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

    qsort(studentArray, D_ARRAY_SIZE, sizeOfStudentStruct, studentGradeCompareFunc);

    int quartileGrades[D_NUM_QUARTILES-1];
    int quartileIdx = 0;

    for (int i = 0; i < D_NUM_QUARTILES-1; i++)
    {
        int dividend = (i+1)*(D_ARRAY_SIZE);
        quartileIdx = dividend / D_NUM_QUARTILES;
        if (dividend % D_NUM_QUARTILES != 0)
        {
            quartileIdx += 1;
        }
        quartileGrades[i] = studentArray[quartileIdx-1].grade;
    }


    for (int i = 1; i < D_NUM_QUARTILES; i++)
    {
        printf("To be better than %d %% one would need to score higher than %d \n", (100*i)/4, quartileGrades[i-1]);
    }

    for (int i = 0; i < D_ARRAY_SIZE; i++)
    {
        printf ("%s: %d \n", studentArray[i].name, studentArray[i].grade);
    }

    cin.get();
    return 0;

}

int studentGradeCompareFunc(const void * voidA, const void * voidB)
{
    student* st1 = (student *) voidA;
    student* st2 = (student *) voidB;
    return st1->grade - st2->grade;
}
