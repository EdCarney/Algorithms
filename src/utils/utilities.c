#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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