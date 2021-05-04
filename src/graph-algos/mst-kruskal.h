#include <stdlib.h>
#include "set.h"
#include "graph.h"
#include "queue.h"
#include "../sorting-algos/heap-sort.h"

edge *mstKruskal(graph *G, int *numMstEdges);

vertex *mstKruskalWithRoot(graph *G, int *numMstEdges, int sourceId);

edge *addEdgeToArray(edge *A, int *numMstEdges, edge edgeToAdd);

set *mergeSets(set *set1, set *set2, set *allSets, int *numSets);