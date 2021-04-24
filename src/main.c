#include <stdio.h>
#include "utils/utilities.h"

const char *inputFile = "./data/graph_info.txt";
const int numVertices = 20;

int main() {
    printf("Hello world!\n");

    struct adjNode **adjacencyList;
    readAdjacencyListFromFile(inputFile, numVertices, &adjacencyList);

    struct adjNode* currNode;
    for (int i = 0; i < numVertices; ++i) {
        printf("Vertex %d Connections (vertex, weight): \n  ", i + 1);
        currNode = adjacencyList[i];
        while (currNode != NULL) {
            printf("(%d, %d) ", currNode->vertexNumber, currNode->weight);
            currNode = currNode->next;
        }
        printf("\n");
    }

    return 0;
}