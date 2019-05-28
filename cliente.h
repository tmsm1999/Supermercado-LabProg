#ifndef CLIENTE_H
#define CLIENTE_H

/*
  === TIPO CLIENTE ===
  
  O tipo cliente armazena informação referente ao número de items que um cliente pretende comprar e o seu tempo de entrada.
 */


typedef struct cliente {
    int nCompras, tEntrada;
} *CLIENTE;

// Devolve um cliente com n items a comprar que foi para as caixas no instante t
CLIENTE cliente_novo(int nCompras, int tEntrada);

// Libertar da memória o cliente
void cliente_free(CLIENTE c);

// Devolve o número de artigos a comprar pelo cliente c
int cliente_nCompras(CLIENTE c);

// Devolve o instante em que o cliente se dirigiu às caixas
int cliente_tEntrada(CLIENTE c);

// Imprimir cliente em formato de texto
void cliente_print(CLIENTE c);


#endif
