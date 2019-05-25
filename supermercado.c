#include "supermercado.h"



// Arranque do programa
int main(int argc, char** argv) {
    if (argc < 5) {
	fprintf(stderr, "Uso: %s afluência apetência nCaixas nCaixasPrioridade nCiclos\n", argv[0]);
	exit(EXIT_FAILURE);
    }
    
    int afluencia = atoi(argv[1]);
    int apetencia = atoi(argv[2]);
    int nCaixas   = atoi(argv[3]);
    int nCaixasP  = atoi(argv[4]);
    int nCiclos   = atoi(argv[5]);
    
    simulador(afluencia, apetencia, nCaixas, nCaixasP, nCiclos);
    
    return 0;
}


// Verifica se o primeiro cliente da caixa caixa_atual (caso exista) já está despachado e atualiza a informação na caixa nesse caso
void trata_primeiro(int passo, CAIXA caixa_atual) {
    // Obtém informação sobre o primeiro cliente na fila
    CLIENTE cliente = priority_queue_peek(caixa_fila(caixa_atual));
    int espera = passo - caixa_pronta(caixa_atual);
    int processados = espera * caixa_velocidade(caixa_atual);

    // Caso o primeiro cliente da fila esteja despachado, atualiza a informação da caixa
    if (processados >= cliente_nCompras(cliente)) {
	caixa_atualizaDisponivel(caixa_atual, passo+1);
	caixa_incrClientes(caixa_atual);
	caixa_aumentaProdutos(caixa_atual, cliente_nCompras(cliente));
	caixa_aumentaEspera(caixa_atual, passo - cliente_tEntrada(cliente));
	caixa_removeCliente(caixa_atual);
	printf("--> Cliente atendido na caixa %d\n", caixa_numero(caixa_atual));

	// Libertar o cliente da memória
	cliente_free(cliente);
    }
}


// Percorre as caixas na lista l, atualizando as respetivas listas de clientes, quando necessário (isto é, processando os clientes que já estão na caixa tempo suficiente para estarem despachados)
void trata_clientes(int passo, CAIXA *lista_caixas, int nCaixas) {
    // Percorre caixas e vai processando uma a uma
    for (int i = 0; i < nCaixas; i++) {
	CAIXA c = lista_caixas[i];
	if (caixa_vazia(c))
	    caixa_atualizaDisponivel(c, passo);
	else
	    trata_primeiro(passo, c);
    }
}


// Devolve True se alguma caixa na lista lista_caixas tiver clientes
BOOL existem_caixas_ocupadas(CAIXA *lista_caixas, int nCaixas) {
    for (int i = 0; i < nCaixas; i++) {
	CAIXA c = lista_caixas[i];
	if (!caixa_vazia(c)) return TRUE;
    }
    return FALSE;
}


// Mostra para o ecrã a representação textual de cada uma das caixas em lista_caixas
void mostra_caixas(CAIXA *lista_caixas, int nCaixas) {
    if (lista_caixas == NULL)
	exit_error("Lista de caixas vazia.");
    
    for (int i = 0; i < nCaixas; i++) {
	caixa_print(lista_caixas[i]);
	printf("\n");
    }
}


// Escreve para o ecrã as estatísticas de cada caixa na lista
void processa_resultados(CAIXA *lista_caixas, int nCaixas) {
    printf("--> ESTATÍSTICAS\n");
    
    for (int i = 0; i < nCaixas; i++) {
	CAIXA c = lista_caixas[i];
	printf("- Caixa %d (%d produto(s) por ciclo): ", caixa_numero(c), caixa_velocidade(c));

	printf("%d cliente(s) atendido(s)", caixa_clientesAtendidos(c));
	if (caixa_clientesAtendidos(c))
	    printf(", média de %.2lf produto(s)/cliente\n", 1.0*caixa_produtosProcessados(c)/caixa_clientesAtendidos(c));
	else
	    printf("\n");
    }
}


// Iniciar o simulador de supermercado
void simulador(int afluencia, int apetencia, int nCaixas, int nCaixasP, int nCiclos) {
    srand(time(NULL));

    //int probabilidade = 0, nProdutos = 0;

    // Criar caixas
    CAIXA lista_caixas[nCaixas+nCaixasP];

    int i;
    for (i = 0; i < nCaixas; i++)
	lista_caixas[i] = caixa_nova(i+1, 1);
    
    for (int j = 0; j < nCaixasP; j++)
	lista_caixas[i+j] = caixa_nova(i+j+1, 2);

    
    // Simulação
    for (i = 1; i <= nCiclos; i++) {
	printf("--> CICLO %d.\n", i);

	trata_clientes(i, lista_caixas, nCaixas+nCaixasP);

	int probabilidade = rand() % 101;
	if (probabilidade <= afluencia) {
	    int nProdutos = 1 + (rand() % (3 * apetencia));

	    CLIENTE c = cliente_novo(nProdutos, i);
	    printf("--> Criado cliente com %d produto(s).\n", nProdutos);

	    // Encontrar a caixa mais vazia
	    int caixaEscolhida = 0;
	    for (int j = 1; j < nCaixas+nCaixasP; j++) {
		int nClientes = priority_queue_size(caixa_fila(lista_caixas[j]));
		if (nClientes < priority_queue_size(caixa_fila(lista_caixas[caixaEscolhida])))
		    caixaEscolhida = j;
	    }

	    // Inserir o cliente numa das filas da caixa. Se o cliente tiver < 200 produtos, vai para a fila urgente
	    // Se a caixa for de fila única, o cliente vai para a única fila
	    int prioridade = (cliente_nCompras(c) < 200) ? 1 : 0;
	    priority_queue_enqueue(caixa_fila(lista_caixas[caixaEscolhida]), prioridade, c);
	}

	mostra_caixas(lista_caixas, nCaixas+nCaixasP);
	printf("\n\n");
    }

    printf("--> As caixas fecharam.\n\n\n");

    // Processar últimos clientes depois de as portas fecharem (começar no próximo instante)
    while (existem_caixas_ocupadas(lista_caixas, nCaixas+nCaixasP)) {
	printf("--> CICLO %d.\n", i);
	trata_clientes(i, lista_caixas, nCaixas+nCaixasP);
	mostra_caixas(lista_caixas, nCaixas+nCaixasP);
	printf("\n\n");
	i++;
    }

    processa_resultados(lista_caixas, nCaixas+nCaixasP);

    // Libertar memória reservadas para as caixas
    for (int i = 0; i < nCaixas+nCaixasP; i++)
	caixa_free(lista_caixas[i]);
}
