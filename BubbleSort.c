#include "ConsolePrint.h"
#include "ArrayUtils.h"

int bubbleSort(int size, int* array) {
    int p = 1;
    int noIterations = 0;
    while (p) {
        p = 0;
        for (int i = 0; i < size - 1; i++) {
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                p = 1;
                printStat(size, array);
            }
            noIterations++;
        }
    }
    return noIterations;
}