#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "error.h"

// Número máximo de clientes por fila
#define MAX_CLIENTES 1000


// Estrutura fila de prioridade
typedef struct priorityqueue {
    QUEUE normal;
    QUEUE urgente;
    int size;
    int numQueues;
} *PRIORITY_QUEUE;


// Criar uma nova fila de prioridade
PRIORITY_QUEUE priority_queue_new(int n, int numQueues);

// Libertar a fila de prioridade e as estruturas a ela associadas da memória
void priority_queue_free(PRIORITY_QUEUE pq);

// Colocar o elemento mais prioritário da fila normal na fila urgente
void priority_queue_increase_priority(PRIORITY_QUEUE pq);

// Introduzir um elemento com uma certa prioridade na fila
void priority_queue_enqueue(PRIORITY_QUEUE pq, int priority, void* value);

// Retirar o elemento mais prioritário
void* priority_queue_dequeue(PRIORITY_QUEUE pq);

// Obter o elemento mais prioritário sem o remover
void* priority_queue_peek(PRIORITY_QUEUE pq);

// Obter o número de elementos da fila
int priority_queue_size(PRIORITY_QUEUE pq);

// Verificar se a fila de prioridade está vazia
BOOL priority_queue_is_empty(PRIORITY_QUEUE pq);

// Imprimir uma representação textual da fila de prioridade
void priority_queue_print(PRIORITY_QUEUE pq);

#endif
