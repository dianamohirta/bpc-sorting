#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <wchar.h>
#include <stdbool.h>
#include <time.h>

void printInstructions() {
    printf_s("Enter one of the following codes:\n");
    printf_s("Selection Sort: 1\n");
    printf_s("Bubble Sort:    2\n");
    printf_s("Heap Sort:      3\n");
    printf_s("Quick Sort:     4\n");
    printf_s("Insertion Sort: 5\n");
    printf_s("Radix Sort:     6\n");
    printf_s("Shell Sort:     7\n");
}

int sort(int algorithm, int size, int* array) {
    switch (algorithm)
    {
    case 1:
        return selectionSort(size, array);
    case 2:
        return bubbleSort(size, array);
    case 3:
        return heapSort(size, array);
    case 4:
        return quickSort(size, array);
    case 5:
        return insertionSort(size, array);
    case 6:
        return radixSort(size, array);
    case 7:
        return shellSort(size, array);
    }
}

char* getName(int algorithm) {
    switch (algorithm)
    {
    case 1:
        return "Selection Sort";
    case 2:
        return "Bubble Sort";
    case 3:
        return "Heap Sort";
    case 4:
        return "Quick Sort";
    case 5:
        return "Insertion Sort";
    case 6:
        return "Radix Sort";
    case 7:
        return "Shell Sort";
    }
}

void configureConsole() {
    SMALL_RECT windowSize = { 0 , 0 , 77 , 80 };
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
}

double getTime() {
    return (double) clock();
}

int main() {
    configureConsole();

    int algorithm, array[200], size = 20;
    generateArrayElements(size, array);

    printInstructions();
    printf_s("Enter algorthm code: ");
    scanf_s("%d", &algorithm);

    double startTime = getTime();
    int noIterations = sort(algorithm, size, array);
    double stopTime = getTime();
    int executionTime = (double)(stopTime - startTime) / CLOCKS_PER_SEC;

    printReport(getName(algorithm), executionTime, noIterations, size);

}