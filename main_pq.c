#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main() {

	PRIORITY_QUEUE pq = mk_priority_queue(MAX_CLIENTES);

	int a = 1, b = 2;

	enqueue_priority_queue(pq, 0, &a);
	enqueue_priority_queue(pq, 0, &b);
	enqueue_priority_queue(pq, 1, &a);

	printf("Size = %d\n", size_priority_queue(pq));

	dequeue_priority_queue(pq);
	printf("Size = %d\n", size_priority_queue(pq));

	//peek_priority_queue(pq);

	enqueue_priority_queue(pq, 1, &a);
	printf("Size = %d\n", size_priority_queue(pq));

	peek_priority_queue(pq);

	//printf("Fila está vazia = %d\n", priority_queue_is_empty(pq));
	//printf("Fila está cheia = %d\n", priority_queue_is_full(pq));

	dequeue_priority_queue(pq);
	//dequeue_priority_queue(pq);
	//dequeue_priority_queue(pq);
	printf("Size = %d\n", size_priority_queue(pq));


	enqueue_priority_queue(pq, 0, &a);
	peek_priority_queue(pq);
	
	increase_priority(pq);
	peek_priority_queue(pq);

	dequeue_priority_queue(pq);
	printf("Size = %d\n", size_priority_queue(pq));

	return 0;
}
