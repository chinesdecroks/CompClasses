#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void)
{
    FILE *f = fopen("arq.txt", "w");

    if (!f) return 0;
    
    No** vetor = (No**)malloc(5*sizeof(No*));
    int tam[5] = {1000, 2000, 3000, 4000, 5000};



    fprintf(f, "Tabela de Tempo / Num de Entradas\n");



    free(vetor);
    fclose(f);


}