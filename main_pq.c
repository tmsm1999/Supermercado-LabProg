#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main() {

	PRIORITY_QUEUE *pq = mk_priority_queue(100);

	enqueue_priority_queue(pq, 0, 1);
	enqueue_priority_queue(pq, 0, 2);
	enqueue_priority_queue(pq, 1, 1);

	printf("Size = %d\n", size_priority_queue(pq));

	dequeue_priority_queue(pq);
	printf("Size = %d\n", size_priority_queue(pq));

	peek_priority_queue(pq);

	enqueue_priority_queue(pq, 1, 1);
	printf("Size = %d\n", size_priority_queue(pq));

	peek_priority_queue(pq);

	printf("Fila está vazia = %d\n", priority_queue_is_empty(pq));
	printf("Fila está cheia = %d\n", priority_queue_is_full(pq));

	dequeue_priority_queue(pq);
	dequeue_priority_queue(pq);
	dequeue_priority_queue(pq);
	printf("Size = %d\n", size_priority_queue(pq));


	enqueue_priority_queue(pq, 0, 1);
	peek_priority_queue(pq);
	
	increase_priority(pq);
	peek_priority_queue(pq);

	dequeue_priority_queue(pq);
	printf("Size = %d\n", size_priority_queue(pq));

	return 0;
}