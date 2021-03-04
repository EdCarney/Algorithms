#include <stdio.h>
#include <time.h>
#include "utils/utilities.h"
#include "sorting-algos/selection-sort.h"
#include "sorting-algos/insertion-sort.h"

const char * inputFile = "./../data/array-input-1.txt";
clock_t clockTime;
double runtime;

int testInsertionSort();
int testSelectionSort();

int main() {
    int ret = 0;

    ret += testInsertionSort();
    ret += testSelectionSort();

    return ret < 0 ? -1 : 0;
}

int testInsertionSort() {
    double* unsortedArray;
    int numElements;
    
    printf("\nINSERTION SORT\n");
    if (readArrayFromFile(inputFile, &unsortedArray, &numElements) < 0) {
        printf("ERROR: Could not read array from file: %s\n", inputFile);
        return -1;
    }

    printDoubleArray(unsortedArray, numElements);

    clockTime = clock();
    if (insertionSort(unsortedArray, numElements) < 0) {
        printf("ERROR: Problem doing Insertion Sort\n");
        return -1;
    }
    clockTime = clock() - clockTime;
    runtime = clockTime * 1000 / CLOCKS_PER_SEC;

    printDoubleArray(unsortedArray, numElements);
    printf("Total time taken (ms): %f", runtime);
    printf("\n");
    return 0;
}

int testSelectionSort() {
    double* unsortedArray;
    int numElements;
    printf("\nSELECTION SORT\n");
    if (readArrayFromFile(inputFile, &unsortedArray, &numElements) < 0) {
        printf("ERROR: Could not read array from file: %s\n", inputFile);
        return -1;
    }

    printDoubleArray(unsortedArray, numElements);

    if (selectionSort(unsortedArray, numElements) < 0) {
        printf("ERROR: Problem doing Selection Sort\n");
        return -1;
    }

    printDoubleArray(unsortedArray, numElements);
    printf("\n");
    return 0;
}