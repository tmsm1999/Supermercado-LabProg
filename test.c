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
    printf("queue size: %d\n", queue_size(cx->fila));
    //enqueue((void*) c, caixa_fila(cx));
    printf("queue size: %d\n", queue_size(cx->fila));
    //enqueue((void*) cliente_novo(3, 5), cx->fila);
    caixa_print(cx); printf("\n");
}
