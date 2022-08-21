#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
Substitution cipher, generating random cipher array, ciphering a text and converting it back, all letter UPPER-CASE.
Ciphering letters only, not punctuations. Using only arrays.
*/

int main()
{
    const int NUM_CIPHER_CHARS = 26;

    char plainText[] = "THIS IS AN EXAMPLE PLAIN TEXT. THE TEXT IS CIPHERED \n"
            "USING CHAR ARRAY WHICH IS GENERATED RANDOMLY IN CODE.";

    int textSize = sizeof(plainText);

    char cipherText[textSize];

    // Generate cipherChars randomly (exercise 3.6)
    char tempAlphabet[NUM_CIPHER_CHARS] = {
        'A','B','C','D','E','F','G','H','I','J','K',
        'L','M','N','O','P','Q','R','S','T','U','V',
        'W','X','Y','Z'
    };

    char cipherChars[NUM_CIPHER_CHARS];

    srand(time(NULL));
    int chIdx = 0;
    int randNum;

    for (int i = 0; i < NUM_CIPHER_CHARS; i++)
    {
        chIdx = i;
        while (chIdx == i || tempAlphabet[chIdx] == -1)
        {
            chIdx = rand() % 26;
        }
        cipherChars[i] = tempAlphabet[chIdx];
        tempAlphabet[chIdx] = -1;
    }



    char ch = '0';

    // Producing cipher text (exercise 3.4)
    for (int i = 0; i < textSize; i++)
    {
        if (plainText[i] < 'A' || plainText[i] > 'Z')
        {
            cipherText[i] = plainText[i];
        }
        else
        {
            cipherText[i] = cipherChars[plainText[i] - 'A'];
        }
    }

    cout << cipherText << endl;

    // Converting back to plain text (exercise 4.5)
    cout << "Converting to plain text:" << endl;

    // Array generated to find corresponding character in alphabet faster
    char cipherCharsIdxMap[NUM_CIPHER_CHARS];

    for (int i = 0; i < NUM_CIPHER_CHARS; i++)
    {
        cipherCharsIdxMap[cipherChars[i] - 'A'] = i + 'A';
    }


    char plainText2[textSize];
    plainText2[0] = '\0';


    for (int i = 0; i < textSize; i++)
    {
        if (cipherText[i] < 'A' || cipherText[i] > 'Z')
        {
            plainText2[i] = cipherText[i];
        }
        else
        {
            plainText2[i] = cipherCharsIdxMap[cipherText[i]-'A'];
            chIdx = 0;
        }
    }

    cout << plainText2 << endl;
}
