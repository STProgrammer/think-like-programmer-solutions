#include <iostream>

using std::cout;
using std::cin;
using std::endl;

typedef char * arrayString;

void output(arrayString str);
void append(arrayString &str, char ch);
void concatenate(arrayString &str1, arrayString str2);
char characterAt(arrayString str, int position);

int main()
{
    arrayString str = new char[5];
    str[0] = 4; str[1] = 'T'; str[2] = 'e'; str[3] = 's'; str[4] = 't';
    cout << "The string: ";
    output(str);

    cout << "\nCharacter at position " << 1 << " is " << characterAt(str, 1) << endl;

    cout << "\nBefore append: ";
    output(str);
    append(str, '!');
    cout << "\nAfter append: ";
    output(str);

    arrayString str1 = new char[5];
    str1[0] = 4; str1[1] = 'T'; str1[2] = 'e'; str1[3] = 's'; str1[4] = 't';

    arrayString strToAdd = new char[4];
    strToAdd[0] = 3; strToAdd[1] = 'b'; strToAdd[2] = 'e'; strToAdd[3] = 'd';

    cout << "\nBefore concatenate: ";
    output(str1);
    cout << "\nString to add: ";
    output(strToAdd);
    concatenate(str1, strToAdd);
    cout << "\nAfter concatenate: ";
    output(str1);
    cout << "\n";
    cout << (void*) str1 << " " << (void*)strToAdd << endl;

    cin.get();
    return 0;

}

void output(arrayString str)
{
    for (int i = 1; i <= str[0]; i++)
    {
        cout << str[i];
    }
}


char characterAt(arrayString str, int position)
{
    return str[position];
}


void append(arrayString &str, char ch)
{
    arrayString newStr = new char[str[0] + 2];

    for (int i = 1; i <= str[0]; i++)
    {
        newStr[i] = str[i];
    }
    newStr[str[0]+1] = ch;
    newStr[0] = str[0] + 1;
    delete[] str;
    str = newStr;
}

void concatenate(arrayString &str1, arrayString str2)
{

    int newLen = str1[0] + str2[0];
    arrayString newStr = new char[newLen+1];
    for (int i = 1; i <= str1[0]; i++)
    {
        newStr[i] = str1[i];
    }
    for (int i = str1[0]+1; i <= newLen; i++)
    {
        newStr[i] = str2[i - str1[0]];
    }
    newStr[0] = newLen;
    delete[] str1;
    str1 = newStr;
}
