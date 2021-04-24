struct adjNode {
    int vertexNumber;
    int weight;
    struct adjNode* next;
};

// Initializes an adjacency list from the provided file. Assumes that there are n^2
// entries in the input file, where n is the number of vertices in the graph. The
// weight value 999 is used to indicate that there is no edge between two vertices.
// Updates the provided adjacencyList to point to the newly created adjacency list.
int readAdjacencyListFromFile(const char* fileName, int numVertices, struct adjNode ** adjacencyList[]);