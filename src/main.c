#include <stdio.h>
#include <time.h>
#include "utils/utilities.h"
#include "sorting-algos/selection-sort.h"
#include "sorting-algos/insertion-sort.h"
#include "data-structures/binary-search-tree.h"

const char * inputFile = "./../data/array-input-1.txt";
clock_t clockTime;
double runtime;

int testInsertionSort();
int testSelectionSort();
int testBinarySearchTree();

int main() {
    int ret = 0;

    ret += testInsertionSort();
    ret += testSelectionSort();
    ret += testBinarySearchTree();

    printf("\n");

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
    printf("Total time taken (ms): %f\n", runtime);
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
    return 0;
}

int testBinarySearchTree() {
    double* unsortedArray;
    int numElements;
    printf("\nBINARY SEARCH TREE\n");
    if (readArrayFromFile(inputFile, &unsortedArray, &numElements) < 0) {
        printf("ERROR: Could not read array from file: %s\n", inputFile);
        return -1;
    }

    printDoubleArray(unsortedArray, numElements);

    struct bstNode* rootNode = constructBst(unsortedArray, numElements);

    // print elements in order
    inOrderTreeWalk(rootNode);
    printf("\n");

    // print min and max
    printf("BST Min: %.1f\n", treeMinimum(rootNode)->key);
    printf("BST Max: %.1f\n", treeMaximum(rootNode)->key);

    // search for element
    printf("Element 90 in tree: %s\n", treeSearch(rootNode, 90) ? "true" : "false" );
    printf("Element 258 in tree: %s\n", treeSearch(rootNode, 258) ? "true" : "false");

    // print root node, successor, and predecessor
    printf("Root node key: %.1f\n", rootNode->key);
    printf("Root node predecessor: %.1f\n", treePredecessor(rootNode)->key);
    printf("Root node successor: %.1f\n", treeSuccessor(rootNode)->key);

    printf("\n");
    return 0;
}