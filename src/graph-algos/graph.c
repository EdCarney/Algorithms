#include "graph.h"

int createGraphFromFile(const char *fileName, int numVertices, struct graph *graph) {

    // create new graph
    struct graph *ret = malloc(sizeof(struct graph));

    // populate vertices
    createGraphVertices(numVertices, ret);

    // populate edges
    createGraphEdgesFromFile(fileName, ret);

    // populate adjacency list
    createGraphAdjListFromFile(fileName, ret);

    *graph = *ret;

    return 0;
}

int createGraphVertices(int numVertices, struct graph *graph) {
    graph->numVertices = numVertices;
    graph->vertices = (struct vertex*)calloc(numVertices, sizeof(struct vertex));

    for (int i = 0; i < numVertices; ++i) {
        graph->vertices[i].id = i + 1;
        graph->vertices[i].key = INT_MAX; // closest thing to inf in C
    }
}

int createGraphEdgesFromFile(const char* fileName, struct graph *graph) {
    int weight = 0, numEdges = 0;
    FILE *fp;

    if (!(fp = fopen(fileName, "r")))
        return -1;

    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            fscanf(fp, "%d", &weight);
            if (j != i && weight < 999) {
                ++numEdges;
            }
        }
    }

    graph->numEdges = numEdges;
    graph->edges = (struct edge*)calloc(numEdges, sizeof(struct edge));

    rewind(fp);

    numEdges = 0;
    for (int i = 0; i < graph->numVertices; ++i) {
        for (int j = 0; j < graph->numVertices; ++j) {
            fscanf(fp, "%d", &weight);
            if (j != i && weight < 999) {
                graph->edges[numEdges].from = &(graph->vertices[i]);
                graph->edges[numEdges].to = &(graph->vertices[j]);
                graph->edges[numEdges].weight = weight;
                ++numEdges;
            }
        }
    }

    fclose(fp);

    return 0;
} 

int createGraphAdjListFromFile(const char* fileName, struct graph *graph) {
    FILE* fp;
    struct adjNode **ret, *currNode;
    int weight = 0;

    if (!(fp = fopen(fileName, "r")))
        return -1;

    // initalize adjacency list with default node values
    for (int i = 0; i < graph->numVertices; ++i)
        if (!(ret = (struct adjNode**)calloc(graph->numVertices, sizeof(struct adjNode*))))
            return -1;

    for (int i = 0; i < graph->numVertices; ++i) {
        ret[i] = initializeAdjNode();
        currNode = ret[i];

        for (int j = 1; j <= graph->numVertices; ++j) {
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
    graph->adjacent = ret;
}

struct adjNode* initializeAdjNode() {
    struct adjNode* node = malloc(sizeof(struct adjNode));
    node->vertexNumber = -1;
    node->weight = -1;
    node->next = NULL;
    return node;
}