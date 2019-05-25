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


// Criar fila com capacidade para n elementos
QUEUE queue_new(int n);

// Libertar fila da memória
void queue_free(QUEUE q);

// Colocar elemento na fila
void queue_enqueue(QUEUE q, void* v);

// Retirar elemento mais antigo da fila
void* queue_dequeue(QUEUE q);

// Selecionar/retornar o valor do primeiro elemento na fila
void* queue_peek(QUEUE q);

// Verificar se a fila está vazia
BOOL queue_is_empty(QUEUE q);

// Verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE q);

// Retornar o tamanho atual da fila
int queue_size(QUEUE q);

// Transformar a fila numa lista
void** queue_to_list(QUEUE q);

// Verificar se duas filas são iguais
BOOL queues_are_equal(QUEUE a, QUEUE b);

// Imprimir uma representação textual da fila
void queue_print(QUEUE q);


#endif
