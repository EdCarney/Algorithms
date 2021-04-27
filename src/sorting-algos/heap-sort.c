#include "heap-sort.h"

struct heap* initializeHeap() {
    struct heap* heap = malloc(sizeof(struct heap));
    heap->heapSize = 0;
    heap->length = 0;
    heap->values = NULL;
    return heap;
}

struct heap* initializeHeapFromEdges(struct graph *graph) {
    struct heap* heap = initializeHeap();
    heap->values = (struct edge*)calloc(graph->numEdges, sizeof(struct edge));
    heap->length = graph->numEdges;
    for (int i = 0; i < graph->numEdges; ++i)
        heap->values[i] = graph->edges[i];
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

void minHeapSort(struct heap *heap) {
    buildMinHeap(heap);
    for (int i = heap->length - 1; i > 0; --i) {
        struct edge temp = heap->values[0];
        heap->values[0] = heap->values[i];
        heap->values[i] = temp;
        --(heap->heapSize);
        minHeapify(heap, 0);
    }
}

void minHeapify(struct heap* heap, int index) {
    int left = calcLeftNode(index);
    int right = calcRightNode(index);
    int smallest = index;

    if (left < heap->heapSize && heap->values[left].weight < heap->values[smallest].weight)
        smallest = left;
    
    if (right < heap->heapSize && heap->values[right].weight < heap->values[smallest].weight)
        smallest = right;

    if (smallest != index) {
        struct edge temp = heap->values[index];
        heap->values[index] = heap->values[smallest];
        heap->values[smallest] = temp;
        minHeapify(heap, smallest);
    }
}

struct heap* buildMinHeap(struct heap* heap) {
    heap->heapSize = heap->length;
    for (int i = (int)floor((heap->length) / 2); i >= 0; --i)
        minHeapify(heap, i);
}