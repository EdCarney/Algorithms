#include <stdio.h>
#include <time.h>
#include <stdbool.h> 
#include "utils/utilities.h"
#include "sorting-algos/treap-sort.h"

const char * inputFile = "./../data/string-input-1.txt";
const bool printArrays = true;
clock_t clockTime;
double runtime;

int testTreapSort();

int main() {
    int ret = 0;

    ret += testTreapSort();
    puts("");

    return ret < 0 ? -1 : 0;
}

int testTreapSort() {
    char* unsortedArray;
    int numElements;
    printf("\nTREAP SORT\n");
    if (readCharArrayFromFile(inputFile, &unsortedArray, &numElements) < 0) {
        printf("ERROR: Could not read array from file: %s\n", inputFile);
        return -1;
    }

    struct tnode* root = initializeTreapFromArray(unsortedArray, numElements);

    printTreeKeyOrder(root);
    //printTreeInfoDepthFirst(root);

    printf("'A' in the treap: %s\n", treapSearch(root, 'A') ? "true" : "false");
    printf("'r' in the treap: %s\n", treapSearch(root, 'r') ? "true" : "false");

    printf("Treap satisfies BST properties: %s\n", verifyBstProperties(root) > 0 ? "false" : "true");
    printf("Treap satisfies Max-Heap properties: %s\n", verifyMaxHeapProperties(root) > 0 ? "false" : "true");
}