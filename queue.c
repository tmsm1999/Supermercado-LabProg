#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "cliente.h"


// funcao auxiliar (privada)
void queue_exit_error(char *msg) { 
   fprintf(stderr,"Error: %s\n",msg);
   exit(EXIT_FAILURE);
}

// criar fila com capacidade para n inteiros
QUEUE mk_empty_queue(int n) {

    QUEUE q = (QUEUE) malloc(sizeof(QUEUE));
    if (q == NULL)
        queue_exit_error("(mk_empty_queue) Out of memory.");

    q -> queue = (void **) malloc(sizeof(void*) * n);
    if (q -> queue == NULL) 
        queue_exit_error("(mk_empty_queue) Out of memory.");

    q -> nMax = n;
    q -> start = -1;
    q -> end = 0;
    q -> currentSize = 0;

    return q;
}

// libertar fila
void queue_free(QUEUE q) {
    if (q != NULL) {
        free(q -> queue);
        free(q);
    } 
    else 
        queue_exit_error("(queue_free) Queue not well constructed.");
}

// colocar valor na fila
void enqueue(QUEUE q, void* v) {
    if (q == NULL)
	queue_exit_error("(enqueue) Queue not well constructed.");
    
    if (q -> queue == NULL) 
        queue_exit_error("(enqueue) Queue not well constructed.");
    
    if (queue_is_full(q) == TRUE) 
        queue_exit_error("(enqueue) Queue is full.");

    if (queue_is_empty(q) == TRUE) {
        q -> start = q -> end; // fila fica com um elemento
    }
    
    q -> queue[q -> end] = v;
    q -> end = (q -> end + 1) % (q -> nMax);
    q -> currentSize++;
}

// retirar valor na fila
void* dequeue(QUEUE q) {
    if (q == NULL)
	queue_exit_error("(dequeue) Queue not well constructed.");

    if (q -> queue == NULL) 
        queue_exit_error("(dequeue) Queue not well constructed.");
    
    if (queue_is_empty(q) == TRUE) 
        queue_exit_error("(dequeue) Can't remove element. Queue is empty.");

    void* res = q -> queue[q -> start];
    q -> start = (q -> start + 1) % (q -> nMax);
    q -> currentSize--;
    
    if (q -> start == q -> end) { // se só tinha um elemento
        q -> start = -1; 
        q -> end = 0;
        q -> currentSize = 0;
    }

    return res;
}

// verificar se a fila está vazia
BOOL queue_is_empty(QUEUE q) {
    if (q == NULL) 
        queue_exit_error("(queue_is_empty) Queue not well constructed.");

    if (q -> start == -1) return TRUE;
        return FALSE;
}

// verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE q) { 
    if (q == NULL) 
        queue_exit_error("(queue_is_full) Queue not well constructed.");

    if (q -> end == q -> start) 
        return TRUE;
    
    return FALSE;
}

// selecionar/retornar o valor do primeiro elemento na fila
void* queue_peek(QUEUE q) {
    if (q == NULL)
        queue_exit_error("(queue_peek) Queue not well constructed.");

    else if (queue_is_empty(q))
        queue_exit_error("(queue_peek) Queue is empty. Can't retrieve value.");

    return q -> queue[q -> start];
}

// retornar o tamanho atual da fila
int queue_size(QUEUE q) {
    if (q == NULL)
        queue_exit_error("(queue_size) Queue not well constructed.");

    return q -> currentSize;
}

// transformar a fila numa lista
void** queue_to_list(QUEUE q) {
    if (q == NULL)
        queue_exit_error("(queue_to_list) Queue not well constructed.");
    
    else if (queue_is_empty(q))
        queue_exit_error("(queue_to_list) Queue is empty. Can't transform into list.");

    int s = queue_size(q);
    void **list = malloc(s * sizeof(void*));

    for (int i = 0; i < s; i++) {
        list[i] = dequeue(q);
        enqueue(q, list[i]);
    }

    return list;
}

// verificar se duas filas são iguais
BOOL queues_are_equal(QUEUE a, QUEUE b) {
    if (a == NULL || b == NULL)
        queue_exit_error("(queues_are_equal) Queue not well constructed.");

    if (queue_size(a) != queue_size(b))
        return FALSE;
    else {
        int s = queue_size(a);

        void **listA = queue_to_list(a);
        void **listB = queue_to_list(b);

	for (int i = 0; i < s; i++)
            if (listA[i] != listB[i])
                return FALSE;

        return TRUE;
    }
}

// imprimir uma representação textual da fila
void queue_print(QUEUE q) {
    printf("[");
    if (queue_size(q) > 0) {
	void ** list = queue_to_list(q);
	for (int i = 0; i < queue_size(q); i++) {
	    //for (int i = q->start; i != q->end; i = (i+1) % q->nMax) {
	    if (i > 0) printf(", ");
	    cliente_print(list[i]);
	}
    }
    printf("]");
}
