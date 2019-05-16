#include "cliente.h"
#include "caixa.h"


int main() {
    // Cliente
    CLIENTE c = cliente_novo(3, 3);
    printf("nCompras: %d\n", cliente_nCompras(c));
    printf("tEntrada: %d\n", cliente_tEntrada(c));
    printf("cliente: "); cliente_print(c); printf("\n");


    // Caixa
    CAIXA cx = caixa_nova(5);
    printf("queue size: %d\n", priority_queue_size(cx->fila));
    priority_queue_enqueue(caixa_fila(cx), 0, (void*) c);
    printf("queue size: %d\n", priority_queue_size(cx->fila));
    priority_queue_enqueue(cx->fila, 1, (void*) cliente_novo(3, 5));
    caixa_print(cx); printf("\n");
}
