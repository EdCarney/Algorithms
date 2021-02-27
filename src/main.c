#include <stdio.h>
#include "utilities.h"
#include "selection-sort.h"
#include "insertion-sort.h"

const char * inputFile = ".\\..\\data\\array-input-1.txt";

int testInsertionSort();

int main() {
    int ret = 0;


    ret += testInsertionSort();


    return 0;
}

int testInsertionSort() {
    double* unsortedArray;
    int numElements;
    printf("\n");
    if (readArrayFromFile(inputFile, &unsortedArray, &numElements) < 0) {
        printf("ERROR: Could not read array from file: %s\n", inputFile);
        return -1;
    }

    printDoubleArray(unsortedArray, numElements);

    if (insertionSort(unsortedArray, numElements) < 0) {
        printf("ERROR: Problem doing Insertion Sort\n");
        return -1;
    }

    printDoubleArray(unsortedArray, numElements);
    printf("\n");
    return 0;
}