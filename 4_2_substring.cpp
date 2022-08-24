#include <iostream>
#define D_ARRAY_SIZE 12


using std::cout;
using std::cin;
using std::endl;


typedef char * arrayString;

void append(arrayString &str, char ch);
void concatenate(arrayString &str1, arrayString str2);
char characterAt(arrayString str, int position);
arrayString substring(arrayString str, int startPos, int len);
int length(arrayString str);

int main()
{
    arrayString str = new char[D_ARRAY_SIZE];

    for(int i = 0; i < D_ARRAY_SIZE-1;i++)
    {
        str[i] = 'a' + i;
    }
    str[D_ARRAY_SIZE-1] = 0;



    int startPos = 3;
    int len = 2;

    arrayString newStr = substring(str, startPos, len);

    cout << "The string: " << str << endl;
    cout << "The substring: " << newStr << endl;

    delete[] str;
    delete[] newStr;

    cin.get();
    return 0;

}


arrayString substring(arrayString str, int startPos, int len)
{
    arrayString newStr = new char[len+1];

    int strLength = length(str);

    for (int i = 0; i < len; i++)
    {
        newStr[i] = str[i+startPos];
    }
    newStr[len] = 0;
    return newStr;
}


char characterAt(arrayString str, int position)
{
    return str[position];
}

void append(arrayString &str, char ch)
{
    int oldLen = length(str);
    arrayString newStr = new char[oldLen + 2];

    for (int i = 0; i < oldLen; i++)
    {
        newStr[i] = str[i];
    }
    newStr[oldLen] = ch;
    newStr[oldLen + 1] = 0;
    delete[] str;
    str = newStr;
}

void concatenate(arrayString &str1, arrayString str2)
{
    int len1 = length(str1);
    int len2 = length(str2);
    int newLen = len1 + len2;
    arrayString newStr = new char[newLen+1];
    for (int i = 0; i < len1; i++)
    {
        newStr[i] = str1[i];
    }
    for (int i = len1; i < newLen; i++)
    {
        newStr[i] = str2[i - len1];
    }
    newStr[newLen] = 0;
    delete[] str1;
    str1 = newStr;
}

int length(arrayString str)
{
    int len = 0;
    while(str[len] != 0)
    {
        len++;
    }
    return len;
}

