#include <iostream> //For cout
#include <cstring>  //For the string functions
#include <stdio.h>

using std::cout;
using std::endl;

//Do not run this

struct test {
    int num;
    test * next;
};

int main()
{
    test * loopPtr = nullptr;
    test * head = nullptr;


    loopPtr = new test;
    head = loopPtr;
    loopPtr->num = 14;
    loopPtr->next = nullptr;
    cout << head->num << endl;
    loopPtr->next = new test;
    loopPtr = loopPtr->next;
    loopPtr->num = 89;

    cout << head->next->num << endl;



    return 0;
}
