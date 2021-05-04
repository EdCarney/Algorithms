#include "queue.h"

#define MAX 500

queue *initializeQueue() {
    queue *Q = malloc(sizeof(queue));
    Q->vertexArray = (vertex*)calloc(MAX, sizeof(vertex));
    Q->front = 0;
    Q->rear = -1;
    Q->itemCount = 0;
    return Q;
}

vertex peek(queue *Q) {
   return Q->vertexArray[Q->front];
}

bool isEmpty(queue *Q) {
   return Q->itemCount == 0;
}

bool isFull(queue *Q) {
   return Q->itemCount == MAX;
}

int size(queue *Q) {
   return Q->itemCount;
}  

void enqueue(queue *Q, vertex data) {

   if(!isFull(Q)) {
	
      if(Q->rear == MAX-1) {
         Q->rear = -1;            
      }       

      Q->vertexArray[++(Q->rear)] = data;
      Q->itemCount++;
   }
}

vertex dequeue(queue *Q) {
   vertex data = Q->vertexArray[(Q->front)++];
	
   if(Q->front == MAX) {
      Q->front = 0;
   }
	
   (Q->itemCount)--;
   return data;  
}