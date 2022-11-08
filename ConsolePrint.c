#include <stdio.h>
#include <windows.h>
#include "ConsolePrint.h"

#ifdef WIN32
#define F_OK 0
#define access _access
#endif

void printStat(int size, int* array) {
    Sleep(20);
    system("cls");
    for (int i = size; i >= 0; i--) {
        for (int j = 0; j < size; j++) {

            if (i <= 0) {
                if (array[j] < 10) {
                    printf_s(" %d ", array[j]);
                }
                else {
                    printf_s("%d ", array[j]);
                }
            } else if (array[j] >= i) {
                printf_s("%c%c%c", (char)254u, (char)254u, (char)254u);
            }
            else {
                printf_s("   ");
            }
        }
        printf_s("\n");
    }
}

void writeHeader(FILE* file) {
    fprintf(file, "=================================================================================================================================================================\n");
    fprintf(file, "====     Algoritm Name     =================     Execution Time     ======================     No iterations     ======================     No Elements     =====\n");
    fprintf(file, "=================================================================================================================================================================\n");
}

void appendBody(FILE* file, const char* algName, const long time, const int noIterations, const int noElements) {

    fprintf(file, "====     %s     =================     %ld    ======================     %d     ======================    %d    =====\n", algName, time, noIterations, noElements);
    fprintf(file, "==================================================================================================================================================================\n");
}

void writeConsoleHeader() {
    printf_s("=======================================================================================================================================================================\n");
    printf_s("====     Algoritm Name     =================     Execution Time     ======================     No of iterations     ======================     No of elements     =====\n");
    printf_s("=======================================================================================================================================================================\n");
}

void appendConsoleBody(const char* algName, const long time, const int noIterations, const int noElements) {

    printf_s("====     %s     ======================     %ld    ======================     %d     ======================     %d     ====================\n", algName, time, noIterations, noElements);
    printf_s("==================================================================================================================================================================\n");
}

void generateReport(const char* algName, const long time, const int noIterations, const int noElements) {

    FILE* file;
    //if (access("raport.txt", F_OK) != 0) {
        fopen_s(&file, "raport.txt", "w+");
        writeHeader(file);
    //}
    appendBody(file, algName, time, noIterations, noElements);
}

void printReport(const char* algName, const long time, const int noIterations, const int noElements) {

    writeConsoleHeader();
    appendConsoleBody(algName, time, noIterations, noElements);
}

void writeSortData(int size, int* positions) {

    FILE* file;
    fopen_s(&file, "reply.txt", "w+");
    for (int i = 0; i < size; i++) {
        //fprintf(file, "%d ", positions[i]);
        printf_s("%d ", positions[i]);
    }
    //fprintf(file, "\n");
}

void readSortData(int size, int* entries, int** positions) {

    FILE* file;
    fopen_s(&file, "reply.txt", "r+");
    int row = 0;
    while (!feof(file)) {
        for (int i = 0; i < size; i++) {
            fscanf_s(file, "%d", &positions[row][i]);
        }
        row++;
    }
    entries = row;
}

void replyStat(int size) {

    int entries, positions[1000][1000];
    readSortData(size, &entries, positions);
    for (int i = 0; i < entries; i++) {
        printStat(size, positions[i]);
    }
}