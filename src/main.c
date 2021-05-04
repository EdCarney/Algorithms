#include <stdio.h>
#include "graph-algos/graph.h"
#include "graph-algos/set.h"
#include "graph-algos/mst-kruskal.h"
#include "sorting-algos/heap-sort.h"

const char *inputFile = "./data/graph_info.txt";
const int numVertices = 20;

int main() {
    /*
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

    set *allSets = calloc(G.numVertices, sizeof(set));
    for (int i = 0; i < G.numVertices; ++i) {
        makeSet(&G.vertices[i], &allSets[i]);
    }

    puts("ALL SETS");
    for (int i = 0; i < G.numVertices; ++i) {
        printf("Set: %d, Num Values: %d, Vertex ID: %d\n", i, allSets[i].numValues, allSets[i].values[0]->id);
    }

    puts("FIND IN SETS");
    set *foundSet;
    for (int i = 0; i < G.numEdges; ++i) {
        foundSet = findSet(G.edges[i].from, allSets, G.numVertices);
        printf("SET ID: %d\n", foundSet->id);
    }

    set *unionSet = unionSets(&allSets[0], &allSets[1]);
    printf("NUM VALUES: %d\n", unionSet->numValues);
    for (int i = 0; i < unionSet->numValues; ++i) {
        printf("VALUE: %d\n", unionSet->values[i]->id);
    }
    */

    // puts("EDGE VALUES");
    // for (int i = 0; i < G.numEdges; ++i) {
    //     printf("From: %d, To: %d, Weight: %d\n", G.edges[i].from->id, G.edges[i].to->id, G.edges[i].weight);
    // }

    graph G;
    int numMstVertices;
    vertex mstVertex;

    createGraphFromFile(inputFile, numVertices, &G);
    vertex *mst_2 = mstKruskalWithRoot(&G, &numMstVertices, 1);

    puts("\nKruskal MST Rooted at Node 1");
    for (int i = 0; i < numMstVertices; ++i) {
        mstVertex = mst_2[i];
        printf("VERTEX ID: %d, PARENT ID: %d, WEIGHT: %d\n", mstVertex.id, mstVertex.parent->id, mstVertex.key);
    }
    printf("VERTEX ID: %d, PARENT ID: %s, WEIGHT: %d\n\n", 1, "NULL", 0);

    return 0;
}