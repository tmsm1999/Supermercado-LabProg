#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
<<<<<<< HEAD
// funcao auxiliar (privada)

static void queue_exit_error(char *msg);
=======

>>>>>>> c57cceb998b836a7de544dc1482ceb07e0a168ae

// funcao auxiliar (privada)
static void queue_exit_error(char *msg) { 
   fprintf(stderr,"Error: %s\n",msg);
   exit(EXIT_FAILURE);
}

// criar fila com capacidade para n inteiros
QUEUE *mk_empty_queue(int n) {

    QUEUE *q = (QUEUE *) malloc(sizeof(QUEUE));
    if (q == NULL) 
        queue_exit_error("Out of memory.");

    q -> queue = (int *) malloc(sizeof(int) * n);
    if (q -> queue == NULL) 
        queue_exit_error("Out of memory.");

    q -> nMax = n;
    q -> start = -1;
    q -> end = 0;
    q -> currentSize = 0;

    return q;
}

// libertar fila
void free_queue(QUEUE *q) {
    if (q != NULL) {
        free(q -> queue);
        free(q);
    } 
    else 
        queue_exit_error("Queue not well constructed.");
}

// colocar valor na fila
void enqueue(int v, QUEUE *q) {
    if (q == NULL)
	queue_exit_error("Queue not well constructed.");
    
    if (q -> queue == NULL) 
        queue_exit_error("Queue not well constructed.");
    
    if (queue_is_full(q) == TRUE) 
        queue_exit_error("Queue is full.");

    if (queue_is_empty(q) == TRUE) {
        q -> start = q -> end; // fila fica com um elemento
    }
    
    q -> queue[q -> end] = v;
    q -> end = (q -> end + 1) % (q -> nMax);
    q -> currentSize++;
}

// retirar valor na fila
int dequeue(QUEUE *q) {
    if (q == NULL)
	queue_exit_error("Queue not well constructed.");

    if (q -> queue == NULL) 
        queue_exit_error("Queue not well constructed.");
    
    if (queue_is_empty(q) == TRUE) 
        queue_exit_error("Can't remove element. Queue is empty.");

    int aux = q -> queue[q -> start];
    q -> start = (q -> start + 1) % (q -> nMax);
    q -> currentSize--;
    
    if (q -> start == q -> end) { // se só tinha um elemento
        q -> start = -1; 
        q -> end = 0;
        q -> currentSize = 0;
    }

    return aux;
}

// verificar se a fila está vazia
BOOL queue_is_empty(QUEUE *q) {
    if (q == NULL) 
        queue_exit_error("Queue not well constructed.");

    if (q -> start == -1) return TRUE;
        return FALSE;
}

// verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE *q) { 
    if (q == NULL) 
        queue_exit_error("Queue not well constructed.");

    if (q -> end == q -> start) 
        return TRUE;
    
    return FALSE;
}

// selecionar/retornar o valor do primeiro elemento na fila
int peek_queue(QUEUE *q) {
    if (q == NULL)
        queue_exit_error("Queue not well constructed.");

    else if (queue_is_empty(q))
        queue_exit_error("Queue is empty. Can't retrieve value.");

    return q -> queue[q -> start];
}

// retornar o tamanho atual da fila
int size(QUEUE *q) {
    if (q == NULL)
        queue_exit_error("Queue not well constructed.");

    return q -> currentSize;
}

// transformar a fila numa lista
int* queue_to_list(QUEUE *q) {
    if (q == NULL)
        queue_exit_error("Queue not well constructed.");
    
    else if (queue_is_empty(q))
        queue_exit_error("Queue is empty. Can't transform into list.");

    int s = size(q);
    int *list = malloc(s * sizeof(int));

    for (int i = 0; i < s; i++) {
        list[i] = dequeue(q);
        enqueue(list[i], q);
    }

    return list;
}

// verificar se o argumento se trata de uma fila. 
// ESTA FUNÇÃO NÃO ESTÁ CORRETA.
BOOL is_queue(QUEUE *q) {
    if (q == NULL) {
        return FALSE;
    }
    
    return TRUE;
}

// verificar se duas filas são iguais
BOOL queues_are_equal(QUEUE *a, QUEUE *b) {
    if (a == NULL || b == NULL) {
        queue_exit_error("Queue not well constructed.");
    }

    if (size(a) != size(b)) {
        return FALSE;
    }
    else {
        int s = size(a);

        int *listA = queue_to_list(a);
        int *listB = queue_to_list(b);

	for (int i = 0; i < s; i++) {
            if (listA[i] != listB[i]) {
                return FALSE;
            }
        }

        return TRUE;
    }
}

































