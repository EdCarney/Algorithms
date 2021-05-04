#include "mst-kruskal.h"

edge *mstKruskal(graph *G, int *numTreeEdges) {
    set *allSets, *foundSet1, *foundSet2, *tempSet, *tempSets;
    int numSets = G->numVertices, setCount = 0, numMstEdges = 0;
    edge *A = (edge*)calloc(1, sizeof(edge));

    allSets = (set*)calloc(G->numVertices, sizeof(set));
    for (int i = 0; i < G->numVertices; ++i)
        makeSet(&G->vertices[i], &allSets[i]);

    heap *H = initializeHeapFromEdges(G);
    maxHeapSort(H);

    for (int i = 0; i < H->length; ++i) {
        foundSet1 = findSet(H->values[i].from, allSets, numSets);
        foundSet2 = findSet(H->values[i].to, allSets, numSets);

        if (foundSet1 != foundSet2) {
            // add the edge to A
            A = addEdgeToArray(A, &numMstEdges, &(H->values[i]));
            
            // merge the trees
            tempSet = unionSets(foundSet1, foundSet2);
            tempSets = calloc(numSets - 1, sizeof(set));
            setCount = 0;
            for (int i = 0; i < numSets; ++i) {
                if (allSets[i].id != foundSet1->id &&
                    allSets[i].id != foundSet2->id) {
                        tempSets[setCount++] = allSets[i];
                }
            }
            tempSets[setCount++] = *tempSet;
            allSets = tempSets;
            numSets = setCount;
        }
    }

    *numTreeEdges = numMstEdges;
    return A;
}

edge *addEdgeToArray(edge *A, int *numMstEdges, edge *edgeToAdd) {
    (*numMstEdges)++;
    edge *tempA = calloc(*numMstEdges, sizeof(edge));
    for (int i = 0; i < *numMstEdges - 1; ++i) {
        tempA[i] = A[i];
    }
    tempA[*numMstEdges - 1] = *edgeToAdd;
    free(A);
    return tempA;
}

set *mergeSets(set *set1, set *set2, set *allSets, int *numSet) {
    
}