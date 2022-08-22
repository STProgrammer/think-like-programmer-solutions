#include <iostream>

using std::cout;
using std::endl;

typedef char * arrayString;

void append(arrayString &str, char ch);
void concatenate(arrayString &str1, arrayString str2);
char characterAt(arrayString str, int position);
int getLength(arrayString str);

int main()
{
    arrayString str = new char[5];
    str[0] = 'T'; str[1] = 'e'; str[2] = 's'; str[3] = 't'; str[4] = 0;
    cout << "The string: " << str << endl;

    cout << "Character at position " << 1 << " is " << characterAt(str, 1) << endl;

    cout << "Before append: " << str << endl;
    append(str, '!');
    cout << "After append: " << str << endl;

    arrayString str1 = new char[5];
    str1[0] = 'T'; str1[1] = 'e'; str1[2] = 's'; str1[3] = 't'; str1[4] = 0;

    arrayString strToAdd = new char[4];
    strToAdd[0] = 'b'; strToAdd[1] = 'e'; strToAdd[2] = 'd'; strToAdd[3] = 0;

    cout << "Before concatenate: " << str1 << endl;
    cout << "String to add: " << strToAdd << endl;
    concatenate(str1, strToAdd);
    cout << "After concatenate: " << str1 << endl;
    cout << (void*) str1 << " " << (void*)strToAdd << endl;

}

char characterAt(arrayString str, int position)
{
    return str[position];
}

void append(arrayString &str, char ch)
{
    int oldLen = getLength(str);
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
    int len1 = getLength(str1);
    int len2 = getLength(str2);
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

int getLength(arrayString str)
{
    int len = 0;
    while(str[len] != 0)
    {
        len++;
    }
    return len;
}

