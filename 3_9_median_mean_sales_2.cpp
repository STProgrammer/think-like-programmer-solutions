#include <iostream>

using namespace std;

int compareFunc(const void * val1, const void * val2);
double getMedian(int arr[], const int ARR_SIZE);
double getMedianWithQSort(int arr[], const int ARR_SIZE);
double getMean(int arr[], const int ARR_SIZE);

int main()
{
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;


    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {-1, -1, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, -1, -1, -1},
        {-1, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, -1}
    };

    double median = 0;
    double maxMedian = 0;
    double mean = 0;
    double maxMean = 0;


    //Using selection sort on its half
    for (int agentIdx = 0; agentIdx < NUM_AGENTS; agentIdx++)
    {

        //median = getMedian(sales[agentIdx], NUM_MONTHS);
        median = getMedianWithQSort(sales[agentIdx], NUM_MONTHS);
        if (maxMedian < median) maxMedian = median;
        mean = getMean(sales[agentIdx], NUM_MONTHS);
        if (maxMean < mean) maxMean = mean;
    }

    //Printing the sorted lists
    for (int i = 0; i < NUM_AGENTS; i++)
    {
        printf("\nAgent %d: ", i+1);
        for (int j = 0; j < NUM_MONTHS; j++)
        {
            cout << sales[i][j] << " ";
        }
    }

    printf("\nMax median sales is %.1f", maxMedian);
    printf("\nMax mean sales is %.1f", maxMean);

}



int compareFunc(const void * val1, const void * val2)
{
    return *(int*)(val1) - *(int*)(val2);
}


double getMedian(int arr[], const int ARR_SIZE)
{
    // Using selection sort on its half
    double median = 0;
    // Find start index
    int startIdx = 0;
    while (arr[startIdx] == -1 && startIdx < ARR_SIZE)
    {
        startIdx++;
    }
    // Find end index
    int endIdx = ARR_SIZE-1;
    while (arr[endIdx] == -1 && endIdx > 0)
    {
        endIdx--;
    }
    int listSize = endIdx-startIdx+1;

    bool odd = listSize % 2;
    int centerIdx = listSize / 2 + startIdx;

    int minimum;
    int minimumIdx;

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

    if (odd) median = arr[centerIdx];
    else median = (arr[centerIdx - 1] + arr[centerIdx]) / 2.0;
    return median;

}



double getMedianWithQSort(int arr[], const int ARR_SIZE)
{
    double median = 0;

    // Find start slice
    int startSlice = 0;
    while (arr[startSlice] == -1 && startSlice < ARR_SIZE)
    {
        startSlice++;
    }
    // Find end index
    int endSlice = ARR_SIZE-1;
    while (arr[endSlice] == -1 && endSlice > 0)
    {
        endSlice--;
    }
    endSlice = ARR_SIZE - endSlice - 1;
    int listSize = ARR_SIZE - endSlice - startSlice;

    bool odd = listSize % 2;
    int centerIdx = listSize / 2 + startSlice;

    //Split array
    int * p_temp = &arr[startSlice];

    qsort(p_temp, listSize, sizeof(int), compareFunc);
    if (odd) median = arr[centerIdx];
    else median = (arr[centerIdx - 1] + arr[centerIdx]) / 2.0;
    return median;
}


double getMean(int arr[], const int ARR_SIZE)
{
    int n = 0;
    double sum = 0;

    for(int i = 0; i < ARR_SIZE; i++)
    {
        if (arr[i] == -1) continue;
        n++;
        sum += arr[i];
    }

    return sum / n;
}

