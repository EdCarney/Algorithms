#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct graph
{
    int numVertices;
    int numEdges;

    // List of all vertices in the graph.
    struct vertex *vertices;

    // List of all edges in the graph.
    struct edge *edges;

    // Adjacency list for the graph.
    struct adjNode **adjacent;
};

struct vertex
{
    int id;
    int key;
};

struct edge
{
    int weight;

    // Starting node for the edge.
    struct vertex *from;

    // Ending node for the edge.
    struct vertex *to;
};

struct adjNode {
    int vertexNumber;
    int weight;
    struct adjNode* next;
};

int createGraphFromFile(const char *fileName, int numVertices, struct graph *graph);

int createGraphVertices(int numVertices, struct graph *graph);

int createGraphEdgesFromFile(const char* fileName, struct graph *graph);

// Initializes an adjacency list from the provided file. Assumes that there are n^2
// entries in the input file, where n is the number of vertices in the graph. The
// weight value 999 is used to indicate that there is no edge between two vertices.
// Updates the provided adjacencyList to point to the newly created adjacency list.
int createGraphAdjListFromFile(const char* fileName, int numVertices, struct adjNode ** adjListPtr[]);

struct adjNode* initializeAdjNode();