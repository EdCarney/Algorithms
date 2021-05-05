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
void findAndPrintShortestPath(const char *inputFile, int numVertices, int sourceVertex, int destVertex);

int main() {

    printAdjacencyLists(inputFile, numVertices);
    findAndPrintRootedMst(inputFile, numVertices, 1);
    findAndPrintShortestPath(inputFile, numVertices, 3, 19);

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
        printf("VERTEX %d:\t", i + 1);
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

void findAndPrintShortestPath(const char *inputFile, int numVertices, int sourceVertex, int destVertex) {
    graph G;
    createGraphFromFile(inputFile, numVertices, &G);
    set *S = shortestPathDijkstra(&G, getGraphVertexById(&G, sourceVertex));

    // find the destination vertex
    vertex *dest;
    for (int i = 0; i < S->numValues; ++i) {
        if (S->values[i]->id == destVertex) {
            dest = S->values[i];
            break;
        }
    }

    printf("\nDijkstra Shortest Path From %d To %d\n", sourceVertex, destVertex);
    printHeaderBar();

    printf("PATH: ");
    int totalCost = dest->key;
    while (dest) {
        printf("%d > ", dest->id);
        dest = dest->parent;
    }
    printf("NULL\n");
    printf("TOTAL COST: %d\n", totalCost);

    printHeaderBar();
    printf("\n");
}