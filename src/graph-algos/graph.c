#include "graph.h"

int createGraphFromFile(const char *fileName, int numVertices, struct graph *graph) {
    FILE *fp;
    int weight = 0, numEdges = 0;
    
    if (!(fp = fopen(fileName, "r")))
        return -1;

    // create new graph
    graph = malloc(sizeof(struct graph));
    
    // populate vertices
    graph->numVertices = numVertices;
    graph->vertices = (struct vertex*)calloc(numVertices, sizeof(struct vertex));

    for (int i = 0; i < numVertices; ++i) {
        graph->vertices[i].id = i + 1;
        graph->vertices->key = INT_MAX; // closest thing to inf in C
    }

    // populate edges

    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            fscanf(fp, "%d", weight);
            if (j != i && weight < 999) {
                ++numEdges;
            }
        }
    }

    graph->numEdges = numEdges;
    graph->edges = (struct edge*)calloc(numEdges, sizeof(struct edge));

    numEdges = 0;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            fscanf(fp, "%d", weight);
            if (j != i && weight < 999) {
                graph->edges[numEdges].from = graph->vertices[i];
                graph->edges[numEdges].to = graph->vertices[j];
                graph->edges[numEdges].weight = weight;
                ++numEdges;
            }
        }
    }

    // populate adjacency list
    readAdjacencyListFromFile(fileName, numVertices, &graph->adjacent);

    return 0;
}