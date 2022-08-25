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
void addDigit(intLinkedList& integer, char charDigit);
intLinkedList sumIntLists(intLinkedList integer1, intLinkedList integer2);
void removeLinkedList(intLinkedList &head);

int main()
{
    char charDigit = 0;
    intLinkedList integer1 = nullptr;

    cout << "Type in a number:\n";
    charDigit = cin.get();

    while(charDigit != 10)
    {
        addDigit(integer1, charDigit);
        charDigit = cin.get();
    }
    cout << "\nThe number is:\n";
    printInteger(integer1);



    intLinkedList integer2 = nullptr;
    charDigit = 0;
    cout << "\nType in another number:\n";

    charDigit = cin.get();
    while(charDigit != 10)
    {
        addDigit(integer2, charDigit);
        charDigit = cin.get();
    }

    cout << "\nThe number is:\n";
    printInteger(integer2);

    intLinkedList sumInteger = sumIntLists(integer1, integer2);

    cout << "\nThe sum of the numbers is:\n";
    printInteger(sumInteger);

    removeLinkedList(integer1);
    removeLinkedList(integer2);
    removeLinkedList(sumInteger);

    cin.get();
    return 0;

}


void addDigit(intLinkedList& integer, char charDigit)
{

    if (charDigit < '0' || charDigit > '9')
    {
        cout << "Wrong character" << endl;
        return;
    }
    int digit = charDigit - '0';

    listNode * newNode = new listNode;
    newNode->num = digit;
    newNode->next = integer;
    integer = newNode;
}


void printInteger(intLinkedList integer)
{
    listNode * loopPtr = integer;
    if (loopPtr != nullptr)
    {
        printInteger(loopPtr->next);
        cout << loopPtr->num;
    }
}


// Exercise 4.10
intLinkedList sumIntLists(intLinkedList integer1, intLinkedList integer2)
{
    intLinkedList head;

    int digit1 = 0;
    int digit2 = 0;
    int sumDigit = 0;


    int extraVal = 0;

    listNode * loopPtr1 = integer1;
    listNode * loopPtr2 = integer2;

    listNode * loopPtrSum = new listNode;
    head = loopPtrSum;


    while (loopPtr1 != nullptr || loopPtr2 != nullptr)
    {
        if (loopPtr1 != nullptr)
        {
            digit1 = loopPtr1->num;
            loopPtr1 = loopPtr1->next;
        }

        if (loopPtr2 != nullptr)
        {
            digit2 = loopPtr2->num;
            loopPtr2 = loopPtr2->next;
        }

        sumDigit = digit1 + digit2 + extraVal;
        if (sumDigit >= 10)
        {
            extraVal = 1;
            sumDigit = sumDigit - 10;
        }
        else
        {
            extraVal = 0;
        }

        loopPtrSum->num = sumDigit;

        digit1 = digit2 = 0;

        // Check if next digit exists
        if (loopPtr1 != nullptr || loopPtr2 != nullptr || extraVal)
        {
            loopPtrSum->next = new listNode;
        }
        else
        {
            loopPtrSum->next = nullptr;
        }
        loopPtrSum = loopPtrSum->next;
    }

    if (extraVal)
    {
        loopPtrSum->num = 1;
        loopPtrSum->next = nullptr;
    }
    return head;
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




