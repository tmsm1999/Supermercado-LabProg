#include <stdio.h>
#include <stdlib.h>


// Função auxiliar (privada)
void exit_error(char *msg) { 
   fprintf(stderr,"Erro: %s\n", msg);
   exit(EXIT_FAILURE);
}
