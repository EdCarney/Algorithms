#include "mst-kruskal.h"

edge *mstKruskal(graph *G, int *numTreeEdges) {
    set *allSets, *foundSet1, *foundSet2;
    int numSets = G->numVertices, numMstEdges = 0;
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
            A = addEdgeToArray(A, &numMstEdges, H->values[i]);
            
            // merge the trees
            allSets = mergeSets(foundSet1, foundSet2, allSets, &numSets);
        }
    }

    *numTreeEdges = numMstEdges;
    return A;
}

edge *mstKruskalWithRoot(graph *G, int *numTreeEdges, int sourceId) {
    edge *A = mstKruskal(G, numTreeEdges);
    int vertexNum, numConnectingEdges;
    vertex currentVertex, *tempVertex;
    queue *Q = initializeQueue();

    // get the source vertex and add to queue
    for (int i = 0; i < G->numVertices; ++i)
        if (G->vertices[i].id == sourceId)
            enqueue(Q, G->vertices[i]);

    while (!isEmpty(Q)) {
        currentVertex = dequeue(Q);
        for (int i = 0; i < *numTreeEdges; ++i) {
            if (A[i].from->id == currentVertex.id && A[i].to->parent == NULL && A[i].to->id != sourceId) {
                A[i].to->parent = A[i].from;
                enqueue(Q, *A[i].to);
            }
            else if (A[i].to->id == currentVertex.id && A[i].from->parent == NULL && A[i].from->id != sourceId) {
                tempVertex = A[i].to;
                A[i].to = A[i].from;
                A[i].from = tempVertex;
                A[i].to->parent = A[i].from;
                enqueue(Q, *A[i].to);
            }
        }
    }

    return A;
    // create a queue of vertices to process
    // for each vertex in the queue
    // go through and find any edges containing the vertex
    // if the vertex's parent is NULL
        // set the parent of the other vertex to the vertex you are considering
        // add the updated vertex to your queue
}

edge *addEdgeToArray(edge *A, int *numMstEdges, edge edgeToAdd) {
    (*numMstEdges)++;
    edge *tempA = calloc(*numMstEdges, sizeof(edge));

    for (int i = 0; i < *numMstEdges - 1; ++i)
        tempA[i] = A[i];

    tempA[*numMstEdges - 1] = edgeToAdd;
    free(A);
    return tempA;
}

set *mergeSets(set *set1, set *set2, set *allSets, int *numSets) {
    set *tempSet = unionSets(set1, set2);
    set *tempSets = calloc(*numSets - 1, sizeof(set));
    int setCount = 0;

    for (int i = 0; i < *numSets; ++i)
        if (allSets[i].id != set1->id && allSets[i].id != set2->id)
            tempSets[setCount++] = allSets[i];

    tempSets[setCount++] = *tempSet;
    *numSets = setCount;
    return tempSets;
}