#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {

    QUEUE a = mk_empty_queue(3);
    printf("size = %d\n", size(a));
    printf("queue is empty = %d\n", queue_is_empty(a));
    printf("queue is full  = %d\n", queue_is_full(a));
    printf("\n");

    enqueue(a, 1);
    printf("size = %d\n", size(a));
    printf("queue is empty = %d\n", queue_is_empty(a));
    printf("queue is full  = %d\n", queue_is_full(a));
    printf("\n");

    enqueue(a, 2);
    printf("size = %d\n", size(a));
    printf("queue is empty = %d\n", queue_is_empty(a));
    printf("queue is full  = %d\n", queue_is_full(a));
    printf("\n");

    enqueue(a, 3);
    printf("size = %d\n", size(a));
    printf("queue is empty = %d\n", queue_is_empty(a));
    printf("queue is full  = %d\n", queue_is_full(a));
    printf("\n");
    
    QUEUE b = mk_empty_queue(3);
    printf("queues are equal: %d\n", queues_are_equal(a, b));
    enqueue(b, 1);
    printf("queues are equal: %d\n", queues_are_equal(a, b));
    enqueue(b, 2);
    printf("queues are equal: %d\n", queues_are_equal(a, b));
    enqueue(b, 3);
    printf("queues are equal: %d\n", queues_are_equal(a, b));

    printf("peek queue: %d\n", peek_queue(a));
    int *list = queue_to_list(a);
    printf("a = [");
    for (int i = 0; i < size(a); i++) {
	if (i > 0) printf(", ");
	printf("%d", list[i]);
    }
    printf("]\n");

    printf("queues are equal: %d\n", queues_are_equal(a, b));
    free_queue(a);
    a = NULL;
    
    printf("queues are equal: %d\n", queues_are_equal(a, b));

    

    

    /*QUEUE *f = mk_empty_queue(3);
	printf("%d\n", is_queue(5));

	QUEUE *a = mk_empty_queue(6);
	enqueue(1, a);
	enqueue(2, a);
	enqueue(3, a);
	enqueue(4, a);

	QUEUE *b = mk_empty_queue(6);
	enqueue(1, b);
	enqueue(2, b);
	enqueue(3, b);

	printf("%d\n", queues_are_equal(a, b));

	return 0;






	QUEUE *q = mk_empty_queue(5);
	//printf("%d\n", peek_queue(q));
	enqueue(5, q);
	printf("Peek: %d\n", peek_queue(q));
	printf("Tamanho atual: %d\n", size(q));
	enqueue(2, q);
	printf("Peek: %d\n", peek_queue(q));
	printf("Tamanho atual: %d\n", size(q));
	enqueue(4, q);

	int *l = queue_to_list(q);
	for(int i = 0; i < size(q); i++) {
		printf("%d ", l[i]);
	}
	printf("\n");

	printf("Peek: %d\n", peek_queue(q));
	printf("Tamanho atual: %d\n", size(q));
	dequeue(q);
	printf("Peek: %d\n", peek_queue(q));
	printf("Tamanho atual: %d\n", size(q));
	dequeue(q);
	printf("Peek: %d\n", peek_queue(q));
	printf("Tamanho atual: %d\n", size(q));
	dequeue(q);
	printf("Tamanho atual: %d\n", size(q));
	printf("Peek: %d\n", peek_queue(q));
	printf("Tamanho atual: %d\n", size(q));








	return 0;*/
}
