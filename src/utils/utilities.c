#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utilities.h"

int readCharArrayFromFile(const char* fileName, char ** arrPtr, int * countPtr) {
    return readLimitedCharArrayFromFile(fileName, arrPtr, countPtr, CHAR_MIN, CHAR_MAX);
}

int readLimitedCharArrayFromFile(const char* fileName, char ** arrPtr, int * countPtr, char minVal, char maxVal) {
    FILE* fp;
    int numElements = 0, count = 0;
    char *ret, c;

    if (!(fp = fopen(fileName, "r"))) {
        return -1;
    }

    while ((c = fgetc(fp)) != EOF)
        if (c >= minVal && c <= maxVal)
            ++numElements;
        
    if (!(ret = (char*)calloc(numElements, sizeof(char))))
        return -1;

    rewind(fp);

    while ((c = fgetc(fp)) != EOF)
        if (c >= minVal && c <= maxVal)
            ret[count++] = c;

    *arrPtr = ret;
    *countPtr = numElements;
    return 0;
}

int readArrayFromFile(const char* fileName, double ** arrPtr, int * countPtr) {
    FILE* fp;
    char line[10];
    char* ptr;
    int numElements = 0, counter = 0;
    double* ret;

    if (!(fp = fopen(fileName, "r")))
        return -1;

    while (fgets(line, 10, fp))
        ++numElements;

    if (!(ret = (double*)calloc(numElements, sizeof(double))))
        return -1;

    rewind(fp);

    while (fgets(line, 10, fp))
        ret[counter++] = strtod(line, &ptr);

    fclose(fp);

    *arrPtr = ret;
    *countPtr = numElements;
    return 0;
}

void printDoubleArray(double * array, int numElements) {
    // printf("[ ");
    for (int i = 0; i < numElements; ++i)
        printf("%.1f, ", array[i]);
    // printf("]\n");
    printf("\n");
}

void printIntArray(int * array, int numElements) {
    printf("[ ");
    for (int i = 0; i < numElements; ++i)
        printf("%d, ", array[i]);
    printf("]\n");
}