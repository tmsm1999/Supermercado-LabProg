#ifndef CAIXA_H
#define CAIXA_H

#include "queue.h"
#include "priority_queue.h"
#include "cliente.h"


/*
  TIPO CAIXA

  O tipo caixa mantém a informação referente a uma das caixas do supermercado.
*/


// Número máximo de clientes por fila
#define MAX_CLIENTES 1000


typedef struct {
    PRIORITY_QUEUE fila;
    int eta, clientesAtendidos, produtosProcessados, esperaTotal, numero, velocidade;
} *CAIXA;


// Devolve o objeto correspondente à caixa com o número n
CAIXA caixa_nova(int numero);

// Atualiza o instante em que a caixa c estará disponível para t
void caixa_atualizaDisponivel(CAIXA c, int t);

// Incrementa o número de clientes atendidos na caixa c
void caixa_incrClientes(CAIXA c);

// Aumenta o número de produtos processados na caixa c em n
void caixa_aumentaProdutos(CAIXA c, int prods);

// Aumenta o tempo de espera total na caixa c em t
void caixa_aumentaEspera(CAIXA c, int t);

// Retira um cliente da fila da caixa c
void caixa_removeCliente(CAIXA c);

// Devolve a fila associada à caixa c
PRIORITY_QUEUE caixa_fila(CAIXA c);

// Devolve o número da caixa c
int caixa_numero(CAIXA c);

// Devolve a estimativa de quando a caixa c estará pronta
int caixa_pronta(CAIXA c);

// Devolve o número de clientes já atendidos na caixa c
int caixa_clientesAtendidos(CAIXA c);

// Devolve o número de produtos processados na caixa c
int caixa_produtosProcessados(CAIXA c);

// Devolve o tempo total de espera na caixa c
int caixa_esperaTotal(CAIXA c);

// Devolve o número de produtos processados por unidade de tempo na caixa c
int caixa_velocidade(CAIXA c);

// Devolve True caso a caixa c esteja vazia (sem clientes) e False caso contrário
BOOL caixa_vazia(CAIXA c);

// Imprimir uma representação textual da caixa c
void caixa_print(CAIXA c);


#endif
