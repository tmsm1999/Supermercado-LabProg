+------------------------------------------+
|                                          |
|  Simulador de Supermercado               |
|                                          |
|  Tomás Maria Santiago Mamede             |
|  Vasco José Rodrigues Cruz               |
|  FCUP, Laboratório de Programação, 2019. |
|                                          |
+------------------------------------------+



Este trabalho consiste num simulador de atendimento de clientes gerados aleatoriamente por caixas de supermercado. Foi escrito em C.

O programa pode ser compilado com o comando 'make'
(gcc -Wall error.c queue.c priority_queue.c cliente.c caixa.c supermercado.c -o supermercado).


O programa é iniciado com o comando e argumentos './supermercado afluência apetência nCaixas nCaixasPrioridade nCiclos'. Um exemplo de execução é './supermercado 30 30 5 5 10'. É apresentado o estado das caixas ao longo do tempo e, no final, as estatísticas das caixas.
