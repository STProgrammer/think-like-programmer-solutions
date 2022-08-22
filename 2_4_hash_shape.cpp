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
    enum lr {LEFT, RIGHT, NEXT};
    enum part {UPPER, MIDDLE, BELT, BOTTOM};

    int starSizeParam = 40;

    int change = 2;
    int space = 5;
    int indent = 3.1*starSizeParam/2-1;
    int indentChange = -1;
    int spaceChange = 8;
    int extraIndent = 4;
    int pos = LEFT;
    int part = UPPER;



    for (int hashWidth=2; hashWidth > 0; hashWidth+=change)
    {
        pos = LEFT;
        cout << part;

        while (pos != NEXT)
        {
            if (pos == LEFT)
            {
                cout << setw(indent+extraIndent);
                indent += indentChange;
            }
            else
            {
                cout << setw(space);
                space += spaceChange;
            }
            for (int hashNum = 0; hashNum < hashWidth; hashNum++)
            {
                cout << "#";
            }


            if (part == BOTTOM)
            {
                pos = ++pos % 3;
            }
            else
            {
                pos = NEXT;
            }

            if (pos == NEXT)
            {
                cout << "\n";
            }
        }


        if (hashWidth >= starSizeParam && part == UPPER)
        {
            change = -4;
            hashWidth = 3.1*starSizeParam;
            indent = 1;
            indentChange = 2;
            part = MIDDLE;
        }

        else if (hashWidth <= (1.8*starSizeParam) && part == MIDDLE)
        {
            hashWidth = hashWidth-4;
            change = 2;
            indentChange = -1;
            indent -= 1;
            part = BELT;
        }
        else if (hashWidth >= (2*starSizeParam) && part == BELT)
        {
            hashWidth = hashWidth/2+2;
            change = -3;
            indentChange = -1;
            //indent -= 2;
            part = BOTTOM;
        }
    }
/* (AD): Missing return statement */
    return 0;
}
