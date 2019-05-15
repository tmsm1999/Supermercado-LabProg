#ifndef PRIORITYQUEUEHEADER
#define PRIORITYQUEUEHEADER

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Número máximo de clientes por fila
#define MAX_CLIENTES 1000


typedef struct {
	QUEUE normal;
	QUEUE urgente;
	int size;
} *PRIORITY_QUEUE;

PRIORITY_QUEUE mk_priority_queue(int n);
void increase_priority(PRIORITY_QUEUE pq);
void priority_queue_enqueue(PRIORITY_QUEUE pq, int priority, void* value);
void* priority_queue_dequeue(PRIORITY_QUEUE pq);
int priority_queue_size(PRIORITY_QUEUE pq);
BOOL priority_queue_is_empty(PRIORITY_QUEUE pq);
//BOOL priority_queue_is_full(PRIORITY_QUEUE pq);
void* peek_priority_queue(PRIORITY_QUEUE pq);
void priority_queue_print(PRIORITY_QUEUE q);

#endif
