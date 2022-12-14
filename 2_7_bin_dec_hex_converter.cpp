#include <iostream>
#include <math.h>

/*
Binary, hex and dec converter without using arrays.
*/

using std::cin;
using std::cout;
using std::pow;
using std::endl;

void decimalToBinary(int dec = 0);
void decimalToHex(int dec = 0);

int binaryToDecimal();
void binaryToHex(int dec = 0);

int hexToDecimal();
void hexToBinary();

int main()
{
    int choice = 1;

    while (choice != 0)
    {
        cout << "This is a simple program to convert between decimal, binary and hexadecimal numbers." << endl;

        cout << "Select number type to convert from by typing a single number and pressing enter: " << endl;
        cout << " 1) decimal \n 2) binary \n 3) hexadecimal 0) to quit \n ";

        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            int dec;
            cout << "Select type to convert decimal number to: " << endl;
            cout << " 1) binary \n 2) hexadecimal \n ";
            cin >> choice;
            cin.ignore();
            if (choice == 1)
            {
                cout << "Type in decimal number and convert it to binary:\n";
                cin >> dec;
                cin.ignore();
                cout << "The binary of " << dec << " is:" << endl;
                decimalToBinary(dec);
            }
            else if (choice == 2)
            {
                cout << "Type in decimal number and convert it to hexadecimal:\n";
                cin >> dec;
                cin.ignore();
                cout << "The hexadecimal of " << dec << " is:" << endl;
                decimalToHex(dec);
            }
            else
            {
                cout << "Your choice is invalid!\n";
            }
        }
        else if (choice == 2)
        {
            cout << "Select type to convert binary number to: " << endl;
            cout << " 1) decimal \n 2) hexadecimal \n ";
            cin >> choice;
            cin.ignore();
            if (choice == 1)
            {
                cout << "Type in binary number and convert it to decimal:\n";
                int dec = binaryToDecimal();
                cout << "The decimal number is:\n";
                cout << dec << endl;
            }
            else if (choice == 2)
            {
                cout << "Type in binary number and convert it to hexadecimal:\n";
                binaryToHex();
            }
            else
            {
                cout << "Your choice is invalid!\n";
            }
        }
        else if (choice == 3)
        {
            cout << "Select type to convert hexadecimal number to: " << endl;
            cout << " 1) decimal \n 2) binary \n ";
            cin >> choice;
            cin.ignore();
            if (choice == 1)
            {
                cout << "Type in hexadecimal number and convert it to decimal:\n";
                int dec = hexToDecimal();
                cout << "The decimal number is:\n";
                cout << dec << endl;
            }
            else if (choice == 2)
            {
                cout << "Type in hexadecimal number and convert it to binary:\n";
                hexToBinary();
            }
            else
            {
                cout << "Your choice is invalid!\n";
            }
        }
        else
        {
            cout << "Your choice is invalid!\n";
        }
        cout << "Do you want to repeat? Press any number and enter to repeat, press 0 and enter to quit.\n";
        cin >> choice;
        cin.ignore();
    }

    return 0;
}


void decimalToBinary(int dec)
{
    int temp = dec;
    int c = 0;
    int n = -1;
    int digit = 0;
    while (temp)
    {
        n++;
        temp /= 2;
    }
    temp = dec;

    do {
        c = pow(2, n--);
        digit = (temp / c) % 2;
        cout << digit;
    } while(n >= 0);

    cout << "\n";
}


void decimalToHex(int dec)
{
    int temp = dec;
    int c = 0;
    int n = -1;
    int digit = 0;
    char charDigit = 0;

    while (temp)
    {
        n++;
        temp /= 16;
    }
    temp = dec;

    do
    {
        c = pow(16, n--);
        digit = (temp / c) % 16;
        charDigit = digit < 10 ? '0' + digit: digit + 'A' - 10;
        cout << charDigit;
    } while(n >= 0);

    cout << "\n";
}


int binaryToDecimal()
{
    int digitSize = 32;
    char ch = 0;
    int dec = 0;
    int digitCount = 0;
    while(ch != 10 || digitCount >= digitSize)
    {
        ch = cin.get();
        if (ch == ' ' || ch == 10) continue;
        dec = dec*2 + ch - '0';
        digitCount++;
    }
    return dec;
}


void binaryToHex(int dec)
{
    if(!dec)
    {
        dec = binaryToDecimal();
    }
    decimalToHex(dec);
}


int hexToDecimal()
{
    int digitSize = 8;
    char ch = 0;
    int dec = 0;
    int digitCount = 0;
    while(ch != 10 || digitCount >= digitSize)
    {
        ch = cin.get();
        if (ch == ' ' || ch == 10) continue;
        dec *= 16;
        dec += ch < 'A' ? ch - '0': ch - 'A' + 10;
        digitCount++;
    }
    return dec;
}



void hexToBinary()
{
    char charDigit = 0;

    while(charDigit != 10)
    {
        charDigit = cin.get();
        if (charDigit == ' ' || charDigit == 10)
        {
            continue;
        }
        switch(charDigit)
        {
            case '0': cout << "0000 "; break;
            case '1': cout << "0001 "; break;
            case '2': cout << "0010 "; break;
            case '3': cout << "0011 "; break;
            case '4': cout << "0100 "; break;
            case '5': cout << "0101 "; break;
            case '6': cout << "0110 "; break;
            case '7': cout << "0111 "; break;
            case '8': cout << "1000 "; break;
            case '9': cout << "1001 "; break;
            case 'A': cout << "1010 "; break;
            case 'B': cout << "1011 "; break;
            case 'C': cout << "1100 "; break;
            case 'D': cout << "1101 "; break;
            case 'E': cout << "1110 "; break;
            case 'F': cout << "1111 "; break;
            default: cout << ""; break;
        }

    }
}






