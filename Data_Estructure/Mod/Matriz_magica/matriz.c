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

int matriz_soma(int** m, int tam)
{
    int s = 0;

    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            s += m[i][j];

    return s;
}

int somaDiag_p(int** m, int tam)
{
    int s = 0;

    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            if (i==j)
                s += m[i][j];
}

int somaDiag_s(int** m, int tam)
{
    int s = 0;

    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            if (i+j+1 == tam)
                s += m[i][j];
    
}

int eh_simetrica(int** m, int** t, int tam)
{
    int simetrica = 0;

    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++)
        {
            if(m[i][j] == t[i][j])
            {
                simetrica = 1;
            }
            else
            {
                simetrica = 0;
                break;
            }
        }

        if (i == tam-1 && simetrica)
            return 1;
        else if (!simetrica)
            return 0;
    }

}

int soma_linha(int** m, int tam, int l)
{
    int s = 0;

    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            if (i == l)
                s += m[i][j];

    return s;


}

int soma_coluna(int** m, int tam, int c)
{
    int s = 0;

    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            if (j == c)
                s += m[i][j];
}

int eh_matrizMagica(int** m, int tam)
{
    int num_mag = matriz_soma(m, tam) / tam;
    
}

