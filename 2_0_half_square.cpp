#include <iostream>

using std::cin;
using std::cout;

int main()
{

    char digitChar;

    char c;

    int oddSum = 0;
    int evenSum = 0;
    int finalSum = 0;

    int i = 1;
    cout << "Enter a number and press enter to validate: ";
    digitChar = cin.get();
    while (digitChar != 10) {
        int digit = 0;
        digit = digitChar - '0';
        if (i % 2 == 0) { //If position is even from left
            evenSum += digit;
            digit *= 2;
            if (digit >= 10) {
                digit = 1 + (digit - 10);
            }
            oddSum += digit;
            finalSum = evenSum;
        } else { //If position is odd from left
            oddSum += digit;
            digit *= 2;
            if (digit >= 10) {
                digit = 1 + (digit - 10);
            }
            evenSum += digit;
            finalSum = oddSum;
        }
        digitChar = cin.get();
        i++;
        cout << "Checksum is " << finalSum << "\n";
    }
    if (finalSum % 10 == 0) {
        cout << "The digit is valid! \n";
    } else {
        cout << "The digit is invalid! \n";
    }


}


