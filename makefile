CC = gcc
CFLAGS = -Wall
DEPS = error.h queue.h priority_queue.h cliente.h caixa.h supermercado.h

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@

supermercado: error.c queue.c priority_queue.c cliente.c caixa.c supermercado.c
	$(CC) $(CFLAGS) error.c queue.c priority_queue.c cliente.c caixa.c supermercado.c -o supermercado
