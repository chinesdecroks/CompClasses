#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int** cria_matriz(int tam)
{
    int** m = malloc(tam * sizeof(int*));

        for (int i = 0; i < tam; i++)
            m[i] = malloc(tam * sizeof(int));

    return m;
}

void libera_matriz(int** m, int tam)
{
    for (int i = 0; i < tam; i++)
        free(m[i]);
    
        free(m);
}

void imprime_matriz(int** m, int tam)
{
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            printf("%d%c", m[i][j], (j == tam-1) ? '\n' : ' ');
}

int** le_matriz(int** m, int tam)
{
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            scanf("%d", &m[i][j]);

    return m;
        
    
}

int** transposta(int **m, int tam)
{
    int** t = cria_matriz(tam);

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            t[i][j] = m[j][i];
        }
    }

    return t;
}