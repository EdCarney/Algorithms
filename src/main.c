#include <stdio.h>
#include <time.h>
#include "utils/utilities.h"
#include "sorting-algos/selection-sort.h"
#include "sorting-algos/insertion-sort.h"
#include "data-structures/binary-search-tree.h"

const char * inputFile = "./../data/array-input-2.txt";
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
    puts("");

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
    puts("");

    // print min and max
    printf("BST Min: %.1f\n", treeMinimum(rootNode)->key);
    printf("BST Max: %.1f\n", treeMaximum(rootNode)->key);

    // search for element
    double goodSearch = 12, badSearch = 258;
    printf("Element %.1f in tree: %s\n", goodSearch, treeSearch(rootNode, goodSearch) ? "true" : "false" );
    printf("Element %.1f in tree: %s\n", badSearch, treeSearch(rootNode, badSearch) ? "true" : "false");

    // print root node, successor, and predecessor
    printf("Root node key: %.1f\n", rootNode->key);
    printf("Root node predecessor: %.1f\n", treePredecessor(rootNode)->key);
    printf("Root node successor: %.1f\n", treeSuccessor(rootNode)->key);

    // insert new node and print again
    double insertKey = 30;
    printf("Inserting new node in BST with key: %.1f\n", insertKey);
    struct bstNode* newNode = initializeBstNodeWithKey(insertKey);
    treeInsert(rootNode, newNode);
    inOrderTreeWalk(rootNode);
    puts("");

    // remove added node and print again
    printf("Deleting node in BST with key: %.1f\n", insertKey);
    treeDelete(&rootNode, newNode);
    inOrderTreeWalk(rootNode);
    puts("\nDeleting root node in BST");
    treeDelete(&rootNode, rootNode);
    inOrderTreeWalk(rootNode);
    puts("");
    return 0;
}