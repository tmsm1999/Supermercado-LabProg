#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define clear() printf("\033[H\033[J")

int main() {
	clear();

	printf("ATENDIMENTO\n");
	printf("\n");

	QUEUE *normal = mk_empty_queue(100); //Atendimento consultas normais.
	QUEUE *urgente = mk_empty_queue(100); //Atendimento na urgência.

	int close = 0;
	int option = 0;

	int n = 1; //número da senha em que vai na fila de prioridade normal.
	int u = 1; //numero da senha em que vai na fila de prioridade urgente.

	while(close == 0) {
		printf("Escolha o seu tipo de senha.\n");
		printf("\n");
		printf("1 - Tirar Senha Normal\n");
		printf("2 - Tirar Senha de Urgência\n");
		printf("\n");
		printf("Opções:\n");
		printf("\n");
		printf("3 - Atender o próximo cliente\n");
		printf("4 - Encerrar o sistema de senhas\n");
		printf("\n");
		printf("Clientes por atender: %d\n", size(normal) + size(urgente));
		//printf("Última senha normal atendida: N%d\n", peek_queue(n));
		printf("\n");
		printf("Opção: ");
		scanf(" %d", &option);

		if(option == 1) {
			enqueue(n, normal);
			clear();
			printf("Senha N%d tirada.\n", n);
			printf("\n");
			n++;
		}
		else if(option == 2) {
			enqueue(u, urgente);
			clear();
			printf("Senha U%d tirada.\n", u);
			printf("\n");
			u++;
		}
		else if(option == 3) {
			if(size(urgente) > 0) {
				clear();
				printf("Cliente com senha U%d atendido.\n", dequeue(urgente));
				printf("\n");
			}
			else if(size(normal) > 0) {
				clear();
				printf("Cliente com a senha N%d atendido\n", dequeue(normal));
				printf("\n");
			}
			else {
				clear();
				printf("Não existem clientes por atender.\n");
				printf("\n");
			}
		}
		else if(option == 4) {
			close = 1;
			clear();
			printf("Sistema de senhas encerrado.\n");
		}
	}

	while(size(urgente) > 0) {
		printf("\n");
		printf("Opções:\n");
		printf("\n");
		printf("3 - Atender o próximo Cliente\n");
		printf("\n");
		printf("Clientes por atender: %d\n", size(normal) + size(urgente));
		printf("\n");
		printf("Opção: ");
		scanf(" %d", &option);

		if(option == 3) {
			clear();
			printf("Cliente com senha U%d atendido.\n", dequeue(urgente));
		}
	}

	while(size(normal) > 0) {
		printf("\n");
		printf("Opções:\n");
		printf("\n");
		printf("3 - Atender o próximo Cliente\n");
		printf("\n");
		printf("Clientes por atender: %d\n", size(normal) + size(urgente));
		printf("\n");
		printf("Opção: ");
		scanf(" %d", &option);

		if(option == 3) {
			clear();
			printf("Cliente com a senha N%d atendeido\n", dequeue(normal));
		}
	}

	clear();
	printf("Não existem mais clientes por atender.\n");
	printf("\n");

	return 0;
}