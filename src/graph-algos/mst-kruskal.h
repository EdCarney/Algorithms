#include <stdlib.h>
#include "set.h"
#include "graph.h"
#include "../sorting-algos/heap-sort.h"

edge *mstKruskal(graph *G, int *numMstEdges);

edge *addEdgeToArray(edge *A, int *numMstEdges, edge *edgeToAdd);