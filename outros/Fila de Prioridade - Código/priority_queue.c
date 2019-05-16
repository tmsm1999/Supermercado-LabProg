#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "queue.h"

PRIORITY_QUEUE *mk_priority_queue(int s) {

	PRIORITY_QUEUE *pq = (PRIORITY_QUEUE*) malloc(sizeof(PRIORITY_QUEUE)); 
	
	pq -> normal = mk_empty_queue(s);
	pq -> urgente = mk_empty_queue(s);
	
	pq -> normal -> nMax = s/2;
	pq -> urgente -> nMax = s/2;

	pq -> size = s;

	return pq;
}

void increase_priority(PRIORITY_QUEUE *pq) {
	enqueue(dequeue(pq -> normal), pq -> urgente);
	printf("A prioridade aumentou.\n");
}

void enqueue_priority_queue(PRIORITY_QUEUE *pq, int priority, int value) {

	if(priority == 0) {
		printf("Entrou na fila normal.\n");
		enqueue(value, pq -> normal);
	}
	else if(priority == 1) {
		printf("Entrou na fila urgente.\n");
		enqueue(value, pq -> urgente);
	}
}

void dequeue_priority_queue(PRIORITY_QUEUE *pq) {
	if(queue_is_empty(pq -> urgente) == FALSE) {
		dequeue(pq -> urgente);
		printf("Saiu da fila urgente.\n");
		return;
	}
	else if(queue_is_empty(pq -> normal) == FALSE) {
		dequeue(pq -> normal);
		printf("Saiu da fila normal.\n");
		return;
	}

	queue_exit_error("Can't remove element. Queue is empty.");
}

int size_priority_queue(PRIORITY_QUEUE *pq) {
	return size(pq -> normal) + size(pq -> urgente);
}

BOOL priority_queue_is_empty(PRIORITY_QUEUE *pq) {
	if(queue_is_empty(pq -> normal) && queue_is_empty(pq -> urgente)) {
		return TRUE;
	}
	return FALSE;
}

BOOL priority_queue_is_full(PRIORITY_QUEUE *pq) {
	if(size(pq -> normal) + size(pq -> urgente) < pq -> size) {
		return FALSE;
	} 
	return TRUE;
}

int peek_priority_queue(PRIORITY_QUEUE *pq) {
	if(priority_queue_is_empty(pq) == TRUE)
        queue_exit_error("Queue is empty. Can't retrieve value.");

	if(queue_is_empty(pq -> urgente) == FALSE) {
		printf("Próximo sairá da fila urgente.\n");
		return peek_queue(pq -> urgente);
	}
	
	printf("Próximo sairá da fila nornal.\n");
	return peek_queue(pq -> normal);
}










