#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

struct Vetor
{
    int *dados;
    int tam;
    int cap;
};

int main(void)
{
    vet* v = cria_vet();
    int a;
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &a);
        inserir(v, a);
    }

    for (int i = 1; i <= 6; i++)
    {
        printf("%d\n", obter(v, i));
    }

    liberar(v);

}

vet* cria_vet()
{
    vet* v = malloc(sizeof(vet));

    v->tam = 0;
    v->cap = 4;
    v->dados = malloc(v->cap*sizeof(int));
}

void liberar(vet* v)
{
    free(v->dados);

    free(v);
}

void inserir(vet* v, int valor)
{
    if (v->tam == v->cap)
    {
        v->cap *= 2;
        v->dados = realloc(v->dados, v->cap*sizeof(int));
    }

    v->dados[v->tam] = valor;
    v->tam++;
}

int obter(vet* v, int index)
{
    return v->dados[index-1];
}