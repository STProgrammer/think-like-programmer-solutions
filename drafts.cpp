#include <iostream> //For cout
#include <cstring>  //For the string functions
#include <stdio.h>

using std::cout;
using std::endl;

//Do not run this

int main()
{

    int *p = new int[2];
    p[0] = 14;
    p[1] = 19;

    int* t = new int[2];
    t[0] = 14;
    t[1] = 17;

    cout << (*t == *p) << endl;

    return 0;
}
