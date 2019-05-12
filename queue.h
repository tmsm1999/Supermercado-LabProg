#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} BOOL;


typedef struct fila {
	int start; 
	int end; 
	int nMax;
	int currentSize;
	int *queue;
} QUEUE;

// criar fila com capacidade para n inteiros
QUEUE *mk_empty_queue(int n);
// colocar valor na fila
void enqueue(int v, QUEUE *q);
// retirar valor da fila
int dequeue(QUEUE *q);
// verificar se a fila está vazia
BOOL queue_is_empty(QUEUE *q);
// verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE *q);
// libertar fila
void free_queue(QUEUE *q);
// selecionar/retornar o valor do primeiro elemento na fila
int peek_queue(QUEUE *q);
// retornar o tamanho atual da fila
int size(QUEUE *q);
// transformar a fila numa lista
int* queue_to_list(QUEUE *q);
// verificar se o argumento se trata de uma fila
BOOL is_queue(QUEUE *q);
// comparar duas filas
BOOL queues_are_equal(QUEUE *a, QUEUE *b);
