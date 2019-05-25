#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "queue.h"
#include "cliente.h"


// Criar uma nova fila de prioridade
PRIORITY_QUEUE priority_queue_new(int n, int numQueues) {
    PRIORITY_QUEUE pq = (PRIORITY_QUEUE) malloc(sizeof(n));
    pq->numQueues = numQueues;

    // Fila única
    pq->normal = queue_new(n);

    // Fila dupla
    if (numQueues == 2)
	pq->urgente = queue_new(n);
    
    return pq;
}


// Libertar a fila de prioridade e as estruturas a ela associadas da memória
void priority_queue_free(PRIORITY_QUEUE pq) {
    queue_free(pq->normal);
    if (pq->numQueues == 2) queue_free(pq->urgente);
    
    free(pq);
}


// Colocar o elemento mais prioritário da fila normal na fila urgente
void priority_queue_increase_priority(PRIORITY_QUEUE pq) {
   queue_enqueue(pq -> urgente, queue_dequeue(pq -> normal));
}


// Introduzir um elemento com uma certa prioridade na fila
void priority_queue_enqueue(PRIORITY_QUEUE pq, int priority, void* value) {
    // Fila simples
    if (pq->numQueues == 1)
	queue_enqueue(pq->normal, value);
    // Fila dupla
    else {    
	if (priority == 0)
	    queue_enqueue(pq -> normal, value);
	else
	    queue_enqueue(pq -> urgente, value);
    }
}


// Retirar o elemento mais prioritário
void* priority_queue_dequeue(PRIORITY_QUEUE pq) {
    // Fila simples
    if (pq->numQueues == 1) {
	if (queue_is_empty(pq->normal))
	    exit_error("Não foi possível remover o elemento; a fila está vazia.");

	return queue_dequeue(pq->normal);
    }
    // Fila dupla
    else {
	if (queue_is_empty(pq->normal) && queue_is_empty(pq->urgente))
	    exit_error("Não foi possível remover o elemento; a fila está vazia.");
	
	if (queue_is_empty(pq -> urgente) == FALSE)
	    return queue_dequeue(pq -> urgente);
	
	return queue_dequeue(pq -> normal);
    }
}


// Obter o elemento mais prioritário sem o remover
void* priority_queue_peek(PRIORITY_QUEUE pq) {
    // Fila simples
    if (pq->numQueues == 1) {
	if (queue_is_empty(pq->normal))
	    exit_error("Não foi possível obter o elemento; a fila está vazia.");

	return queue_peek(pq->normal);
    }
    // Fila dupla
    else {    
	if (queue_is_empty(pq->normal) && queue_is_empty(pq->urgente))
	    exit_error("Não foi possível obter o elemento; a fila está vazia.");
	
	if (queue_is_empty(pq -> urgente) == FALSE)
	    return queue_peek(pq -> urgente);
	
	return queue_peek(pq -> normal);
    }
}


// Obter o número de elementos da fila
int priority_queue_size(PRIORITY_QUEUE pq) {
    // Fila única
    if (pq->numQueues == 1)
	return queue_size(pq->normal);
    
    // Fila dupla
    return queue_size(pq -> normal) + queue_size(pq -> urgente);
}


// Verificar se a fila de prioridade está vazia
BOOL priority_queue_is_empty(PRIORITY_QUEUE pq) {
    return priority_queue_size(pq) == 0;
}


// Imprimir uma representação textual da fila de prioridade
void priority_queue_print(PRIORITY_QUEUE pq) {
    // Fila única
    printf("    Normal:  ");
    queue_print(pq->normal);

    // Fila dupla
    if (pq->numQueues == 2) {
	printf("\n    Urgente: ");
	queue_print(pq->urgente);
    }
}
