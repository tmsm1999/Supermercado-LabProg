#ifndef QUEUE_H
#define QUEUE_H

#include "error.h"

typedef enum {FALSE, TRUE} BOOL;


typedef struct {
    int start;
    int end;
    int nMax;
    int currentSize;
    void **queue;
} *QUEUE;


// criar fila com capacidade para n inteiros
QUEUE queue_new(int n);
// colocar valor na fila
void queue_enqueue(QUEUE q, void* v);
// retirar valor da fila
void* queue_dequeue(QUEUE q);
// selecionar/retornar o valor do primeiro elemento na fila
void* queue_peek(QUEUE q);
// verificar se a fila está vazia
BOOL queue_is_empty(QUEUE q);
// verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE q);
// libertar fila
void queue_free(QUEUE q);
// retornar o tamanho atual da fila
int queue_size(QUEUE q);
// transformar a fila numa lista
void** queue_to_list(QUEUE q);
// comparar duas filas
BOOL queues_are_equal(QUEUE a, QUEUE b);
// imprimir uma representação textual da fila
void queue_print(QUEUE q);


#endif
