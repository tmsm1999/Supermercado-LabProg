#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} BOOL;


typedef struct {
	int start; 
	int end; 
	int nMax;
	int currentSize;
	void **queue;
} *QUEUE;

// criar fila com capacidade para n inteiros
QUEUE mk_empty_queue(int n);
// colocar valor na fila
void enqueue(void* v, QUEUE q);
// retirar valor da fila
void* dequeue(QUEUE q);
// verificar se a fila está vazia
BOOL queue_is_empty(QUEUE q);
// verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE q);
// libertar fila
void queue_free(QUEUE q);
// selecionar/retornar o valor do primeiro elemento na fila
void* queue_peek(QUEUE q);
// retornar o tamanho atual da fila
int queue_size(QUEUE q);
// transformar a fila numa lista
void** queue_to_list(QUEUE q);
// comparar duas filas
BOOL queues_are_equal(QUEUE a, QUEUE b);
// imprimir uma representação textual da fila
void queue_print(QUEUE q);


#endif
