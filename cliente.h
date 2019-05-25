#ifndef CLIENTE_H
#define CLIENTE_H

/*
  === TIPO CLIENTE ===
  
  O tipo cliente armazena informação referente ao número de items que um cliente pretende comprar e o seu tempo de entrada.
 */


typedef struct {
    int nCompras, tEntrada;
} *CLIENTE;

CLIENTE cliente_novo(int nCompras, int tEntrada);

void cliente_free(CLIENTE c);

int cliente_nCompras(CLIENTE c);

int cliente_tEntrada(CLIENTE c);

void cliente_print(CLIENTE c);


#endif
