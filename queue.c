#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "cliente.h"


// criar fila com capacidade para n inteiros
QUEUE queue_new(int n) {
    QUEUE q = (QUEUE) malloc(sizeof(QUEUE));
    if (q == NULL)
        exit_error("(mk_empty_queue) Sem memória.");

    q -> queue = (void **) malloc(sizeof(void*) * n);
    if (q -> queue == NULL) 
        exit_error("(mk_empty_queue) Sem memória.");

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
        exit_error("(queue_free) Fila mal construída.");
}


// colocar valor na fila
void queue_enqueue(QUEUE q, void* v) {
    if (q == NULL)
	exit_error("(enqueue) Fila mal construída.");
    
    if (q -> queue == NULL) 
        exit_error("(enqueue) Fila mal construída.");
    
    if (queue_is_full(q) == TRUE) 
        exit_error("(enqueue) A fila está cheia.");

    if (queue_is_empty(q) == TRUE) {
        q -> start = q -> end; // fila fica com um elemento
    }
    
    q -> queue[q -> end] = v;
    q -> end = (q -> end + 1) % (q -> nMax);
    q -> currentSize++;
}


// retirar valor na fila
void* queue_dequeue(QUEUE q) {
    if (q == NULL)
	exit_error("(dequeue) Fila mal construída.");

    if (q -> queue == NULL) 
        exit_error("(dequeue) Fila mal construída.");
    
    if (queue_is_empty(q) == TRUE) 
        exit_error("(dequeue) Não foi possível remover o elemento; a fila está vazia.");

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


// selecionar/retornar o valor do primeiro elemento na fila
void* queue_peek(QUEUE q) {
    if (q == NULL)
        exit_error("(queue_peek) Fila mal construída.");

    else if (queue_is_empty(q))
        exit_error("(queue_peek) Não foi possível obter o elemento; a fila está vazia.");

    return q -> queue[q -> start];
}


// verificar se a fila está vazia
BOOL queue_is_empty(QUEUE q) {
    if (q == NULL) 
        exit_error("(queue_is_empty) Fila mal construída.");

    if (q -> start == -1) return TRUE;
        return FALSE;
}


// verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE q) { 
    if (q == NULL) 
        exit_error("(queue_is_full) Fila mal construída.");

    if (q -> end == q -> start) 
        return TRUE;
    
    return FALSE;
}


// retornar o tamanho atual da fila
int queue_size(QUEUE q) {
    if (q == NULL)
        exit_error("(queue_size) Fila mal construída.");

    return q -> currentSize;
}


// transformar a fila numa lista
void** queue_to_list(QUEUE q) {
    if (q == NULL)
        exit_error("(queue_to_list) Fila mal construída.");
    
    else if (queue_is_empty(q))
        exit_error("(queue_to_list) Não foi possível transformar a fila numa lista; a fila está vazia.");

    int s = queue_size(q);
    void **list = malloc(s * sizeof(void*));

    for (int i = 0; i < s; i++) {
        list[i] = queue_dequeue(q);
        queue_enqueue(q, list[i]);
    }

    return list;
}


// verificar se duas filas são iguais
BOOL queues_are_equal(QUEUE a, QUEUE b) {
    if (a == NULL || b == NULL)
        exit_error("(queues_are_equal) Fila mal construída.");

    if (queue_size(a) == 0 && queue_size(b) == 0) return TRUE;
    
    if (queue_size(a) != queue_size(b)) return FALSE;
    
        //int s = queue_size(a);

        /*void **listA = queue_to_list(a);
        void **listB = queue_to_list(b);

	for (int i = 0; i < s; i++)
            if (listA[i] != listB[i])
                return FALSE;

		return TRUE;*/

    for (int i = a->start, j = b->start; i != a->end; i = (i+1) % a->nMax, j = (j+1) % b->nMax)
	if (a->queue[i] != b->queue[j]) return FALSE;
    
    return TRUE;
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
