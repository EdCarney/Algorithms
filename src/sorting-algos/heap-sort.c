#include "heap-sort.h"

heap* initializeHeap() {
    heap* heap = malloc(sizeof(heap));
    heap->heapSize = 0;
    heap->length = 0;
    heap->values = NULL;
    return heap;
}

heap* initializeHeapFromEdges(graph *inputGraph) {
    heap* heap = initializeHeap();
    heap->values = (edge*)calloc(inputGraph->numEdges, sizeof(edge));
    heap->length = inputGraph->numEdges;
    for (int i = 0; i < inputGraph->numEdges; ++i)
        heap->values[i] = inputGraph->edges[i];
    return heap;
}

int calcParentNode(int i) {
    return (int)floor(i / 2);
}

int calcLeftNode(int i) {
    return (2 * (i + 1)) - 1;
}

int calcRightNode(int i) {
    return 2 * (i + 1);
}

void minHeapSort(heap *inputHeap) {
    buildMinHeap(inputHeap);
    for (int i = inputHeap->length - 1; i > 0; --i) {
        edge temp = inputHeap->values[0];
        inputHeap->values[0] = inputHeap->values[i];
        inputHeap->values[i] = temp;
        --(inputHeap->heapSize);
        minHeapify(inputHeap, 0);
    }
}

void maxHeapSort(heap *inputHeap) {
    buildMaxHeap(inputHeap);
    for (int i = inputHeap->length - 1; i > 0; --i) {
        edge temp = inputHeap->values[0];
        inputHeap->values[0] = inputHeap->values[i];
        inputHeap->values[i] = temp;
        --(inputHeap->heapSize);
        maxHeapify(inputHeap, 0);
    }
}

void minHeapify(heap* inputHeap, int index) {
    int left = calcLeftNode(index);
    int right = calcRightNode(index);
    int smallest = index;

    if (left < inputHeap->heapSize && inputHeap->values[left].weight < inputHeap->values[smallest].weight)
        smallest = left;
    
    if (right < inputHeap->heapSize && inputHeap->values[right].weight < inputHeap->values[smallest].weight)
        smallest = right;

    if (smallest != index) {
        edge temp = inputHeap->values[index];
        inputHeap->values[index] = inputHeap->values[smallest];
        inputHeap->values[smallest] = temp;
        minHeapify(inputHeap, smallest);
    }
}

void maxHeapify(heap* inputHeap, int index) {
    int left = calcLeftNode(index);
    int right = calcRightNode(index);
    int largest = index;

    if (left < inputHeap->heapSize && inputHeap->values[left].weight > inputHeap->values[largest].weight)
        largest = left;
    
    if (right < inputHeap->heapSize && inputHeap->values[right].weight > inputHeap->values[largest].weight)
        largest = right;

    if (largest != index) {
        edge temp = inputHeap->values[index];
        inputHeap->values[index] = inputHeap->values[largest];
        inputHeap->values[largest] = temp;
        maxHeapify(inputHeap, largest);
    }
}

heap* buildMinHeap(heap* inputHeap) {
    inputHeap->heapSize = inputHeap->length;
    for (int i = (int)floor((inputHeap->length) / 2); i >= 0; --i)
        minHeapify(inputHeap, i);
}

heap* buildMaxHeap(heap* inputHeap) {
    inputHeap->heapSize = inputHeap->length;
    for (int i = (int)floor((inputHeap->length) / 2); i >= 0; --i)
        maxHeapify(inputHeap, i);
}