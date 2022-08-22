#include <iostream>

/*
Decode a message from integers to text, without using arrays or strings.
*/


using std::cin;
using std::cout;

int getModulo(int nr, int mode);
char getCharacter(int nr, int mode);
char getPunctuation(int nr)
enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};



int main()
{
    char digit = 0;
    char ch = 0;
    int nr = 0;
    int mode = UPPERCASE;
    int modulo = 0;
    digit = cin.get();

    while(digit != 10)
    {
        while (!(digit == 10 || digit == ','))
        {
            nr = nr*10 + digit - '0';
            digit = cin.get();
        }
        modulo = getModulo(nr, mode);
        if (modulo == 0)
        {
            mode = ++mode % 3;
        }
        else
        {
            ch = getCharacter(modulo, mode);
            cout << ch;
        }
        nr = 0;
        digit = cin.get();
    }
    cin.get();
    return 0;
}


int getModulo(int nr, int mode)
{
    int modulo = 0;
    if (nr == 0) return 0;
    switch(mode)
    {
        case UPPERCASE:
            modulo = nr % 27;
            break;
        case LOWERCASE:
            modulo = nr % 27;
            break;
        case PUNCTUATION:
            modulo = nr % 9;
            break;
        default:
            modulo = 0;
            break;
    }
    return modulo;
}


char getCharacter(int modulo, int mode)
{
    char ch = 0;
    switch(mode)
    {
        case 0:
            ch = 'A' + modulo - 1;
            break;
        case 1:
            ch = 'a' + modulo - 1;
            break;
        case 2:
            ch = getPunctuation(modulo);
            break;
        default:
            ch = 0;
            break;
    }
    return ch;
}

/* (AD): GetPunctuation, single return statement, move '{' to one line below. */
char getPunctuation(int modulo)
{
    char punct = 0;
    switch(modulo)
    {
        case 1:
            punct = '!';
            break;
        case 2:
            punct = '?';
            break;
        case 3:
            punct = ',';
            break;
        case 4:
            punct = '.';
            break;
        case 5:
            punct = ' ';
            break;
        case 6:
            punct = ';';
            break;
        case 7:
            punct = '"';
            break;
        case 8:
            punct = '\'';
            break;
        default:
            punct = 0;
            break;
    }
    return punct;
}



