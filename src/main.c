#include <stdio.h>
#include <time.h>
#include <stdbool.h> 
#include "utils/utilities.h"
#include "sorting-algos/treap-sort.h"

const char *treapInputFile = "./../data/string-input-1.txt";
struct timeval start_t, finish_t;

int executeProblem();

int main() {
    const char *dataInputFile = "./../data/textbook.txt";
    char *dataCharArray;
    int numDataElem, ret = 0;

    // get the array to search against
    if (readCharArrayFromFile(dataInputFile, &dataCharArray, &numDataElem) < 0) {
        printf("ERROR: Could not read array from file: %s\n", dataInputFile);
        return -1;
    }

    printf("\nPROBLEM 4\n");
    ret += executeProblem(dataCharArray, numDataElem, random);

    printf("\nPROBLEM 5\n");
    ret += executeProblem(dataCharArray, numDataElem, charBased);

    printf("\nPROBLEM 6\n");
    ret += executeProblem(dataCharArray, numDataElem, none);

    return ret < 0 ? -1 : 0;
}

int executeProblem(char *dataCharArray, int numDataElem, enum priorityAssignment priAssignment) {
    char *treapCharArray;
    int numTreapElem;
    bool searchResult;

    // get the char array to create the treap
    if (readCharArrayFromFile(treapInputFile, &treapCharArray, &numTreapElem) < 0) {
        printf("ERROR: Could not read array from file: %s\n", treapInputFile);
        return -1;
    }

    // create random treap
    struct tnode* root = initializeTreapFromArray(treapCharArray, numTreapElem, priAssignment);

    for (int i = 0; i < numDataElem; ++i)
        searchResult = treapSearch(root, dataCharArray[i]);
}