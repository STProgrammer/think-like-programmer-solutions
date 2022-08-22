#include <iostream>
#include <cstring>
#define D_ARRAY_SIZE 21
#define D_RANGE_SIZE 10

using namespace std;

/*
Find mode, using arrays only.
*/

int main()
{
    int data[D_ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9,10,1,2,3,3,4,5,6,7,8,9,10};
    int histogram[D_RANGE_SIZE] = {0};

    int mode = data[0];
    bool hasNoMode = true;


/*
    for(int i = 0; i < D_ARRAY_SIZE; i++)
    {
        histogram[data[i]-1]++;
    }

    for(int i = 0; i < D_RANGE_SIZE; i++)
    {
        if (histogram[i] > histogram[mode])
        {
            mode = i;
        }
    }
    mode++;
*/


    for(int i = 0; i < D_ARRAY_SIZE; i++)
    {
        histogram[data[i]-1]++;
        if (histogram[mode-1] < histogram[data[i]-1])
        {
            mode = data[i];
        }
    }


    for(int i = 0; i < D_RANGE_SIZE; i++)
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

    cin.get();

    return 0;
}

