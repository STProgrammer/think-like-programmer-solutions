#include <iostream>
#define D_NUM_AGENTS 3
#define D_NUM_MONTHS 12

using namespace std;

/*
Highest median sales using arrays only
*/

int compareFunc(const void * val1, const void * val2);
float getMedian(int arr[], const int ARR_SIZE);
float getMedianWithQSort(int arr[], const int ARR_SIZE);

int main()
{
    int sales[D_NUM_AGENTS][D_NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    float maxMedian = 0;
    float median = 0;


    //Using selection sort on its half
    for (int agentIdx = 0; agentIdx < D_NUM_AGENTS; agentIdx++)
    {

        //median = getMedian(sales[agentIdx], D_NUM_MONTHS);
        median = getMedianWithQSort(sales[agentIdx], D_NUM_MONTHS);
        if (maxMedian < median) maxMedian = median;
    }

    //Printing the sorted lists
    for (int i = 0; i < D_NUM_AGENTS; i++)
    {
        printf("\nAgent %d: ", i+1);
        for (int j = 0; j < D_NUM_MONTHS; j++)
        {
            cout << sales[i][j] << " ";
        }
    }

    printf("\nMax median sales is %.1f", maxMedian);

    cin.get();
    return 0;
}



float getMedian(int arr[], const int ARR_SIZE)
{
    //Using selection sort on its half
    float median = 0;
    bool odd = ARR_SIZE % 2;
    int centerIdx = ARR_SIZE / 2;
    int startIdx = 0;
    int endIdx = ARR_SIZE-1;
    int minimum = 0;
    int minimumIdx = 0;

    for (int i = startIdx; i <= centerIdx; i++)
    {
        minimum = arr[endIdx];
        minimumIdx = endIdx;
        for (int j = endIdx; j >= i; j--)
        {
            if (arr[j] <= minimum)
            {
                minimum = arr[j];
                minimumIdx = j;
            }
        }
        int temp = arr[i];
        arr[minimumIdx] = temp;
        arr[i] = minimum;
    }
    if (odd)
    {
        median = arr[centerIdx];
    }
    else
    {
        median = (arr[centerIdx - 1] + arr[centerIdx]) / 2.0;
    }
    return median;

}



float getMedianWithQSort(int arr[], const int ARR_SIZE)
{
    float median = 0;
    int maxMedian = 0;
    bool odd = ARR_SIZE % 2;
    int centerIdx = ARR_SIZE / 2;


    qsort(arr, ARR_SIZE, sizeof(int), compareFunc);
    if (odd)
    {
       median = arr[centerIdx];
    }
    else
    {
        median = (arr[centerIdx - 1] + arr[centerIdx]) / 2.0;
    }
    return median;
}



int compareFunc(const void * val1, const void * val2)
{
    return *(int*)(val1) - *(int*)(val2);
}

