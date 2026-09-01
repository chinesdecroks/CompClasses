#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no
{
    int num;
    struct no* prox;
} No;

struct descritor
{
    int tam;
    No* inicio;
    No* fim;
};

void inicializarLista (Descritor* l)
{
    l->tam = 0;
    l->inicio = NULL;
    l->fim = NULL;
}

Descritor* criar_lista()
{
    Descritor* l = (Descritor*)malloc(sizeof(Descritor));
    inicializarLista(l);

    return l;
}

int adicionarNoInicio (Descritor* l, int valor)
{
    No* novo = (No*) malloc(sizeof(No));
    
    if (novo == NULL)
        return 0;
        
    novo->num = valor;
    novo->prox = l->inicio;

    if (l->inicio == NULL)
    {
        l->fim = novo;
    }

    l->inicio = novo;
    l->tam++;
}

