#include "caixa.h"
#include "cliente.h"
#include "queue.h"
#include "priority_queue.h"

#include <time.h>
#include <stdlib.h>



// Verifica se o primeiro cliente da caixa caixa_atual (caso exista) já está despachado e atualiza a informação na caixa nesse caso
void trata_primeiro(int passo, CAIXA caixa_atual);

// Percorre as caixas na lista l, atualizando as respetivas listas de clientes, quando necessário (isto é, processando os clientes que já estão na caixa tempo suficiente para estarem despachados)
void trata_clientes(int passo, CAIXA *lista_caixas, int nCaixas);

// Devolve True se alguma caixa na lista lista_caixas tiver clientes
BOOL existem_caixas_ocupadas(CAIXA *lista_caixas, int nCaixas);

// Mostra para o ecrã a representação textual de cada uma das caixas em lista_caixas
void mostra_caixas(CAIXA *lista_caixas, int nCaixas);

// Escreve para o ecrã as estatísticas de cada caixa na lista
void processa_resultados(CAIXA *lista_caixas, int nCaixas);

// Iniciar o simulador de supermercado
void simulador(int afluencia, int apetencia, int nCaixas, int nCaixasP, int nCiclos);
