#include <iostream>

using std::cout;
using std::cin;
using std::endl;


struct listNode {
    int studentNum;
    int grade;
    listNode * next;
};

typedef listNode * studentCollection;

void printNodes(studentCollection sc);
void addRecord(studentCollection& sc, int studNum, int gr);
void removeRecord(studentCollection& sc, int studNum);
double averageRecord(studentCollection sc);


int main()
{
    studentCollection sc = nullptr;
    addRecord(sc, 1001, 78);
    addRecord(sc, 1012, 93);
    addRecord(sc, 1076, 85);

    cout << "The nodes: " << endl;
    printNodes(sc);


    cout << "The nodes after removing student nr. 1012: " << endl;
    removeRecord(sc, 1012);
    printNodes(sc);

    cout << "The average record is: " << averageRecord(sc) << endl;

    cin.get();
    return 0;

}


void addRecord(studentCollection& sc, int studNum, int gr)
{
    listNode * newNode = new listNode;
    newNode->studentNum = studNum;
    newNode->grade = gr;
    newNode->next = sc;
    sc = newNode;
}


void removeRecord(studentCollection& sc, int studNum)
{
    if (sc == nullptr) return;

    listNode * loopPtr = sc;

    if (loopPtr->studentNum == studNum)
    {
        sc = loopPtr->next;
        delete loopPtr;
    }
    else
    {
        while (loopPtr->next != nullptr)
        {
            if (loopPtr->next->studentNum == studNum)
            {
                listNode * deleteNode = loopPtr->next;
                loopPtr->next = loopPtr->next->next;
                delete deleteNode;
                break;
            }
            else
            {
                loopPtr = loopPtr->next;
            }
        }
    }
    return;
}

void printNodes(studentCollection sc)
{
    listNode * loopPtr = sc;
    while (loopPtr != nullptr)
    {
        printf("Student nr: %d  grade: %d \n", loopPtr->studentNum, loopPtr->grade);
        loopPtr = loopPtr->next;
    }
}


double averageRecord(studentCollection sc)
{
    if (sc == nullptr) return 0;
    int count = 0;
    double sum = 0;
    listNode * loopPtr = sc;
    while (loopPtr != nullptr)
    {
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    double average = sum / count;
    return average;
}

