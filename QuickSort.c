#include "ArrayUtils.h"
#include "ConsolePrint.h"

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortRecursive(int* noIterations, int size, int arr[], int low, int high)
{
    noIterations++;
    printStat(size, arr);
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSortRecursive(noIterations, size, arr, low, pi - 1);
        quickSortRecursive(noIterations, size, arr, pi + 1, high);
    }
}
int quickSort(int size, int arr[])
{
    int noIterations = 0;
    quickSortRecursive(&noIterations, size, arr, 0, size - 1);
    return noIterations;
}