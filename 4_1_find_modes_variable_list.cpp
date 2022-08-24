#include <iostream>
#define D_MAX_SIZE 256

/*
Find modes without using hash maps, just arrays.
*/

using std::cin;
using std::cout;
using std::endl;

void append(int* &arr, int num, int arrSize);
int * findModes(int arr[], const int ARR_SIZE);
void printModes(int modesList[]);

int main()
{
    int num = 0;
    int arraySize = 1;


    int* numList = new int[1];

    cout << "This program finds mode of a list of integers.\n";
    cout << "Type in numbers to and press enter to fill the list, finish by entering -1.\n";
    cout << "You need to type at least 1 number: \n";

    cin >> num;
    cin.ignore();
    numList[0] = num;

    cin >> num;
    cin.ignore();



    while (num != -1 && arraySize < D_MAX_SIZE)
    {
        append(numList, num, arraySize);
        arraySize++;
        cin >> num;
        cin.ignore();
    }

    cout << "\nThe numbers in the list are:\n[";

    for (int i = 0; i < arraySize; i++)
    {
        cout << numList[i] << ",";
    }
    cout << "]\n";



    int * modesList = findModes(numList, arraySize);

    printModes(modesList);

    delete[] numList;
    delete[] modesList;


    cin.get();
    return 0;
}

void append(int* &arr, int num, int arrSize)
{

    int* newArr = new int[arrSize + 1];
    for (int i = 0; i < arrSize; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[arrSize] = num;
    delete[] arr;
    arr = newArr;
}


int * findModes(int arr[], const int ARR_SIZE)
{
    int countTable[ARR_SIZE*2] = {0}; // Saves data like [value, count, value, count, value, count].
    int * modesList = nullptr;
    int * tempModesList = new int[ARR_SIZE+1]; // First value is nr of modes, other values or the modes.
    tempModesList[0] = 0;


    int maxCount = 0;
    int val;
    int nrOfValues = 0; // Nr of different values in the array, in the examples above that is only 10 (numbers from 0 to 9).
    int nrOfModes = 0;

    for (int i = 0; i < ARR_SIZE; i++)
    {
        val = arr[i];
        int j = 0;
        while(val != countTable[2*j] && j < nrOfValues) // Check if value is in array
        {
            j++;
        }
        if (j == nrOfValues)  // If value not in array, add value in array
        {
            countTable[2*j] = val;
            nrOfValues++;
        }
        else // Else increase the count
        {
            countTable[2*j+1]++;
            if (maxCount < countTable[2*j+1])
            {
                maxCount = countTable[2*j+1];
            }
        }
    }

    // Get the modes
    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (maxCount == countTable[2*i+1])
        {
            tempModesList[++nrOfModes] = countTable[2*i];
            tempModesList[0] = nrOfModes;
        }
    }
    if (nrOfModes >= nrOfValues)
    {
        tempModesList[0] = 0;
        nrOfModes = 0;
    }

    modesList = new int[nrOfModes+1];

    for (int i = 0; i <= nrOfModes; i++)
    {
        modesList[i] = tempModesList[i];
    }

    delete[] tempModesList;
    return modesList;
}


void printModes(int modesList[])
{
    const int NR_OF_MODES = modesList[0];

    if (!NR_OF_MODES)
    {
        cout << "The array has no modes!\n";
        return;
    }

    else if (1 == NR_OF_MODES )
    {
        cout << "The mode is: " << modesList[1] << endl;
    }

    else
    {
        cout << "The modes are: " << modesList[1];
        for (int i = 2; i < NR_OF_MODES; i++)
        {
            cout << ", " << modesList[i];
        }

        cout << " and " << modesList[NR_OF_MODES] << "\n";
    }

}

