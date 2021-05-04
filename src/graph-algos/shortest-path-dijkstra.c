#include "shortest-path-dijkstra.h"

void initSingleSource(graph *G, vertex *source) {
    for (int i = 0; i < G->numVertices; ++i) {
        G->vertices[i].key = INT_MAX;
        G->vertices[i].parent = NULL;
    }
    source->key = 0;
}

set *shortestPathDijkstra(graph *G, vertex *source) {
    initSingleSource(G, source);
    set *S = initializeSet();
    
}