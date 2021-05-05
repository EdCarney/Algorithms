#include "shortest-path-dijkstra.h"

void initSingleSource(graph *G, vertex *source) {
    int inf = 2147483647;
    for (int i = 0; i < G->numVertices; ++i) {
        G->vertices[i].key = inf;
        G->vertices[i].parent = NULL;
    }
    source->key = 0;
}

set *shortestPathDijkstra(graph *G, vertex *source) {
    initSingleSource(G, source);
    set *S = initializeSet(), *u;
    vertexHeap *heap = initializeHeapFromVertices(G);
    adjNode *v;

    while (heap->length > 0) {
        u = extractVertexHeapMin(heap);
        S = unionSets(S, u);
        v = G->adjacent[u->values[0]->id - 1];
        while (v != NULL) {
            if (vertexIdInHeap(heap, v->vertexNumber))
                relax(S->values[S->numValues - 1], getHeapVertexById(heap, v->vertexNumber), v->weight);
            else
                relax(S->values[S->numValues - 1], getSetVertexById(S, v->vertexNumber), v->weight);
            v = v->next;
        }
    }
    return S;
}

set *extractVertexHeapMin(vertexHeap *heap) {

    buildMinVertexHeap(heap);
    set *u = malloc(sizeof(set));
    makeSet(&heap->values[0], u);

    // reduce heap value length
    --(heap->length);
    ++(heap->values);
    return u;
}

void relax(vertex *u, vertex *v, int weight) {
    if (v->key > u->key + weight) {
        v->key = u->key + weight;
        v->parent = u;
    }
}
