#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct adjNode {
    int vertexNumber;
    int weight;
    struct adjNode* next;
};


int readAdjacencyListFromFile(const char* fileName, int numVertices, struct adjNode ** adjacencyList[]);