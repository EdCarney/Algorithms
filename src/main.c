#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h> 
#include "utils/utilities.h"
#include "sorting-algos/treap-sort.h"

const char *treapInputFile = "./../data/string-input-1.txt";
struct timeval start_t, finish_t;

double executeProblem();

int main() {
    const char *dataInputFile = "./../data/textbook.txt";
    char *dataCharArray;
    double runtime = 0;
    int numDataElem, numRuns = 5;

    // get the array to search against
    if (readCharArrayFromFile(dataInputFile, &dataCharArray, &numDataElem) < 0) {
        printf("ERROR: Could not read array from file: %s\n", dataInputFile);
        return -1;
    }

    printf("\nPROBLEM 4: Random Priorities\n");
    for (int i = 0; i < numRuns; ++i)
        runtime += executeProblem(dataCharArray, numDataElem, randPri);
    printf("Average Search Running Time (us): %f\n", runtime / (double)numRuns);
    runtime = 0;

    printf("\nPROBLEM 5: Character-Based Priorities\n");
    for (int i = 0; i < numRuns; ++i)
        runtime += executeProblem(dataCharArray, numDataElem, charBasedPri);
    printf("Average Search Running Time (us): %f\n", runtime / (double)numRuns);
    runtime = 0;

    printf("\nPROBLEM 6: No Priorities\n");
    for (int i = 0; i < numRuns; ++i)
        runtime += executeProblem(dataCharArray, numDataElem, noPri);
    printf("Average Search Running Time (us): %f\n", runtime / (double)numRuns);
    runtime = 0;

    return 0;
}

double executeProblem(char *dataCharArray, int numDataElem, enum priorityAssignment priAssignment) {
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

    gettimeofday(&start_t, NULL);
    for (int i = 0; i < numDataElem; ++i)
        searchResult = treapSearch(root, dataCharArray[i]);
    gettimeofday(&finish_t, NULL);

    double total_t = (double)(finish_t.tv_usec - start_t.tv_usec);
    printf("Search Running Time (us): %f\n", total_t);
    return total_t;
}