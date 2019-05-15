#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>


// Devolve um cliente com n items a comprar que foi para as caixas no instante t
CLIENTE cliente_novo(int nCompras, int tEntrada) {
    CLIENTE c = malloc(sizeof(CLIENTE));
    c->nCompras = nCompras;
    c->tEntrada = tEntrada;

    return c;
}


// Devolve o número de artigos a comprar pelo cliente c
int cliente_nCompras(CLIENTE c) {
    return c->nCompras;
}


// Devolve o instante em que o cliente se dirigiu às caixas
int cliente_tEntrada(CLIENTE c) {
    return c->tEntrada;
}


// Imprimir cliente em formato de texto
void cliente_print(CLIENTE c) {
    printf("[%d, %d]", c->nCompras, c->tEntrada);
}
