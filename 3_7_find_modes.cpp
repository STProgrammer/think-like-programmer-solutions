#include <iostream>
#define D_ARR_SIZE 30

/*
Find modes without using hash maps, just arrays.
*/

using std::cin;
using std::cout;

int * findModes(int arr[], const int ARR_SIZE);

void printModes(int modesList[]);

int main()
{
    int noModeArr[D_ARR_SIZE] = {1,0,2,9,3,8,4,7,5,6,1,2,3,4,5,6,7,8,9,0,6,5,7,4,8,3,9,2,0,1}; // No mode
    int oneModeArr[D_ARR_SIZE] = {1,0,2,9,3,8,4,7,5,6,1,2,3,4,5,6,7,8,9,0,6,5,7,4,5,3,9,2,0,1}; // Mode is 5
    int twoModesArr[D_ARR_SIZE] = {1,0,2,9,3,8,4,7,5,6,1,2,3,4,5,4,7,8,9,0,6,5,7,4,8,3,9,2,0,0}; // Mode is 4 and 0


    int * modesList = findModes(noModeArr, D_ARR_SIZE);
    printModes(modesList);
    delete[] modesList;

    modesList = findModes(oneModeArr, D_ARR_SIZE);
    printModes(modesList);
    delete[] modesList;

    modesList = findModes(twoModesArr, D_ARR_SIZE);
    printModes(modesList);
    delete[] modesList;

    cin.get();
    return 0;
}



int * findModes(int arr[], const int ARR_SIZE)
{
    int countTable[ARR_SIZE*2] = {0}; // Saves data like [value, count, value, count, value, count].
    int * modesList = new int[ARR_SIZE+1]; // First value is nr of modes, other values or the modes.
    modesList[0] = 0;


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
            modesList[++nrOfModes] = countTable[2*i];
            modesList[0] = nrOfModes;
        }
    }
    if (nrOfModes >= nrOfValues)
    {
        modesList[0] = 0;
    }

    return modesList;
}


void printModes(int modesList[])
{
    int nrOfModes = modesList[0];

    if (!nrOfModes)
    {
        cout << "The array has no modes!\n";
        return;
    }

    cout << "The modes are: ";

    for (int i = 1; i < nrOfModes; i++)
    {
        cout << modesList[i] << ", ";
    }

    cout << modesList[nrOfModes] << "\n";
}

