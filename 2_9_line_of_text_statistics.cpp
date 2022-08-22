#include <iostream>
#include <string>

/*
Line of text statistics without using array or strings
*/

using std::cin;
using std::cout;
using std::endl;

bool checkIfPunctuation(char ch);
int checkIfVowel(char ch);

int main()
{
    cout << "Write a line of text: " << endl;
    char ch = 0;
    int nrOfWords = 0;

    int wordLength = 0;
    int longestWordLen = 0;

    int nrOfVowels = 0;
    int highestNrOfVowels = 0;

    do
    {
        ch = cin.get();
        if (checkIfPunctuation(ch))
        {
            if (longestWordLen < wordLength)
            {
                longestWordLen = wordLength;
            }
            if (highestNrOfVowels < nrOfVowels)
            {
                highestNrOfVowels = nrOfVowels;
            }
            if (wordLength)
            {
                nrOfWords++;
            }
            wordLength = nrOfVowels = 0;
        }
        else
        {
            wordLength++;
            nrOfVowels += checkIfVowel(ch);
        }


    } while(ch != 10);


    cout << "The statistics: \n";
    cout << "Nr of words: " << nrOfWords << endl;
    cout << "Longest word length: " << longestWordLen << endl;
    cout << "Highest nr of vowels: " << highestNrOfVowels << endl;

    cin.get();

    return 0;

}


bool checkIfPunctuation(char ch)
{
    bool result = false;

    if ((ch < 'A' || ch > 'Z') & (ch < 'a' || ch > 'z'))
    {
        result = true;
    }

    return result;
}




int checkIfVowel(char ch)
{
    bool isVowel = 0;
    switch(ch)
    {
        case 'a':
            isVowel = 1;
            break;
        case 'e':
            isVowel = 1;
            break;
        case 'i':
            isVowel = 1;
            break;
        case 'o':
            isVowel = 1;
            break;
        case 'u':
            isVowel = 1;
            break;
        case 'A':
            isVowel = 1;
            break;
        case 'E':
            isVowel = 1;
            break;
        case 'I':
            isVowel = 1;
            break;
        case 'O':
            isVowel = 1;
            break;
        case 'U':
            isVowel = 1;
            break;
        default:
            isVowel = 0;
            break;
    }
    return isVowel;
}
