#include <stdio.h>
#include "graph-algos/graph.h"
#include "graph-algos/set.h"
#include "sorting-algos/heap-sort.h"

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

    puts("MIN HEAP SORTED EDGES");
    heap *H = initializeHeapFromEdges(&G);
    maxHeapSort(H);
    for (int i = 0; i < H->length; ++i) {
        printf("From: %d, To: %d, Weight: %d\n", H->values[i].from->id, H->values[i].to->id, H->values[i].weight);
    }

    set *allSets = calloc(G.numVertices, sizeof(vertex));
    for (int i = 0; i < G.numVertices; ++i) {
        makeSet(&G.vertices[i], &allSets[i]);
    }

    puts("ALL SETS");
    for (int i = 0; i < G.numVertices; ++i) {
        printf("Set: %d, Num Values: %d, Vertex ID: %d\n", i, allSets[i].numValues, allSets[i].values[0]->id);
    }

    return 0;
}