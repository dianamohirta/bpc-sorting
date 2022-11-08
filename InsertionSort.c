#include "ConsolePrint.h"

int insertionSort(int n, int arr[])
{
    int key, j, noIterations=0;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;

            noIterations++;
            printStat(n, arr);
        }
        arr[j + 1] = key;
    }
}