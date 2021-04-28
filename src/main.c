#include <stdio.h>
#include "graph-algos/graph.h"

const char *inputFile = "./data/graph_info.txt";
const int numVertices = 20;

int main() {
    
    struct graph graph;
    createGraphFromFile(inputFile, numVertices, &graph);

    printf("NUM VERTICES: %d\n", graph.numVertices);
    printf("NUM EDGES: %d\n", graph.numEdges);

    puts("VERTEX VALUES");
    for (int i = 0; i < graph.numVertices; ++i) {
        printf("Id: %d, Key: %d\n", graph.vertices[i].id, graph.vertices[i].key);
    }

    puts("EDGE VALUES");
    for (int i = 0; i < graph.numEdges; ++i) {
        printf("From: %d, To: %d, Weight: %d\n", graph.edges[i].from->id, graph.edges[i].to->id, graph.edges[i].weight);
    }

    puts("ADJACENCY VALUES");
    struct adjNode* currNode;
    for (int i = 0; i < graph.numVertices; ++i) {
        currNode = graph.adjacent[i];
        while (currNode != NULL) {
            printf("(%d, %d) ", currNode->vertexNumber, currNode->weight);
            currNode = currNode->next;
        }
        printf("\n");
    }

    return 0;
}