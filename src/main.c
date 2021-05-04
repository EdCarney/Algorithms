#include <stdio.h>
#include "graph-algos/graph.h"
#include "graph-algos/set.h"
#include "graph-algos/mst-kruskal.h"
#include "graph-algos/shortest-path-dijkstra.h"
#include "sorting-algos/heap-sort.h"

const char *inputFile = "./data/graph_info.txt";
const int numVertices = 20;

void printAdjacencyLists(const char *inputFile, int numVertices);
void findAndPrintRootedMst(const char *inputFile, int numVertices, int sourceVertex);
void findAndPrintShortestPath(const char *inputFile, int numVertices, int sourceVertex);

int main() {

    printAdjacencyLists(inputFile, numVertices);
    findAndPrintRootedMst(inputFile, numVertices, 1);

    return 0;
}

void printHeaderBar() {
    puts("-----------------------------------------");
}

void printAdjacencyLists(const char *inputFile, int numVertices) {
    graph G;
    int numMstVertices, totalWeight = 0;
    vertex mstVertex;

    createGraphFromFile(inputFile, numVertices, &G);

    puts("\nAdjacency List Values (NODE ID, WEIGHT)");
    printHeaderBar();
    adjNode* currNode;
    for (int i = 0; i < G.numVertices; ++i) {
        currNode = G.adjacent[i];
        printf("NODE %d: ", i + 1);
        while (currNode != NULL) {
            printf("(%d, %d) ", currNode->vertexNumber, currNode->weight);
            currNode = currNode->next;
        }
        printf("\n");
    }
    printHeaderBar();
}

void findAndPrintRootedMst(const char *inputFile, int numVertices, int sourceVertex) {
    graph G;
    int numMstVertices, totalWeight = 0;
    vertex mstVertex;

    createGraphFromFile(inputFile, numVertices, &G);
    vertex *mst = mstKruskalWithRoot(&G, &numMstVertices, sourceVertex);

    printf("\nKruskal MST Rooted at Node %d\n", sourceVertex);
    printHeaderBar();
    for (int i = 0; i < numMstVertices; ++i) {
        mstVertex = mst[i];
        printf("VERTEX: %d,\tPARENT: %d,\tWEIGHT: %d\n", mstVertex.id, mstVertex.parent->id, mstVertex.key);
        totalWeight += mstVertex.key;
    }
    printf("VERTEX: %d,\tPARENT: %s,\tWEIGHT: %d\n", sourceVertex, "NULL", 0);
    printf("TOTAL COST: %d\n", totalWeight);
    printHeaderBar();
    printf("\n");
}

void findAndPrintShortestPath(const char *inputFile, int numVertices, int sourceVertex) {
    graph G;

    createGraphFromFile(inputFile, numVertices, &G);

}
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