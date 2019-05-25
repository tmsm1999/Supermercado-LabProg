#include <stdio.h>
#include <stdlib.h>


// Imprimir uma mensagem de erro e abortar execução
void exit_error(char *msg) { 
   fprintf(stderr,"Erro: %s\n", msg);
   exit(EXIT_FAILURE);
}
