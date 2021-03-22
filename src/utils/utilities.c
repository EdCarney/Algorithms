#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "utilities.h"

bool isCapitalAlphabetChar(char c) {
    return (c >= 'A' && c <= 'Z') ? true : false;
}

bool isLowerAlphabetChar(char c) {
    return (c >= 'a' && c <= 'z') ? true : false;
}

char capatilizeChar(char c) {
    if (isCapitalAlphabetChar(c))
        return c;
    return c - 32;
}

int readCharArrayFromFile(const char* fileName, char ** arrPtr, int * countPtr) {
    FILE* fp;
    int numElements = 0, count = 0;
    char *ret, c;

    if (!(fp = fopen(fileName, "r"))) {
        return -1;
    }

    while ((c = fgetc(fp)) != EOF)
        if (isCapitalAlphabetChar(c) || isLowerAlphabetChar(c))
            ++numElements;
        
    if (!(ret = (char*)calloc(numElements, sizeof(char))))
        return -1;

    rewind(fp);

    while ((c = fgetc(fp)) != EOF) {
        if (isCapitalAlphabetChar(c))
            ret[count++] = c;
        else if (isLowerAlphabetChar(c))
            ret[count++] = capatilizeChar(c);
    }

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