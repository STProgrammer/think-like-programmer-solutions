#include <iostream>

using std::cin;
using std::cout;

/*
Luhn checksum without saving the numbers, processing each number one by one.
*/



int main()
{

    char digitChar;     /* (AD): Always initialize variables during declaration */
    int oddSum = 0;
    int evenSum = 0;
    int finalSum = 0;

    int pos = 1;
    cout << "Enter a number and press enter to validate: ";
    digitChar = cin.get();
    while (digitChar != 10)
    {
        int digit = 0;
        digit = digitChar - '0';
        /* (AD): You might have noticed that I'm using block line comment even single lines */
        /* (AD): That's because some old compilers doesn't recognize // */
        /* (AD): Most probably you'll not work with them so you can go with // */
        if (pos % 2 == 0) //If position is even from left
        {
            evenSum += digit;
            digit *= 2;
            if (digit >= 10)    /* (AD): Try to use rvalues on the left side for conditional statements. Prevents invalid assignment and gives compile error. */
            {                   /* (AD): So, lets say you want to check following equality */
                                /* (AD): if (x == 10) {....} This is OK but if you miss one '=' and write if(x = 10), no compile error, waste of time by debugging */
                                /* (AD): Do it like this: if(10 == x) {...}, if you write if(10 = x) you get compile error(10 is not an Lvalue) and fix your mistake quickly */
                digit = 1 + (digit - 10);
            }
            oddSum += digit;
            finalSum = evenSum;
        }
        else
        { //If position is odd from left
            oddSum += digit;
            digit *= 2;
            if (digit >= 10)
            {
                digit = 1 + (digit - 10);
            }
            evenSum += digit;
            finalSum = oddSum;
        }
        digitChar = cin.get();
        pos++;
        cout << "Checksum is " << finalSum << "\n";
    }
    if (finalSum % 10 == 0) {
        cout << "The digit is valid! \n";
    }
    else
    {
        cout << "The digit is invalid! \n";
    }
    /* (AD): Missing return statement is added */
    return 0;
}


