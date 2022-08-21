#include <iostream> //For cout
#include <cstring>  //For the string functions
#include <stdio.h>

using namespace std;

int main()
{



    double * x = new double;
    *x = 3.4;
    double y = *x;

    delete(x);
    cout << x << endl;

}

int * returnArray(int arr[])
{
    for(int i = 0; i < 10; i++)
    {
        arr[i] = 37;
    }
    return arr;
}
