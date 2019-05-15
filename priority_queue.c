#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "queue.h"
#include "cliente.h"


PRIORITY_QUEUE mk_priority_queue(int n) {

	PRIORITY_QUEUE pq = (PRIORITY_QUEUE) malloc(sizeof(n)); 
	
	pq -> normal = mk_empty_queue(n);
	pq -> urgente = mk_empty_queue(n);
	
	return pq;
}

void increase_priority(PRIORITY_QUEUE pq) {
    enqueue(pq -> urgente, dequeue(pq -> normal));
    printf("A prioridade aumentou.\n");
}

void priority_queue_enqueue(PRIORITY_QUEUE pq, int priority, void* value) {

	if(priority == 0) {
		printf("Entrou na fila normal.\n");
		enqueue(pq -> normal, value);
	}
	else {
		printf("Entrou na fila urgente.\n");
		enqueue(pq -> urgente, value);
	}
}

void* priority_queue_dequeue(PRIORITY_QUEUE pq) {
    if (queue_is_empty(pq->normal) && queue_is_empty(pq->urgente))
	queue_exit_error("Can't remove element. Queue is empty.");
    
    if(queue_is_empty(pq -> urgente) == FALSE) {
	printf("Saiu da fila urgente.\n");
	return dequeue(pq -> urgente);
    }

    printf("Saiu da fila normal.\n");
    return dequeue(pq -> normal);
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

void* peek_priority_queue(PRIORITY_QUEUE pq) {
    if (queue_is_empty(pq->normal) && queue_is_empty(pq->urgente))
	queue_exit_error("Can't remove element. Queue is empty.");
    
    if(queue_is_empty(pq -> urgente) == FALSE) {
	printf("Próximo sairá da fila urgente.\n");
	return queue_peek(pq -> urgente);
    }
    
    printf("Próximo sairá da fila nornal.\n");
    return queue_peek(pq -> normal);
}


// imprimir uma representação textual da fila
void priority_queue_print(PRIORITY_QUEUE q) {
    printf("{");
    printf("[");
    void ** list;
    if (queue_size(q->normal) > 0) {
	list = queue_to_list(q->normal);
	for (int i = 0; i < queue_size(q->normal); i++) {
	    //for (int i = q->start; i != q->end; i = (i+1) % q->nMax) {
	    if (i > 0) printf(", ");
	    cliente_print(list[i]);
	}
    }
    printf("]");

    if (queue_size(q->urgente) > 0) {
	list = queue_to_list(q->urgente);
	for (int i = 0; i < queue_size(q->urgente); i++) {
	    //for (int i = q->start; i != q->end; i = (i+1) % q->nMax) {
	    if (i > 0) printf(", ");
	    cliente_print(list[i]);
	}
    }
    printf("]");
    
    printf("}");
}
