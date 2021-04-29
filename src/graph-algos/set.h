#include <stdlib.h>
#include "graph.h"

typedef struct _set {
    struct vertex **values;
    int numValues;
} set;

set *makeSet(vertex *value);

set *findSet(vertex *value, set *allSets, int numSets);

set *unionSets(set *setOne, set *setTwo);