#include<stdlib.h>
#include "graph.h"
#include "set.h"
#include "../sorting-algos/heap-sort.h"

void initSingleSource(graph *G, vertex *source);

set *shortestPathDijkstra(graph *G, vertex *source);

set *extractVertexHeapMin(vertexHeap *heap);

void relax(vertex *u, vertex *v, int weight);