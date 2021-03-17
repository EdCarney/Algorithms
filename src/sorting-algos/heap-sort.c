#include "heap-sort.h"

struct heap* initializeHeap() {
    struct heap* heap = malloc(sizeof(struct heap));
    heap->heapSize = 0;
    heap->length = 0;
    heap->values = NULL;
    return heap;
}

struct heap* initializeHeapFromArray(double inputArray[], int numElements) {
    struct heap* heap = initializeHeap();
    heap->values = (double*)calloc(numElements, sizeof(double));
    heap->length = numElements;
    for (int i = 0; i < numElements; ++i)
        heap->values[i] = inputArray[i];
    return heap;
}

int calcParentNode(int i) {
    return (int)floor(i / 2);
}

int calcLeftNode(int i) {
    return 2 * i;
}

int calcRightNode(int i) {
    return 2 * i + 1;
}

void heapSort(struct heap* heap) {
    buildMaxHeap(heap);
    for (int i = heap->length - 1; i > 0; --i) {
        double temp = heap->values[0];
        heap->values[0] = heap->values[i];
        heap->values[i] = temp;
        --(heap->heapSize);
        maxHeapify(heap, 0);
    }
}

void maxHeapify(struct heap* heap, int index) {
    int left = calcLeftNode(index);
    int right = calcRightNode(index);
    int largest = index;

    if (left < heap->heapSize && heap->values[left] > heap->values[largest])
        largest = left;
    
    if (right < heap->heapSize && heap->values[right] > heap->values[largest])
        largest = right;

    if (largest != index) {
        double temp = heap->values[index];
        heap->values[index] = heap->values[largest];
        heap->values[largest] = temp;
        maxHeapify(heap, largest);
    }
}

struct heap* buildMaxHeap(struct heap* heap) {
    heap->heapSize = heap->length;
    for (int i = (int)floor((heap->length) / 2); i >= 0; --i)
        maxHeapify(heap, i);
}