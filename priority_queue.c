#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "queue.h"
#include "cliente.h"


PRIORITY_QUEUE priority_queue_new(int n) {
    PRIORITY_QUEUE pq = (PRIORITY_QUEUE) malloc(sizeof(n));     
    pq -> normal = queue_new(n);
    pq -> urgente = queue_new(n);
    
    return pq;
}


void priority_queue_increase_priority(PRIORITY_QUEUE pq) {
   queue_enqueue(pq -> urgente, queue_dequeue(pq -> normal));
}


void priority_queue_enqueue(PRIORITY_QUEUE pq, int priority, void* value) {
    if (priority == 0) {
	//printf("Entrou na fila normal.\n");
	queue_enqueue(pq -> normal, value);
    }
    else {
	//printf("Entrou na fila urgente.\n");
	queue_enqueue(pq -> urgente, value);
    }
}


void* priority_queue_dequeue(PRIORITY_QUEUE pq) {
    if (queue_is_empty(pq->normal) && queue_is_empty(pq->urgente))
	exit_error("Não foi possível remover o elemento; a fila está vazia.");
    
    if (queue_is_empty(pq -> urgente) == FALSE) {
	//printf("Saiu da fila urgente.\n");
	return queue_dequeue(pq -> urgente);
    }
    
    //printf("Saiu da fila normal.\n");
    return queue_dequeue(pq -> normal);
}


void* priority_queue_peek(PRIORITY_QUEUE pq) {
    if (queue_is_empty(pq->normal) && queue_is_empty(pq->urgente))
	exit_error("Não foi possível obter o elemento; a fila está vazia.");
    
    if (queue_is_empty(pq -> urgente) == FALSE)
	return queue_peek(pq -> urgente);
    
    return queue_peek(pq -> normal);
}


int priority_queue_size(PRIORITY_QUEUE pq) {
    return queue_size(pq -> normal) + queue_size(pq -> urgente);
}


BOOL priority_queue_is_empty(PRIORITY_QUEUE pq) {
    return priority_queue_size(pq) == 0;
}

/*BOOL priority_queue_is_full(PRIORITY_QUEUE *pq, int nFila) {
  if (nFila == 0) return queue_is_full(pq->normal) ? TRUE : FALSE;
  return queue_is_full(pq->urgente) ? TRUE : FALSE;
  }*/


// imprimir uma representação textual da fila
void priority_queue_print(PRIORITY_QUEUE q) {
    printf("    Normal:  ");
    queue_print(q->normal);
    printf("\n    Urgente: ");
    queue_print(q->urgente);
}
