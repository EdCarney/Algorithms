#include "utilities.h"

struct adjNode* initializeAdjNode() {
    struct adjNode* node = malloc(sizeof(struct adjNode));
    node->vertexNumber = -1;
    node->weight = -1;
    node->next = NULL;
    return node;
}

struct adjNode* initializeAdjNodeWithVals(int vertex, int weight) {
    struct adjNode* node = initializeAdjNode();
    node->vertexNumber = vertex;
    node->weight = weight;
    return node;
}

int readAdjacencyListFromFile(const char* fileName, int numVertices, struct adjNode ** adjListPtr[]) {
    FILE* fp;
    struct adjNode **ret, *currNode, *headNode;
    bool firstNode = false;
    int weight = 0;

    if (!(fp = fopen(fileName, "r")))
        return -1;

    // initalize adjacency list with default node values
    for (int i = 0; i < numVertices; ++i)

    if (!(ret = (struct adjNode**)calloc(numVertices, sizeof(struct adjNode*))))
        return -1;

    for (int i = 0; i < numVertices; ++i) {
        ret[i] = initializeAdjNode();
        currNode = ret[i];

        for (int j = 1; j <= numVertices; ++j) {
            fscanf(fp, "%d", &weight);
            if (weight != 999) {
                currNode->vertexNumber = j;
                currNode->weight = weight;
                currNode->next = initializeAdjNode();
                currNode = currNode->next;
            }
        }

        // remove the ternary value
         currNode = ret[i];
         while (currNode->next->vertexNumber > 0)
            currNode = currNode->next;
        currNode->next = NULL;
    }

    fclose(fp);
    *adjListPtr = ret;
}