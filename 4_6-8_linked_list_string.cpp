#include <iostream>

using std::cout;
using std::cin;
using std::endl;


struct listNode {
    char ch;
    listNode * next;
};

typedef listNode * stringLinkedList;

void append(stringLinkedList& str, char ch);
char characterAt(stringLinkedList str, int pos);
void printString(stringLinkedList str);
void concatenate(stringLinkedList &str1, stringLinkedList str2);
void removeChars(stringLinkedList &str, int startIdx, int nrOfChars);
void removeLinkedList(stringLinkedList &head)

int main()
{
    stringLinkedList str = nullptr;



    append(str, 'T');
    append(str, 'e');
    append(str, 's');
    append(str, 't');

    printString(str);

    printf("\nCharacter at index %d in \"Test\" is %c \n", 2, characterAt(str, 2));

    stringLinkedList str2 = nullptr;
    //stringLinkedList str1 = nullptr;

    append(str2, 'b');
    append(str2, 'e');
    append(str2, 'd');

    printString(str2);

    concatenate(str, str2);

    cout << "\nNew concatenated string: " << endl;
    printString(str);
    cout << "\n" << (void*) str << " " << (void*)str2 << endl;

    int startIdx = 1;
    int nrOfChars = 2;

    removeChars(str, startIdx, nrOfChars);

    printf("Removed %d characters starting from index %d running removeChars() function:\n", nrOfChars, startIdx);
    printString(str);

    removeLinkedList(str);
    removeLinkedList(str2);

    cin.get();
    return 0;
}



void append(stringLinkedList& str, char ch)
{
    listNode * newNode = new listNode;
    newNode->next = nullptr;
    newNode->ch = ch;

    if (str == nullptr)
    {
        str = newNode;
    }
    else
    {
        listNode * loopPtr = str;
        while (loopPtr->next != nullptr)
        {
            loopPtr = loopPtr->next;
        }
        loopPtr->next = newNode;
    }

}



void printString(stringLinkedList str)
{
    listNode * loopPtr = str;
    while (loopPtr != nullptr)
    {
        cout << loopPtr->ch;
        loopPtr = loopPtr->next;
    }

}


char characterAt(stringLinkedList str, int pos)
{
    int cnt = 0;
    listNode * loopPtr = str;
    while (loopPtr != nullptr && cnt < pos)
    {
        loopPtr = loopPtr->next;
        cnt++;
    }
    if (cnt == pos)
    {
        return loopPtr->ch;
    }
    else
    {
        return 0;
    }
}


// Exercise 4.8 remove multiple characters from linked list strings.
void removeChars(stringLinkedList &str, int startIdx, int nrOfChars)
{
    // Find start index
    listNode * loopPtr = str;
    if (loopPtr == nullptr)
    {
        return;
    }

    int posCounter = 0;
    int deleteCounter = 0;
    listNode * tempPtr = loopPtr;

    while (loopPtr != nullptr && posCounter < startIdx)
    {
        tempPtr = loopPtr;
        loopPtr = loopPtr->next;
        posCounter++;
    }

    //loopPtr = loopPtr->next;
    listNode * deletePtr;

    // Remove the chars until end
    if (posCounter == startIdx)
    {
        while (loopPtr != nullptr && deleteCounter < nrOfChars)
        {
            deletePtr = loopPtr;
            loopPtr = loopPtr->next;
            delete deletePtr;
            deleteCounter++;
        }
        if (startIdx == 0)
        {
            str = loopPtr;
        }
        else
        {
            tempPtr->next = loopPtr;
        }

    }
}


// Exercise 4.7 concatenate linked list strings.
void concatenate(stringLinkedList &str1, stringLinkedList str2)
{
    // Loop to tail
    listNode * loopPtr = str1;
    listNode * loopPtr2 = str2;

    if (loopPtr != nullptr)
    {
        while (loopPtr->next != nullptr)
        {
            loopPtr = loopPtr->next;
        }
    }
    else
    {
        if (str2 != nullptr)
        {
            str1 = new listNode;
            str1->ch = str2->ch;
            loopPtr = str1;
            loopPtr2 = str2->next;
        }
    }

    while (loopPtr2 != nullptr)
    {
        loopPtr->next = new listNode;
        loopPtr = loopPtr->next;
        loopPtr->ch = loopPtr2->ch;
        loopPtr->next = nullptr;
        loopPtr2 = loopPtr2->next;
    }

}


void removeLinkedList(stringLinkedList &head)
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





