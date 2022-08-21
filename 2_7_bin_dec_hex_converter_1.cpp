#include <iostream>
#include <string>

/*
Dec hex bin conversion with strings

*/

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::getline;

string decimalToBinary(int dec);
string decimalToHex(int dec);

int binaryToDecimal(string bin);
string binaryToHex(string bin);

int hexToDecimal(string hex);
string hexToBinary(string hex);


int main()
{

    int dec;
    cout << "Type in decimal number and convert it to binary and hexadecimal:\n";
    cin >> dec;
    cin.ignore();

    string bin = decimalToBinary(dec);

    cout << "The binary of " << dec << " is " << bin << endl;

    string hex = decimalToHex(dec);

    cout << "The hexadecimal of " << dec << " is " << hex << endl;


    cout << "Type in binary number and convert it to decimal and hexadecimal:\n";
    getline(cin, bin, '\n');

    dec = binaryToDecimal(bin);

    cout << "The decimal of " << bin << " is " << dec << endl;

    hex = binaryToHex(bin);

    cout << "The hexadecimal of " << bin << " is " << hex << endl;


    cout << "Type in hexadecimal number and convert it to decimal and binary:\n";
    getline(cin, hex, '\n');

    dec = hexToDecimal(hex);

    cout << "The decimal of " << hex << " is " << dec << endl;

    bin = hexToBinary(hex);

    cout << "The binary of " << hex << " is " << bin << endl;




}

string decimalToBinary(int dec=0)
{
    int temp = dec;
    char digit = '0';
    string binPart;
    string bin;

    do {
        binPart = "0000";
        for(int i = 3; i >= 0; i--)
        {
            digit = temp % 2 + '0';
            binPart[i] = digit;
            temp /= 2;
            if(!temp) break;
        }

        bin = temp ? " " + binPart + bin: binPart + bin;

    } while (temp);
    return bin;
}



string decimalToHex(int dec=0)
{
    int temp = dec;
    char digit = '0';
    string hex;
    int rest = 0;
    int i = 4; //Counting for digit space


    do {
        i--;
        rest = temp % 16;
        digit = rest < 10 ? rest + '0': rest + 'A' - 10;
        hex = digit + hex;
        temp /= 16;
        if (temp && i == 0)
        {
            hex = " " + hex;
            i=4;
        }

    } while (temp);
    return hex;
}


int binaryToDecimal(string bin)
{
    int dec = 0;
    int digit;

    int length = bin.size();

    for(int i = 0; i < length; i++)
    {
        if (bin[i] == ' ') continue;
        digit = bin[i] - '0';
        dec = dec*2 + digit;
    }
    return dec;
}



string binaryToHex(string bin)
{
    /*int dec = binaryToDecimal(bin);

    string hex = decimalToHex(dec);

    return hex;*/

    string hex;
    char digit;

    int length = bin.size()-1;

    if (!length) hex = "0000";

    int temp = 1;
    int dec = 0;
    int j = 4; //index to count nr of binary digits left (4 binary digit is one hex digit)
    int k = 4; //hex index to control spaces

    for(int i = length; i >=0; i--)
    {
        if (bin[i] == ' ') continue;
        digit = bin[i];
        if (digit == '0') {
            temp *= 2;
        }
        if (digit == '1') {
            dec += temp;
            temp *= 2;
        }

        j--;
        if (j == 0 || i == 0) {
            int rest = dec % 16;
            digit = rest < 10 ? rest + '0': rest + 'A' - 10;
            j = 4;
            dec = 0; temp = 1;
            hex = digit + hex;
            k--;
            if (k==0 && i > 0)
            {
                hex = " " + hex;
                k = 4;
            }
        }
    }
    return hex;
}





string hexToBinary(string hex)
{
    /*int dec = binaryToDecimal(bin);

    string hex = decimalToHex(dec);

    return hex;*/

    string bin;
    string binPart;
    char ch;

    int length = hex.size();

    if (!length) bin = "0000";

    for (int i = 0; i < length; i++)
    {
        ch = hex[i];

		if (ch == ' ') continue;

        switch(ch)
        {
            case '0': binPart = "0000"; break;
            case '1': binPart = "0001"; break;
            case '2': binPart = "0010"; break;
            case '3': binPart = "0011"; break;
            case '4': binPart = "0100"; break;
            case '5': binPart = "0101"; break;
            case '6': binPart = "0110"; break;
            case '7': binPart = "0111"; break;
            case '8': binPart = "1000"; break;
            case '9': binPart = "1001"; break;
            case 'A': binPart = "1010"; break;
            case 'B': binPart = "1011"; break;
            case 'C': binPart = "1100"; break;
            case 'D': binPart = "1101"; break;
            case 'E': binPart = "1110"; break;
            case 'F': binPart = "1111"; break;
            default: binPart = "error"; break;
        }

        bin += i <= length ? binPart + " " : binPart;
    }
    return bin;
}



int hexToDecimal(string hex)
{
    int dec = 0;
    int digit;

    int length = hex.size();

    for(int i = 0; i < length; i++)
    {
        if (hex[i] == ' ') continue;
        digit = hex[i] < 'A' ? hex[i] - '0': hex[i] - 'A' + 10;
        dec = dec*16 + digit;
    }
    return dec;

}


