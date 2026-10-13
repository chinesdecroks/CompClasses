#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista.h"

struct no 
{
    int n;
    struct no* prox;
};

No* initList()
{
    return NULL;
}

void inserirIni(No* lista, int valor)
{
    No* novo = (No*)malloc(sizeof(No));

    if (novo == NULL)
        return;

    novo->n = valor;
    novo->prox = lista;
    lista = novo;
}

void inserirFim(No* lista, int valor)
{
    No* novo = (No*)malloc(sizeof(No)), *at = lista;

    if (novo == NULL)
        return;

    while (at->prox == NULL)
        at = at->prox;

    novo->n = valor;
    novo->prox = at->prox;
    at->prox = novo;
}

int consulta(No* lista, int tam)
{
    srand(time(NULL));

    int pos = rand() % tam, cont = 0;
    No* at = lista;

    while (cont != pos)
    {
        at = at->prox;
        cont++;
    }   
    
    return at->n;
}

double inserirIni_t(No* lista, int tam)
{
    srand(time(NULL));
    clock_t inicio, fim;

    inicio = clock();

    for (int i = 0; i < tam; i++)
    {
        int r = rand() % 100;
        inserirIni(lista, r);
    }

    fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

double inserirFim_t(No* lista, int tam)
{
    srand(time(NULL));
    clock_t inicio, fim;

    inicio = clock();

    for (int i = 0; i < tam; i++)
    {
        int r = rand() % 100;
        inserirFim(lista, r);
    }

    fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

double consulta_t(No* lista, int tam)
{
    clock_t inicio, fim;

    inicio = clock();

    for (int i = 0; i < tam; i++)
        consulta(lista, tam);
    

    fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

void liberaLista(No* lista)
{
    
}

