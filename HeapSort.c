#include "ConsolePrint.h"
#include "ArrayUtils.h"

void heapify(int arr[], int N, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < N && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

int heapSort(int n, int array[]) {
    int noIterations = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
        printStat(n, array);
        noIterations++;
    }

    return noIterations;
}