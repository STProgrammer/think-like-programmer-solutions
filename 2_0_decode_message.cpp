#include <iostream>

/*
Decode a message from integers to text, without using arrays or strings.
*/


using std::cin;
using std::cout;

int getModulo(int nr, int mode);            /* (AD): Functions are cammelCase BUT their first letter should be capital as well GetModulo */
char getCharacter(int nr, int mode);        /* (AD): Functions are cammelCase BUT their first letter should be capital as well GetCharacter */
char getPunctuation(int nr);                /* (AD): Functions are cammelCase BUT their first letter should be capital as well GetPunctuation */
enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};  /* (AD): I prefer following enumeration, because this type is passed to func as an argument. */



/*
typedef enum mode                           (AD): Works for both C and C++.
{
    T_MODE_UPPERCASE = 0,                   (AD): Always initialize first enum eventhough it is already 0
    T_MODE_LOWERCASE,                       (AD): Other people can understand it's a typedef enum by seeing 'T' and 'ENUM'
    T_MODE_PUNCTUATION                      You can use '_' between words in enums, constant definitons, typedefs
}T_MODE_ENUM;
*/


/* Constant definitions
#define D_LIMIT_MAX 100                     (AD): So other people can understand it's constant def by seeing 'D' all capital naming.
#define D_LIMIT_MIN 0
*/



int main()
{

    char digit;                             /* (AD): Always initialize variables during declaration. */
    char ch = '0';
    int nr = 0;
    int mode = UPPERCASE;                   /* (AD): Why don't you make a typedef enum as above and use it for mode --> T_MODE_ENUM mode = UPPERCASE; */
    int modulo = 0;
    digit = cin.get();

    /* (AD): Don't worry about the code lines, move '{' to one line below such that it becomes aligned with '}'s. */
    /* (AD): I'm fixing this part, you can edit the other ones */
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
    /* (AD): Missing return statement */
    return 0;
}


/* (AD): Since mode is a typedef now, change its type from int --> T_MODE_ENUM */
/* (AD): This gives clue to other people about what should they pass to this function as an argument. It's not an int but T_MODE_ENUM. */
int getModulo(int nr, int mode) {
    /* (AD): I prefer this opening curly bracket '{' right below the function prototype. */
    /* (AD): This is not a must but you should choose one and continue with it. It's different for other functions and this function */
    if (nr == 0) return 0;
    switch(mode) {  /* (AD): Prefer to use it one line below. This is also valid for while, if, for, do etc... */
    case UPPERCASE:
        return nr % 27; /* (AD): As long as not must, please try to have single return for each function. */
        break;          /* (AD): So you can define int result = 0; Update result in cases and return it at the end. --> Easy to follow code */
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

/* (AD): GetCharacter,  T_MODE_ENUM, move '{' to one line below, single return statement */
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

/* (AD): GetPunctuation, single return statement, move '{' to one line below. */
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



