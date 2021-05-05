#include "heap-sort.h"

edgeHeap* initializeEdgeHeap() {
    edgeHeap* heap = malloc(sizeof(edgeHeap));
    heap->heapSize = 0;
    heap->length = 0;
    heap->values = NULL;
    return heap;
}

vertexHeap* initializeVertexHeap() {
    vertexHeap* heap = malloc(sizeof(vertexHeap));
    heap->heapSize = 0;
    heap->length = 0;
    heap->values = NULL;
    return heap;
}

edgeHeap* initializeHeapFromEdges(graph *inputGraph) {
    edgeHeap* heap = initializeEdgeHeap();
    heap->values = (edge*)calloc(inputGraph->numEdges, sizeof(edge));
    heap->length = inputGraph->numEdges;
    for (int i = 0; i < inputGraph->numEdges; ++i)
        heap->values[i] = inputGraph->edges[i];
    return heap;
}

vertexHeap* initializeHeapFromVertices(graph *inputGraph) {
    vertexHeap* heap = initializeVertexHeap();
    heap->values = (vertex*)calloc(inputGraph->numVertices, sizeof(vertex));
    heap->length = inputGraph->numVertices;
    for (int i = 0; i < inputGraph->numVertices; ++i)
        heap->values[i] = inputGraph->vertices[i];
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

void minEdgeHeapSort(edgeHeap *inputHeap) {
    buildMinEdgeHeap(inputHeap);
    edge temp;
    for (int i = inputHeap->length - 1; i > 0; --i) {
        temp = inputHeap->values[0];
        inputHeap->values[0] = inputHeap->values[i];
        inputHeap->values[i] = temp;
        --(inputHeap->heapSize);
        minEdgeHeapify(inputHeap, 0);
    }
}

void minVertexHeapSort(vertexHeap *inputHeap) {
    buildMinVertexHeap(inputHeap);
    vertex temp;
    for (int i = inputHeap->length - 1; i > 0; --i) {
        temp = inputHeap->values[0];
        inputHeap->values[0] = inputHeap->values[i];
        inputHeap->values[i] = temp;
        --(inputHeap->heapSize);
        minVertexHeapify(inputHeap, 0);
    }
}

void maxEdgeHeapSort(edgeHeap *inputHeap) {
    buildMaxEdgeHeap(inputHeap);
    edge temp;
    for (int i = inputHeap->length - 1; i > 0; --i) {
        temp = inputHeap->values[0];
        inputHeap->values[0] = inputHeap->values[i];
        inputHeap->values[i] = temp;
        --(inputHeap->heapSize);
        maxEdgeHeapify(inputHeap, 0);
    }
}

void maxVertexHeapSort(vertexHeap *inputHeap) {
    buildMaxVertexHeap(inputHeap);
    vertex temp;
    for (int i = inputHeap->length - 1; i > 0; --i) {
        temp = inputHeap->values[0];
        inputHeap->values[0] = inputHeap->values[i];
        inputHeap->values[i] = temp;
        --(inputHeap->heapSize);
        maxVertexHeapify(inputHeap, 0);
    }
}

void minEdgeHeapify(edgeHeap* inputHeap, int index) {
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
        minEdgeHeapify(inputHeap, smallest);
    }
}

void minVertexHeapify(vertexHeap* inputHeap, int index) {
    int left = calcLeftNode(index);
    int right = calcRightNode(index);
    int smallest = index;

    if (left < inputHeap->heapSize && inputHeap->values[left].key < inputHeap->values[smallest].key)
        smallest = left;
    
    if (right < inputHeap->heapSize && inputHeap->values[right].key < inputHeap->values[smallest].key)
        smallest = right;

    if (smallest != index) {
        vertex temp = inputHeap->values[index];
        inputHeap->values[index] = inputHeap->values[smallest];
        inputHeap->values[smallest] = temp;
        minVertexHeapify(inputHeap, smallest);
    }
}

void maxEdgeHeapify(edgeHeap* inputHeap, int index) {
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
        maxEdgeHeapify(inputHeap, largest);
    }
}

void maxVertexHeapify(vertexHeap* inputHeap, int index) {
    int left = calcLeftNode(index);
    int right = calcRightNode(index);
    int largest = index;

    if (left < inputHeap->heapSize && inputHeap->values[left].key > inputHeap->values[largest].key)
        largest = left;
    
    if (right < inputHeap->heapSize && inputHeap->values[right].key > inputHeap->values[largest].key)
        largest = right;

    if (largest != index) {
        vertex temp = inputHeap->values[index];
        inputHeap->values[index] = inputHeap->values[largest];
        inputHeap->values[largest] = temp;
        maxVertexHeapify(inputHeap, largest);
    }
}

edgeHeap* buildMinEdgeHeap(edgeHeap* inputHeap) {
    inputHeap->heapSize = inputHeap->length;
    for (int i = (int)floor((inputHeap->length) / 2); i >= 0; --i)
        minEdgeHeapify(inputHeap, i);
}

vertexHeap* buildMinVertexHeap(vertexHeap* inputHeap) {
    inputHeap->heapSize = inputHeap->length;
    for (int i = (int)floor((inputHeap->length) / 2); i >= 0; --i)
        minVertexHeapify(inputHeap, i);
}

edgeHeap* buildMaxEdgeHeap(edgeHeap* inputHeap) {
    inputHeap->heapSize = inputHeap->length;
    for (int i = (int)floor((inputHeap->length) / 2); i >= 0; --i)
        maxEdgeHeapify(inputHeap, i);
}

vertexHeap* buildMaxVertexHeap(vertexHeap* inputHeap) {
    inputHeap->heapSize = inputHeap->length;
    for (int i = (int)floor((inputHeap->length) / 2); i >= 0; --i)
        maxVertexHeapify(inputHeap, i);
}

bool vertexIdInHeap(vertexHeap *H, int id) {
    for (int i = 0; i < H->length; ++i)
        if (H->values[i].id == id)
            return true;
    return false;
}

vertex *getHeapVertexById(vertexHeap *H, int id) {
    for (int i = 0; i < H->length; ++i)
        if (H->values[i].id == id)
            return &H->values[i];
    return NULL;
}