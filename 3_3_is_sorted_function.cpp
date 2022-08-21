#include <iostream>

using namespace std;


bool isArraySorted(int arr[], int arrSize);

int main()
{
    const int ARRAY_SIZE = 10;

    int arr1[ARRAY_SIZE] = {1,6,3,1,2,4,9,6,4,2};

    bool isSorted = isArraySorted(arr1, ARRAY_SIZE);

    if (isSorted) printf("Array is sorted\n");
    else printf("Array is not sorted\n");

    int arr2[ARRAY_SIZE] = {1,1,2,2,4,5,6,7,9,9};

    isSorted = isArraySorted(arr2, ARRAY_SIZE);

    if (isSorted) printf("Array is sorted\n");
    else printf("Array is not sorted\n");

}


bool isArraySorted(int arr[], int arrSize)
{
    if (arrSize <= 1) return true;

    int i = 0;
    arrSize--;

    while(i < arrSize)
    {
        if(arr[i] > arr[i+1]) return false;
        i++;
    }
    return true;
}
