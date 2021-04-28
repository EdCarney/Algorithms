#include <stdio.h>
#include "graph-algos/graph.h"

const char *inputFile = "./data/graph_info.txt";
const int numVertices = 20;

int main() {
    
    graph G;
    createGraphFromFile(inputFile, numVertices, &G);

    printf("NUM VERTICES: %d\n", G.numVertices);
    printf("NUM EDGES: %d\n", G.numEdges);

    puts("VERTEX VALUES");
    for (int i = 0; i < G.numVertices; ++i) {
        printf("Id: %d, Key: %d\n", G.vertices[i].id, G.vertices[i].key);
    }

    puts("EDGE VALUES");
    for (int i = 0; i < G.numEdges; ++i) {
        printf("From: %d, To: %d, Weight: %d\n", G.edges[i].from->id, G.edges[i].to->id, G.edges[i].weight);
    }

    puts("ADJACENCY VALUES");
    adjNode* currNode;
    for (int i = 0; i < G.numVertices; ++i) {
        currNode = G.adjacent[i];
        while (currNode != NULL) {
            printf("(%d, %d) ", currNode->vertexNumber, currNode->weight);
            currNode = currNode->next;
        }
        printf("\n");
    }

    return 0;
}