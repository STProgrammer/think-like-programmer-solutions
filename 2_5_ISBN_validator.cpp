#include <iostream>

using std::cin;
using std::cout;

/*
ISBN validator without using arrays.
*/

/* (AD): Define a new type for enum (T_ISBNPART_ENUM) and name enums as T_ISBNPART_PREFIX, T_ISBNPART_GROUP... */
enum isbnPart {PREFIX, GROUP, REGISTRANT, PUBLICATION, CHECK, COMPLETED};

bool verifyPart(int nr, int digitCount, int part);
bool verifyCheckDigit(int nr);

int main()
{
    char digitChar;
    char ch = '0';
    int nr = 0;
    int digit = 0;
    int modulo = 0;
    int part = PREFIX;
    int digitCount = 0;
    int totalDigitCount = 0;
    int checkSum = 0;
    int pos = 1;
    bool invalidNr = false;


    cout << "Type in ISBN number. 13 digits to validate, 12 digits to get the checksum digit:\n";


    do {
            ch = cin.get();
            digitCount++;
            if(ch == '-' || ch == 10) {
                if (!verifyPart(nr, digitCount, part)) {
                    invalidNr = true;
                    break;
                }
                part = ++part % 6;
                digitCount = nr = 0;
            } else {
                nr = nr*10 + (ch - '0');
                digit = ch - '0';
                totalDigitCount++;

                checkSum += (pos % 2 == 0) ? digit * 3: digit;

                pos++;
            }

        } while(ch != 10);


    // Check if the number is too long
    if (!(part == CHECK && totalDigitCount==12) && !(part == COMPLETED && totalDigitCount==13))
    {
        invalidNr = true;
    }

    // Check if the number is valid in its format
    if (invalidNr || part < CHECK || part > COMPLETED) {
        cout << "The number is not valid!\n";
    } // Then get the checksum digit
    else if (part == CHECK) {
        int checkDigit = 10 - checkSum % 10;
        cout << "The check digit is " << checkDigit << " \n";
    } // Else check the checksum
    else if (part == COMPLETED) {
        if (checkSum % 10 == 0) {
            cout << "The ISBN is valid\n";
        } else {
            cout << "The ISBN is not valid\n";
        }
    }

}


bool verifyPart(int nr, int digitCount, int part)
{
    switch(part) {
    case PREFIX:
        return (nr == 978 || nr == 979);
        break;
    case GROUP:
        return (digitCount >= 1 && digitCount <= 5);
        break;
    case REGISTRANT:
        return (digitCount >= 1 && digitCount <= 6);
        break;
    case PUBLICATION:
        return (digitCount >= 1 && digitCount <= 7);
        break;
    case CHECK:
        return (nr < 10 || nr >= 0);
        break;
    case COMPLETED:
        return false;
        break;
    default:
        return false;
    }

}
