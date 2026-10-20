#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordena.h"

int* randVector(int tam, int vlrmax)
{
    srand(time(NULL));
    int *v = (int *)malloc(tam*sizeof(int));

    for (int i = 0; i < tam; i++)
        v[i] = rand() % vlrmax;

    return v;
    
}

void merge(int* v, int inicio, int meio, int fim)
{
    int i, j, k;

    //Tamanho dos vetores auxiliares
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    //Criar vetores auxiliares
    int *esquerda = (int *)malloc(n1 * sizeof(int));
    int *direita = (int *)malloc(n2 * sizeof(int));

    //Preencher vetores auxiliares
    for (i = 0; i < n1; i++)
        esquerda[i] = v[inicio + i];
    for (j = 0; j < n2; j++)
        direita[j] = v[meio + 1 + j];

    //Intercalação
    i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2)
    {
        if (esquerda[i] <= direita[j])
            v[k++] = esquerda[i++];
        else
            v[k++] = direita[j++];
    }

    //Adiciona os elementos restantes
    while (i < n1)
        v[k++] = esquerda[i++];
    while (j < n2)
        v[k++] = direita[j++];

    free(esquerda);
    free(direita);

    
}

void mergeSort(int* v, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio)/2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
    }
}