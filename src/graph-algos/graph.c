#include "graph.h"

int createGraphFromFile(const char *fileName, int numVertices, graph *inputGraph) {

    // create new graph
    graph *ret = malloc(sizeof(graph));

    // populate vertices
    createGraphVertices(numVertices, ret);

    // populate edges
    createGraphEdgesFromFile(fileName, ret);

    // populate adjacency list
    createGraphAdjListFromFile(fileName, ret);

    *inputGraph = *ret;

    return 0;
}

int createGraphVertices(int numVertices, graph *inputGraph) {
    int inf = 2147483647;
    inputGraph->numVertices = numVertices;
    inputGraph->vertices = (vertex*)calloc(numVertices, sizeof(vertex));

    for (int i = 0; i < numVertices; ++i) {
        inputGraph->vertices[i].id = i + 1;
        inputGraph->vertices[i].key = inf;
    }
}

int createGraphEdgesFromFile(const char* fileName, graph *inputGraph) {
    int weight = 0, numEdges = 0;
    FILE *fp;

    if (!(fp = fopen(fileName, "r")))
        return -1;

    for (int i = 0; i < inputGraph->numVertices; ++i) {
        for (int j = 0; j < inputGraph->numVertices; ++j) {
            fscanf(fp, "%d", &weight);
            if (j != i && weight < 999) {
                ++numEdges;
            }
        }
    }

    inputGraph->numEdges = numEdges;
    inputGraph->edges = (edge*)calloc(numEdges, sizeof(edge));

    rewind(fp);

    numEdges = 0;
    for (int i = 0; i < inputGraph->numVertices; ++i) {
        for (int j = 0; j < inputGraph->numVertices; ++j) {
            fscanf(fp, "%d", &weight);
            if (j != i && weight < 999) {
                inputGraph->edges[numEdges].from = &inputGraph->vertices[i];
                inputGraph->edges[numEdges].to = &inputGraph->vertices[j];
                inputGraph->edges[numEdges].weight = weight;
                ++numEdges;
            }
        }
    }

    fclose(fp);

    return 0;
} 

int createGraphAdjListFromFile(const char* fileName, graph *inputGraph) {
    FILE* fp;
    adjNode **ret, *currNode;
    int weight = 0;

    if (!(fp = fopen(fileName, "r")))
        return -1;

    // initalize adjacency list with default node values
    for (int i = 0; i < inputGraph->numVertices; ++i)
        if (!(ret = (adjNode**)calloc(inputGraph->numVertices, sizeof(adjNode*))))
            return -1;

    for (int i = 0; i < inputGraph->numVertices; ++i) {
        ret[i] = initializeAdjNode();
        currNode = ret[i];

        for (int j = 1; j <= inputGraph->numVertices; ++j) {
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
    inputGraph->adjacent = ret;
}

adjNode* initializeAdjNode() {
    adjNode* node = malloc(sizeof(adjNode));
    node->vertexNumber = -1;
    node->weight = -1;
    node->next = NULL;
    return node;
}

vertex *getGraphVertexById(graph *G, int id) {
    for (int i = 0; i < G->numVertices; ++i)
        if (G->vertices[i].id == id)
            return &G->vertices[i];
}
