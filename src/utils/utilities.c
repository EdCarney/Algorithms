#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

struct adjNode* initializeAdjacencyNode() {
    struct adjNode* node = malloc(sizeof(struct adjNode));
    node->vertexNumber = -1;
    node->weight = -1;
    node->next = NULL;
    return node;
}

int readAdjacencyListFromFile(const char* fileName, int numVertices, struct adjNode ** adjListPtr) {
    FILE* fp;
    struct adjNode *ret, *currNode;
    int weight = 0;

    if (!(fp = fopen(fileName, "r")))
        return -1;

    // initalize adjacency list with default node values
    for (int i = 0; i < numVertices; ++i)

    if (!(ret = (struct adjNode*)calloc(numVertices, sizeof(struct adjNode))))
        return -1;

    for (int i = 0; i < numVertices; ++i) {
        currNode = &ret[i];

        for (int j = 1; j <= numVertices; ++j) {
            fscanf(fp, "%d", &weight);
            if (weight != 999) {
                currNode->vertexNumber = j;
                currNode->weight = weight;
                currNode->next = initializeAdjacencyNode();
                currNode = currNode->next;
            }
        }
        currNode = NULL;
    }

    *adjListPtr = ret;

    fclose(fp);
}