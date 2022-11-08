#include "ConsolePrint.h"
#include "ArrayUtils.h"

int selectionSort(int size, int* array) {
    int noIterations = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                swap(&array[i], &array[j]);
                printStat(size, array);
            }
            noIterations++;
        }
    }
    return noIterations;
}