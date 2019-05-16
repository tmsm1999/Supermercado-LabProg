#ifndef PRIORITYQUEUEHEADER
#define PRIORITYQUEUEHEADER

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct fila_prioridade {
	QUEUE *normal;
	QUEUE *urgente;
	int size;
} PRIORITY_QUEUE;

PRIORITY_QUEUE *mk_priority_queue(int s);
void increase_priority(PRIORITY_QUEUE *pq);
void enqueue_priority_queue(PRIORITY_QUEUE *pq, int priority, int value);
void dequeue_priority_queue(PRIORITY_QUEUE *pq);
int size_priority_queue(PRIORITY_QUEUE *pq);
BOOL priority_queue_is_empty(PRIORITY_QUEUE *pq);
BOOL priority_queue_is_full(PRIORITY_QUEUE *pq);
int peek_priority_queue(PRIORITY_QUEUE *pq);

#endif