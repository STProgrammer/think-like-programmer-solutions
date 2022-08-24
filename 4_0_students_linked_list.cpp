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

void removeLinkedList(studentCollection &head);
void addRecord(studentCollection& sc, int stuNum, int gr);
double averageRecord(studentCollection sc);

int main()
{
    studentCollection sc = nullptr;
    listNode* node1 = new listNode;
    node1->studentNum = 1001;
    node1->grade = 78;
    listNode* node2 = new listNode;
    node2->studentNum = 1012;
    node2->grade = 93; listNode* node3 = new listNode;
    node3->studentNum = 1076;
    node3->grade = 85;
    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;
    node1 = node2 = node3 = nullptr;

    removeLinkedList(sc);

    cin.get();
    return 0;

}


void addRecord(studentCollection& sc, int stuNum, int gr)
{
    listNode * newNode = new listNode;
    newNode->studentNum = stuNum;
    newNode->grade = gr;
    newNode->next = sc;
    sc = newNode;
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

void removeLinkedList(studentCollection &head)
{

    listNode * loopPtr = head;
    listNode * deleteNode;

    while (loopPtr != nullptr)
    {
        deleteNode = loopPtr;
        loopPtr = loopPtr->next;
        delete deleteNode;
    }
    head = nullptr;
    return;
}
