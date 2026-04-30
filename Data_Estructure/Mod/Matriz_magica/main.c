#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void)
{
    int** m = cria_matriz(3);
    int** t = cria_matriz(3);

    m = le_matriz(m, 3);
    t = transposta(m, 3);

    imprime_matriz(m, 3);
    imprime_matriz(t, 3);

    libera_matriz(m, 3);
    libera_matriz(t, 3);
}