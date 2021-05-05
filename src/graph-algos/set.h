#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include "graph.h"

typedef struct set {
    struct vertex **values;
    int numValues;
    int id;
} set;

set *initializeSet();

void makeSet(vertex *value, set *inputSet);

set *findSet(vertex *value, set *allSets, int numSets);

set *unionSets(set *setOne, set *setTwo);

vertex *getSetVertexById(set *S, int id);

#endif /* SET_H */