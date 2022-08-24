#include <iostream>


using std::cin;

typedef char * arrayString;

void append(arrayString &str, char ch);
void concatenate(arrayString &str1, arrayString str2);
char characterAt(arrayString str, int position);
arrayString substring(arrayString str, int startPos, int len);
void replaceString(arrayString &source, arrayString target, arrayString replaceText);
int length(arrayString str);

int main()
{
    arrayString source = new char[9];

    source[0] = 'a'; source[1] = 'b'; source[2] = 'c'; source[3] = 'd';
    source[4] = 'a'; source[5] = 'b'; source[6] = 'e'; source[7] = 'e';
    source[8] = 0;

    arrayString target = new char[3];
    target[0] = 'a'; target[1] = 'b'; target[2] = 0;

    arrayString replaceText = new char[2];
    replaceText[0] = 'x'; replaceText[1] = 'y'; replaceText[2] = 'z'; replaceText[3] = 0;

    printf("Source text: %s \n", source);
    printf("Replace %s with %s in the source text using replaceString() function \n", target, replaceText);
    replaceString(source, target, replaceText);
    printf("The result is: %s ", source);

    cin.get();
    return 0;

}


void replaceString(arrayString &source, arrayString target, arrayString replaceText)
{
    int targetLen = length(target);
    int sourceLen = length(source);
    int replaceLen = length(replaceText);
    int equalCount = 0;
    int replaceCount = 0;
    int replaceIndexes[sourceLen+1] = {0};

    // Prepare replaceIndexes
    for (int i = 0; i < sourceLen; i++)
    {
        if (source[i] == target[equalCount]) // Characters are equal
        {
            equalCount++;
            if (equalCount == targetLen) // If the substring is equal
            {
                replaceIndexes[replaceCount++] = i-targetLen+1;
                equalCount = 0;
            }
        }
        else
        {
            equalCount = 0;
        }
    }




    int newStrLen = sourceLen + replaceCount * (replaceLen - targetLen);
    arrayString newStr = new char[newStrLen+1];

    // Replace using replaceIndexes
    int i = 0;
    int j = 0;
    int replaceIdx = 0;
    int sourceIdx = 0;
    while (i < newStrLen)
    {
        if (sourceIdx == replaceIndexes[replaceIdx])
        {   // Putting the replace text
            for (int j = 0; j < replaceLen; j++)
            {
                newStr[i++] = replaceText[j];
            }
            sourceIdx += targetLen;
            replaceIdx++;
        }
        else
        {
            newStr[i++] = source[sourceIdx++];
        }

    }
    newStr[newStrLen] = 0;
    delete[] source;
    source = newStr;


}

arrayString substring(arrayString str, int startPos, int len)
{
    arrayString newStr = new char[len+1];

    startPos--;

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

