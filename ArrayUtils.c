#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <io.h>  
#include <windows.h>

#ifdef WIN32
#define F_OK 0
#define access _access
#endif

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int n, int* array)
{
    if (n <= 1) {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

void generateArrayElements(int size, int* array) {
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
    shuffle(size, array);
}

//void writeElements(int size, int* array) {
//
//    generateArrayElements(size, array);
//    if (access("unsorted-numbers.txt", F_OK) == 0) {
//        return;
//    }
//    FILE* file;
//    fopen_s(&file, "unsorted-numbers.txt", "w+");
//    for (int i = 0; i < size; i++) {
//        fprintf(file, "%d,", array[i]);
//    }
//    fclose(file);
//}