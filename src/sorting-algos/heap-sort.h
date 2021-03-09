#include <math.h>
#include <stdlib.h>

struct heap {
    int heapSize;
    int length;
    double* values;
};

struct heap* initializeHeap();

struct heap* initializeHeapFromArray(double inputArray[], int numElements);

int calcParentNode(int i);

int calcLeftNode(int i);

int calcRightNode(int i);

void heapSort(struct heap* heap);

void maxHeapify(struct heap* heap, int index);

struct heap* buildMaxHeap(struct heap* heap);