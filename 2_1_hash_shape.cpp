#include <sstream>
#include <iostream>
#include <iomanip>

/*
Hash shape by using only single cout functions.
*/

using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{

    int shapeWidth = 8;

    for (int row = 0; row < 4; row++) {
        cout << setw(row+1);
        for(int hashNum = 0; hashNum < shapeWidth-2*row; hashNum++) {
            cout << "#";
        }
        cout << "\n";
    }
}
