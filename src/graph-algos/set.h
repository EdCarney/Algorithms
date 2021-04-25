#include <stdlib.h>
#include "graph.h"

struct set *makeSet(struct vertex *value);

struct set *findSet(struct vertex *value, struct set *allSets, int numSets);

struct set *unionSets(struct set *setOne, struct set *setTwo);