#include "queue.h"
#include "priority_queue.h"
#include "caixa.h"


/*
  TIPO CAIXA

  O tipo caixa mantém a informação referente a uma das caixas do supermercado.
*/


// Devolve o objeto correspondente à caixa com o número n
CAIXA caixa_nova(int numero, int numQueues) {
    CAIXA c = malloc(sizeof(struct caixa));
    c->fila = priority_queue_new(MAX_CLIENTES, numQueues);
    c->eta = 0;
    c->clientesAtendidos = 0;
    c->produtosProcessados = 0;
    c->esperaTotal = 0;
    c->numero = numero;
    c->velocidade = rand() % 5 + 1;

    return c;
}


// Liberta da memória a caixa e as estruturas associadas
void caixa_free(CAIXA c) {
    priority_queue_free(c->fila);
    free(c);
}


// Atualiza o instante em que a caixa c estará disponível para t
void caixa_atualizaDisponivel(CAIXA c, int t) {
    c->eta = t;
}


// Incrementa o número de clientes atendidos na caixa c
void caixa_incrClientes(CAIXA c) {
    (c->clientesAtendidos)++;
}


// Aumenta o número de produtos processados na caixa c em n
void caixa_aumentaProdutos(CAIXA c, int prods) {
    c->produtosProcessados += prods;
}


// Aumenta o tempo de espera total na caixa c em t
void caixa_aumentaEspera(CAIXA c, int t) {
    c->esperaTotal += t;
}


// Retira um cliente da fila da caixa c
void caixa_removeCliente(CAIXA c) {
    priority_queue_dequeue(c->fila);
}


// Devolve a fila associada à caixa c
PRIORITY_QUEUE caixa_fila(CAIXA c) {
    return c->fila;
}


// Devolve o número da caixa c
int caixa_numero(CAIXA c) {
    return c->numero;
}


// Devolve a estimativa de quando a caixa c estará pronta
int caixa_pronta(CAIXA c) {
    return c->eta;
}


// Devolve o número de clientes já atendidos na caixa c
int caixa_clientesAtendidos(CAIXA c) {
    return c->clientesAtendidos;
}


// Devolve o número de produtos processados na caixa c
int caixa_produtosProcessados(CAIXA c) {
    return c->produtosProcessados;
}


// Devolve o tempo total de espera na caixa c
int caixa_esperaTotal(CAIXA c) {
    return c->esperaTotal;
}


// Devolve o número de produtos processados por unidade de tempo na caixa c
int caixa_velocidade(CAIXA c) {
    return c->velocidade;
}


// Devolve True caso a caixa c esteja vazia (sem clientes) e False caso contrário
BOOL caixa_vazia(CAIXA c) {
    return priority_queue_is_empty(c->fila);
}


// Imprimir uma representação textual da caixa c
void caixa_print(CAIXA c) {
    printf("- Caixa %d (pronta em %d):\n", c->numero, c->eta);
    priority_queue_print(c->fila);
}
