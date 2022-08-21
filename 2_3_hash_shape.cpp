#include <sstream>
#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{
    enum lr {LEFT, RIGHT, NEXT};

    int hashSizeInCenter = 4;
    int repeat = hashSizeInCenter;
    int spaceWidth = (hashSizeInCenter-1)*4+1;
    int indent = 1;
    int pos = LEFT;
    int change = 1;


    for (int width = 1; width > 0; width += change) {
        pos = LEFT;
        while (pos != NEXT) {
            if (pos == LEFT) {
                cout << setw(indent);
            }
            else {
                cout << setw(spaceWidth);
            }
            for (int hashNum = 0; hashNum < width; hashNum++)
            {
                cout << "#";
            }
            pos = ++pos % 3;
        }
        cout << "\n";
        if (width == repeat)
        {
            width += change;
            change *= -1;
            repeat = -1;
            continue;
        }
        spaceWidth -= 4*change;
        indent += change;

    }
}
