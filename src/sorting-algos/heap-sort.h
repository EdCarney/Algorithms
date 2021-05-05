#ifndef HEAP_H
#define HEAP_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../graph-algos/graph.h"

typedef struct edgeHeap {
    int heapSize;
    int length;
    edge *values;
} edgeHeap;

typedef struct vertexHeap {
    int heapSize;
    int length;
    vertex *values;
} vertexHeap;

// Allocates memory for a new heap and sets all values
// to their defaults (numerical as zero, pointers as NULL).
// Returns a pointer to the allocated memory.
edgeHeap* initializeEdgeHeap();

// Allocates memory for a new heap and sets all values
// to their defaults (numerical as zero, pointers as NULL).
// Returns a pointer to the allocated memory.
vertexHeap* initializeVertexHeap();

// Allocates memory for a new BST node and sets all values
// to their defaults except for the heap values and length.
// Heap values are copied from the input array and heap
// length is set to the same as the number of elements.
// Returns a pointer to the allocated memory.
edgeHeap* initializeHeapFromEdges(graph *inputGraph);

// Allocates memory for a new BST node and sets all values
// to their defaults except for the heap values and length.
// Heap values are copied from the input array and heap
// length is set to the same as the number of elements.
// Returns a pointer to the allocated memory.
vertexHeap* initializeHeapFromVertices(graph *inputGraph);

// Returns the index value yielding the parent of the heap
// node at the provided index.
int calcParentNode(int i);

// Returns the index value yielding the left child of the
// heap node at the provided index.
int calcLeftNode(int i);

// Returns the index value yielding the right child of the
// heap node at the provided index.
int calcRightNode(int i);

// Performs an in-place max sort of the provided heap.
void maxEdgeHeapSort(edgeHeap* heap);

// Performs an in-place max sort of the provided heap.
void maxVertexHeapSort(vertexHeap* heap);

// Performs an in-place max sort of the provided heap.
void minEdgeHeapSort(edgeHeap* heap);

// Performs an in-place max sort of the provided heap.
void minVertexHeapSort(vertexHeap* heap);

// Updates the heap to maintain the max-heap property at the
// provided index. Note that any child trees off of the heap
// node at the provided index are assumed to already adhere
// to the max-heap property.
void maxEdgeHeapify(edgeHeap* heap, int index);

// Updates the heap to maintain the max-heap property at the
// provided index. Note that any child trees off of the heap
// node at the provided index are assumed to already adhere
// to the max-heap property.
void maxVertexHeapify(vertexHeap* heap, int index);

// Updates the heap to maintain the min-heap property at the
// provided index. Note that any child trees off of the heap
// node at the provided index are assumed to already adhere
// to the min-heap property.
void minEdgeHeapify(edgeHeap* heap, int index);

// Updates the heap to maintain the min-heap property at the
// provided index. Note that any child trees off of the heap
// node at the provided index are assumed to already adhere
// to the min-heap property.
void minVertexHeapify(vertexHeap* heap, int index);

// Contructs a max heap via an in-place reordering of the heap
// nodes. Returns a pointer to the max heap.
edgeHeap* buildMaxEdgeHeap(edgeHeap* heap);

// Contructs a max heap via an in-place reordering of the heap
// nodes. Returns a pointer to the max heap.
vertexHeap* buildMaxVertexHeap(vertexHeap* heap);

// Contructs a min heap via an in-place reordering of the heap
// nodes. Returns a pointer to the max heap.
edgeHeap* buildMinEdgeHeap(edgeHeap* heap);

// Contructs a min heap via an in-place reordering of the heap
// nodes. Returns a pointer to the max heap.
vertexHeap* buildMinVertexHeap(vertexHeap* heap);

vertex *getHeapVertexById(vertexHeap *H, int id);

bool vertexIdInHeap(vertexHeap *H, int id);

#endif /* HEAP_H */