#include <iostream>

using std::cout;
using std::cin;
using std::endl;


struct listNode {
    int num;
    listNode * next;
};

typedef listNode * intLinkedList;

void printInteger(intLinkedList integer);
intLinkedList intToList(int num);
intLinkedList sumIntLists(intLinkedList integer1, intLinkedList integer2);
void removeLinkedList(intLinkedList &head);

int main()
{
    int num1 = 78;
    int num2 = 14;
    intLinkedList integer1 = intToList(num1);
    intLinkedList integer2 = intToList(num2);
    intLinkedList sum = sumIntLists(integer1, integer2);

    cout << "\nInteger one: ";
    printInteger(integer1);
    cout << "\nInteger two: ";
    printInteger(integer2);
    cout << "\nTheir sum is: ";
    printInteger(sum);

    removeLinkedList(integer1);
    removeLinkedList(integer2);
    removeLinkedList(sum);

    cin.get();
    return 0;

}

// Exercise 4.9
intLinkedList intToList(int num)
{
    if (num < 0)
    {
        num = 0;
    }

    intLinkedList head = nullptr;

    do {
        listNode * newNode = new listNode;
        newNode->num = num % 10;
        num /= 10;
        newNode->next = head;
        head = newNode;
    } while (num);

    return head;
}


// Exercise 4.10
intLinkedList sumIntLists(intLinkedList integer1, intLinkedList integer2)
{
    int num1 = 0;
    int num2 = 0;
    int sum = 0;


    listNode * loopPtr = integer1;
    while (loopPtr != nullptr)
    {
        num1 *= 10;
        num1 += loopPtr->num;
        loopPtr = loopPtr->next;
    }

    loopPtr = integer2;
    while (loopPtr != nullptr)
    {
        num2 *= 10;
        num2 += loopPtr->num;
        loopPtr = loopPtr->next;
    }

    sum = num1 + num2;

    return intToList(sum);
}


void printInteger(intLinkedList integer)
{
    listNode * loopPtr = integer;
    while (loopPtr != nullptr)
    {
        cout << loopPtr->num;
        loopPtr = loopPtr->next;
    }
}

void removeLinkedList(intLinkedList &head)
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



