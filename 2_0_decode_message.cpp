#include <iostream>

/*
Decode a message from integers to text, without using arrays or strings.
*/


using std::cin;
using std::cout;

int getModulo(int nr, int mode);
char getCharacter(int nr, int mode);
char getPunctuation(int nr);
enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};

int main()
{

    char digit;
    char ch = '0';
    int nr = 0;
    int mode = UPPERCASE;
    int modulo = 0;
    digit = cin.get();


    while(digit != 10) {
        while (!(digit == 10 || digit == ',')) {
            nr = nr*10 + digit - '0';
            digit = cin.get();
        }
        modulo = getModulo(nr, mode);
        if (modulo == 0) {
            mode = ++mode % 3;
        } else {
            ch = getCharacter(modulo, mode);
            cout << ch;
        }
        nr = 0;
        digit = cin.get();
    }

}



int getModulo(int nr, int mode) {
    if (nr == 0) return 0;
    switch(mode) {
    case UPPERCASE:
        return nr % 27;
        break;
    case LOWERCASE:
        return nr % 27;
        break;
    case PUNCTUATION:
        return nr % 9;
        break;
    default:
        return '0';
        break;
    }


}

char getCharacter(int modulo, int mode)
{
    switch(mode) {
    case 0:
        return 'A' + modulo - 1;
        break;
    case 1:
        return 'a' + modulo - 1;
        break;
    case 2:
        return getPunctuation(modulo);
        break;
    default:
        return '0';
        break;
    }
}

char getPunctuation(int modulo)
{
    switch(modulo) {
    case 1:
        return '!';
        break;
    case 2:
        return '?';
        break;
    case 3:
        return ',';
        break;
    case 4:
        return '.';
        break;
    case 5:
        return ' ';
        break;
    case 6:
        return ';';
        break;
    case 7:
        return '"';
        break;
    case 8:
        return '\'';
        break;
    default:
        return '0';
        break;
    }
}



