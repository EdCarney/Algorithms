#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct vertex
{
    int id;
    int key;
} vertex;

typedef struct edge
{
    int weight;

    // Starting node for the edge.
    vertex *from;

    // Ending node for the edge.
    vertex *to;
} edge;

typedef struct adjNode adjNode;
struct adjNode {
    int vertexNumber;
    int weight;
    adjNode* next;
};

typedef struct graph
{
    int numVertices;
    int numEdges;

    // List of all vertices in the graph.
    vertex *vertices;

    // List of all edges in the graph.
    edge *edges;

    // Adjacency list for the graph.
    adjNode **adjacent;
} graph;

int createGraphFromFile(const char *fileName, int numVertices, graph *graph);

int createGraphVertices(int numVertices, graph *graph);

int createGraphEdgesFromFile(const char* fileName, graph *graph);

// Initializes an adjacency list from the provided file. Assumes that there are n^2
// entries in the input file, where n is the number of vertices in the graph. The
// weight value 999 is used to indicate that there is no edge between two vertices.
// Updates the provided adjacencyList to point to the newly created adjacency list.
int createGraphAdjListFromFile(const char* fileName, graph *graph);

struct adjNode* initializeAdjNode();