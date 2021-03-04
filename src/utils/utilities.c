#include <stdio.h>
#include <stdlib.h>

int readArrayFromFile(const char* fileName, double ** arrPtr, int * countPtr) {
    FILE* fp;
    char line[10];
    char* ptr;
    int numElements = 0, counter = 0;
    double* ret;

    if ((fp = fopen(fileName, "r")) == NULL)
        return -1;

    while (fgets(line, 10, fp) != NULL)
        ++numElements;

    if ((ret = (double*)calloc(numElements, sizeof(double))) == NULL)
        return -1;

    rewind(fp);

    while (fgets(line, 10, fp) != NULL)
        ret[counter++] = strtod(line, &ptr);

    fclose(fp);

    *arrPtr = ret;
    *countPtr = numElements;
    return 0;
}

void printDoubleArray(double * array, int numElements) {
    printf("[ ");
    for (int i = 0; i < numElements; ++i)
        printf("%.1f, ", array[i]);
    printf("]\n");
}

void printIntArray(int * array, int numElements) {
    printf("[ ");
    for (int i = 0; i < numElements; ++i)
        printf("%d, ", array[i]);
    printf("]\n");
}