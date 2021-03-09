#include <math.h>
#include <stdlib.h>
#include <stdio.h>

struct heap {
    int heapSize;
    int length;
    double* values;
};

// Allocates memory for a new heap and sets all values
// to their defaults (numerical as zero, pointers as NULL).
// Returns a pointer to the allocated memory.
struct heap* initializeHeap();

// Allocates memory for a new BST node and sets all values
// to their defaults except for the heap values and length.
// Heap values are copied from the input array and heap
// length is set to the same as the number of elements.
// Returns a pointer to the allocated memory.
struct heap* initializeHeapFromArray(double inputArray[], int numElements);

// Returns the index value yielding the parent of the heap
// node at the provided index.
int calcParentNode(int i);

// Returns the index value yielding the left child of the
// heap node at the provided index.
int calcLeftNode(int i);

// Returns the index value yielding the right child of the
// heap node at the provided index.
int calcRightNode(int i);

// Performs an in-place sort of the provided heap.
void heapSort(struct heap* heap);

// Updates the heap to maintain the max-heap property at the
// provided index. Note that any child trees off of the heap
// node at the provided index are assumed to already adhere
// to the max-heap property.
void maxHeapify(struct heap* heap, int index);

// Contructs a max heap via an in-place reordering of the heap
// nodes. Returns a pointer to the max heap.
struct heap* buildMaxHeap(struct heap* heap);