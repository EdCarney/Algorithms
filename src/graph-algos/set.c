#include "set.h"

struct set {
    struct vertex **values;
    int numValues;
};

struct set *makeSet(struct vertex *value) {
    struct set *set = (struct set*)malloc(sizeof(struct set));
    set->values = (struct vertex**)calloc(1, sizeof(struct vertex*));
    set->values[0] = value;
    set->numValues = 1;
    return set;
}

struct set *findSet(struct vertex *value, struct set *allSets, int numSets) {
    for (int i = 0; i < numSets; ++i) {
        for (int j = 0; j < allSets[i].numValues; ++j) {
            if (value == allSets[i].values[j]) {
                return &allSets[i];
            }
        }
    }
}

struct set *unionSets(struct set *setOne, struct set *setTwo) {
    struct set *set = (struct set*)malloc(sizeof(struct set));
    set->numValues = setOne->numValues + setTwo->numValues;
    set->values = (struct vertex**)calloc(set->numValues, sizeof(struct vertex*));

    for (int i = 0; i < setOne->numValues; ++i) {
        set->values[i] = setOne->values[i];
    }

    for (int i = setOne->numValues; i < set->numValues; ++i) {
        set->values[i] = setTwo->values[i - setOne->numValues];
    }

    return set;
}