#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;
using std::pow;



int main()
{
    int dec;
    int integerSize = 32;

    cout << "Type in decimal number to convert to binary:\n";
    cin >> dec;
    cin.ignore();

    int temp = dec;



    cout << "The binary of " << dec << " is:\n";

    int c = 0;
    int n = -1;
    int digit = 0;
    while (temp) {
        n++;
        temp /= 2;
    }
    temp = dec;

    do {
        c = pow(2, n--);
        digit = (temp / c) % 2;
        cout << digit;
    } while(n >= 0);


    cout << "\nType in binary number to convert to decimal:\n";

    char ch = '0';
    dec = 0;
    int digitCount = 0;
    while(ch != 10 || digitCount >= integerSize)
    {
        ch = cin.get();
        if (ch == ' ' || ch == 10) continue;
        dec = dec*2 + ch - '0';
        digitCount++;
    }

    cout << "The decimal number is:\n";
    cout << dec;

    cin.get();
}
