#include "set.h"

void makeSet(vertex *value, set *inputSet) {
    set *s = (set*)malloc(sizeof(set));
    s->values = (struct vertex**)calloc(1, sizeof(struct vertex*));
    s->values[0] = value;
    s->numValues = 1;
    s->id = value->id;
    *inputSet = *s;
}

set *findSet(struct vertex *value, set *allSets, int numSets) {
    for (int i = 0; i < numSets; ++i) {
        for (int j = 0; j < allSets[i].numValues; ++j) {
            if (value == allSets[i].values[j]) {
                return &allSets[i];
            }
        }
    }
}

set *unionSets(set *setOne, set *setTwo) {
    set *s = (set*)malloc(sizeof(set));

    s->numValues = setOne->numValues + setTwo->numValues;
    s->values = (struct vertex**)calloc(s->numValues, sizeof(struct vertex*));
    s->id = setTwo->id;

    for (int i = 0; i < setOne->numValues; ++i) {
        s->values[i] = setOne->values[i];
    }

    for (int i = setOne->numValues; i < s->numValues; ++i) {
        s->values[i] = setTwo->values[i - setOne->numValues];
    }

    return s;
}