#include <iostream>
#include <string>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;
using std::pow;


void numberConverter(int baseX, int baseY);
int toDecimalConverter(int baseX);
void fromDecimalConverter(int dec, int baseY);


int main()
{
    int baseX, baseY;

    cout << "Type in the base of the number to convert from:\n";
    cin >> baseX;
    cin.ignore();

    cout << "Type in the base you'll convert to:\n";
    cin >> baseY;
    cin.ignore();

    cout << "Type in the number: \n";

    numberConverter(baseX, baseY);
}


void numberConverter(int baseX, int baseY)
{
    int dec = toDecimalConverter(baseX);

    fromDecimalConverter(dec, baseY);
}


int toDecimalConverter(int baseX)
{
    int digitSize = 64 / baseX;
    char ch = '0';
    int dec = 0;
    int digit = 0;
    int digitCount = 0;
    cout << "Before while loop" << endl;
    while(ch != 10 && digitCount <= digitSize)
    {
        ch = cin.get();
        if (ch == ' ' || ch == 10) continue;
        digit = ch < 'A' ? ch - '0': ch - 'A' + 10;
        dec = dec*baseX + digit;
        digitCount++;

    }
    cout << "After while loop" << endl;
    return dec;
}


void fromDecimalConverter(int dec, int baseY)
{
    int temp = dec;
    int c = 0;
    int n = -1;
    int digit = 0;
    char charDigit = '0';

    while (temp) {
        n++;
        temp /= baseY;
    }
    temp = dec;

    cout << "The number is:" << endl;

    do {
        c = pow(baseY, n--);
        digit = (temp / c) % baseY;
        charDigit = digit < 10 ? '0' + digit: digit + 'A' - 10;
        cout << charDigit;
    } while(n >= 0);

    cout << "\n";
}
