#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

typedef struct queue {
    vertex *vertexArray;
    int front;
    int rear;
    int itemCount;
} queue;

queue *initializeQueue();

queue *initializeQueueFromGraph(graph *G);

vertex peek(queue *Q);

bool isEmpty(queue *Q);

bool isFull(queue *Q);

int size(queue *Q);

void enqueue(queue *Q, vertex data);

vertex dequeue(queue *Q);

#endif /* QUEUE_H */