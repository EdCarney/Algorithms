#include<stdlib.h>
#include "graph.h"
#include "set.h"

void initSingleSource(graph *G, vertex *source);

set *shortestPathDijkstra(graph *G, vertex *source);