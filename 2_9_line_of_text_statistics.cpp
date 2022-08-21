#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

bool checkIfPunctuation(char ch);
int checkIfVowel(char ch);

int main()
{


    cout << "Write a line of text: " << endl;
    char ch = ' ';
    int nrOfWords = 0;

    int wordLength = 0;
    int longestWordLen = 0;

    int nrOfVowels = 0;
    int highestNrOfVowels = 0;

    do {
        ch = cin.get();
        if (checkIfPunctuation(ch))
        {
            if (longestWordLen < wordLength) longestWordLen = wordLength;
            if (highestNrOfVowels < nrOfVowels) highestNrOfVowels = nrOfVowels;
            if (wordLength) nrOfWords++;
            wordLength = nrOfVowels = 0;
        } else {
            wordLength++;
            nrOfVowels += checkIfVowel(ch);
        }


    } while(ch != 10);


    cout << "The statistics: \n";
    cout << "Nr of words: " << nrOfWords << endl;
    cout << "Longest word length: " << longestWordLen << endl;
    cout << "Highest nr of vowels: " << highestNrOfVowels << endl;

    cin.get();

}


bool checkIfPunctuation(char ch)
{
    switch(ch)
    {
        case 10: return 1; break;
        case ' ': return 1; break;
        case '\'': return 1; break;
        case ',': return 1; break;
        case '.': return 1; break;
        case ':': return 1; break;
        case ';': return 1; break;
        case '-': return 1; break;
        case '\\': return 1; break;
        case '/': return 1; break;
        case '!': return 1; break;
        case '?': return 1; break;
        case '+': return 1; break;
        case '=': return 1; break;
        case '(': return 1; break;
        case ')': return 1; break;
        case '%': return 1; break;
        case '&': return 1; break;
        case '$': return 1; break;
        case '"': return 1; break;
        case '#': return 1; break;
        default: return 0; break;
    }
}




int checkIfVowel(char ch)
{
    switch(ch)
    {
        case 'a': return 1; break;
        case 'e': return 1; break;
        case 'i': return 1; break;
        case 'o': return 1; break;
        case 'u': return 1; break;
        case 'A': return 1; break;
        case 'E': return 1; break;
        case 'I': return 1; break;
        case 'O': return 1; break;
        case 'U': return 1; break;
        default: return 0; break;
    }
}
