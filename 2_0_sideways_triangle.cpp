#include <iostream>

/*
Write a program that uses only two output statements,
cout << "#" and cout << "\ n", to produce a pattern of
hash symbols shaped like a sideways triangle:

#
##
###
####
###
##
#


*/

using std::cout;


int main()
{
    int nrOfRows = 7;
    int width = nrOfRows / 2;

    for (int row = 0; row < nrOfRows; row++)
    {
        cout << "\n";
        for (int hashNum = 1; hashNum <= (width+1) - abs(row - width); hashNum++)
        {
            cout << "#";
        }
    }
    /* (AD): Missing return statement */
    return 0;
}


