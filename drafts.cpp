#include <iostream> //For cout
#include <cstring>  //For the string functions
#include <stdio.h>

using std::cout;

//Do not run this

int count = 0;
void stackOverflow()
{
    cout << ++count << " ";
    stackOverflow();
}

int main()
{
    stackOverflow();
    return 0;
}
