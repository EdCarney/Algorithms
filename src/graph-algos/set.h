#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include "graph.h"

typedef struct set {
    struct vertex **values;
    int numValues;
    int id;
} set;

void makeSet(vertex *value, set *inputSet);

set *findSet(vertex *value, set *allSets, int numSets);

set *unionSets(set *setOne, set *setTwo);

#endif /* SET_H */