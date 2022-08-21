#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const int ARRAY_SIZE = 21;
    const int RANGE_SIZE = 10;
    int data[ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9,10,1,2,3,3,4,5,6,7,8,9,10};
    int histogram[RANGE_SIZE] = {0};

    int mode = data[0];
    bool hasNoMode = true;

/*
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        histogram[data[i]-1]++;
    }

    for(int i = 0; i < RANGE_SIZE; i++)
    {
        if (histogram[i] > histogram[mode])
        {
            mode = i;
        }
    }
    mode++;
*/


    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        histogram[data[i]-1]++;
        if (histogram[mode-1] < histogram[data[i]-1])
        {
            mode = data[i];
        }
    }


    for(int i = 0; i < RANGE_SIZE; i++)
    {
        if (histogram[mode-1] > histogram[i])
        {
            hasNoMode = false;
            break;
        }
    }

    if (hasNoMode)
    {
        cout << "The set has no mode" << endl;
    }
    else
    {
        cout << "The mode is " << mode << endl;
    }

}

