#include <sstream>
#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{

    int shapeWidth = 8;
    int repeat = shapeWidth;
    int change = 2;


    for (int width = 2; width > 0; width+=change) {
        cout << setw((shapeWidth - width)/2+1);
        for(int hashNum = 0; hashNum < width; hashNum++) {
            cout << "#";
        }
        cout << "\n";
        if (width == repeat)
        {
            width += 2;
            change *= -1;
            repeat = -1;
            continue;
        }
    }
}
