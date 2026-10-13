#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void)
{
    int** m = cria_matriz(3);
    int** t = cria_matriz(3);

    m = le_matriz(m, 3);
    t = transposta(m, 3);

    int c = soma_coluna(m, 3, 0);
    int l = soma_linha(m, 3, 0);

    printf("A soma da coluna 0 eh %d e da linha 0 eh %d\n", c, l);

    if (eh_simetrica(m, t, 3))
        printf("A matriz eh simetrica\n");
    else 
        printf("A matriz nao eh simetrica\n");

    if (eh_matrizMagica(m, 3))
        printf("Eh quadrado magico\n");
    else
        printf("Nao eh matriz magica\n");

    printf("\n");
    imprime_matriz(m, 3);
    printf("\n");
    imprime_matriz(t, 3);

    libera_matriz(m, 3);
    libera_matriz(t, 3);
}